#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <NeatString/NeatString.h>

/**
 * 
 * 
 */


/*
** command line arguments management
*/
int validateArguments(int argc, char **argv) {

	fprintf(stderr, "# args: %d\n", argc);
	for(int i=1; i<argc; i++)
		fprintf(stderr, "arg[%d]: %s(%lu)\n", i, argv[i], strlen(argv[i]));

	if(argc != 4) {
		fprintf(stdout, "Usage: sfc dir1 dir2 file\n");
		return(1);
	}

	return(0);
}

/*
** build full filename from directory and filename
*/
int buildFilename(int argc, char **argv, int arg, char **fn) {

	int length;
	//char *so; // string operation
	// 
	length = strlen(argv[arg])+strlen(argv[3])+2;
	if(length > FILENAME_MAX) {
		fprintf(stderr, "filename is too long\n");
		return(1);
	}

	*fn = (char *) malloc(length + 1);
	if(!*fn) {
		fprintf(stderr, "unable to allocate filename length\n");
		return(1);
	}

	if(strcpy(*fn, argv[arg]) != *fn) return(1);
	if(strcat(*fn, "/") != *fn) return(1);
	if(strcat(*fn, argv[3]) != *fn) return(1);

	fprintf(stderr, "file name [%d]: %s\n", arg, *fn);
	return(0);
}

/*
** open file
*/
int openFile(char *fn, FILE **fp) {

	// open files
	*fp = fopen(fn, "r");
	if(!*fp) {
		fprintf(stderr, "unable to open file [%s]\n", fn);
		return(1);
	}

	return(0);
}


/*
**
*/
int getNextLine(FILE *fp, char **result, int *ln) {

	ssize_t read;
	char *ptr0, *ptr1, *ptr2;
	int valid = 0;
	size_t inputLen = 160;

	ptr0 = (char *) malloc(inputLen);

	while(valid == 0) {		
		
		(*ln)++;
		//fprintf(stderr, "((%d))\n", *ln);
		if((read = getline(&ptr0, &inputLen, fp)) == -1) {
			free(ptr0);
			return(read);
		}

		if(!strlen(ptr0))
			continue;

		//fprintf(stderr, "read{%lu}{%s}\n", strlen(ptr0), ptr0);

		// inside trim
		ptr1 = itrim(ptr0);
		//fprintf(stderr, "trim[%d][%d][%lu][%s]\n", valid, *ln, strlen(ptr1), ptr1);
		if(strlen(ptr1) == 0) {
			//fprintf(stderr, "T-THERE\n");
			free(ptr1);
			continue;
		}

		//fprintf(stderr, "--HERE\n");

		// remove cpp comments
		ptr2 = removeCPPComments(ptr1);
		//fprintf(stderr, "cmts[%d][%d][%lu][%s]\n", valid, *ln, strlen(ptr2), ptr2);
		if(strlen(ptr2) == 0) {
			//fprintf(stderr, "C-THERE\n");
			free(ptr1);
			free(ptr2);
			continue;
		}

		valid = 1;
	}

	*result = (char *) malloc(strlen(ptr2) + 1);
	strcpy(*result, ptr2);

	free(ptr2);
	free(ptr1);
	free(ptr0);

	return(read);
}

/*
**
*/
int main(int argc, char **argv) {

	FILE *fp1, *fp2;  // file pointer
	char *fn1, *fn2;  // file name
	int length1, length2;

	if(validateArguments(argc, argv)) return(EXIT_FAILURE);

	if(buildFilename(argc, argv, 1, &fn1)) return(EXIT_FAILURE);
	if(buildFilename(argc, argv, 2, &fn2)) return(EXIT_FAILURE);

	if(openFile(fn1, &fp1)) return(EXIT_FAILURE);
	if(openFile(fn2, &fp2)) return(EXIT_FAILURE);


	char *line1 = NULL, *line2 = NULL;
	//size_t len1 = 0, len2 = 0;
	int ln1 = 0, ln2 = 0; // line number
	int loop1 = 1, loop2= 1;

	fprintf(stderr, "\n--STARTING--\n");

	while(loop1 && loop2) {    
		
		if(getNextLine(fp1, &line1, &ln1) == -1) loop1=0;
		if(getNextLine(fp2, &line2, &ln2) == -1) loop2=0;
		
		//if(strlen(line1)) fprintf(stderr, "[%d][%s]\n", ln1, line1);
		//if(strlen(line2)) fprintf(stderr, "[%d][%s]\n", ln2, line2);
		//fprintf(stderr, "\n");

		if(strcmp(line1, line2)) {
			break;
		}

		if(loop1) 
			free(line1);
		if(loop2)
			free(line2);
	}

	if(loop1 && loop2) {
		fprintf(stderr, "\n--FOUND DIFFERENCE--\n");
		fprintf(stdout, "[%d][%s]\n", ln1, line1);
		fprintf(stdout, "[%d][%s]\n", ln2, line2);
	}
	else if(!(loop1 ^ loop2)) {
		fprintf(stderr, "\n--FILES IDENTICALS--\n");
	}
	else {
		fprintf(stderr, "\n--EOF REACHED--\n");
		//fprintf(stderr, "[[%d|%d]]\n\n", loop1, loop2);
		if(!loop1)
			fprintf(stdout, "[%s]\n", fn1);
		else
			fprintf(stdout, "[%s]\n", fn2);
	}

	fprintf(stderr, "\n");

	fclose(fp1);
	fclose(fp2);

	if(loop1) 
		free(line1);
	if(loop2) 
		free(line2);

	free(fn1);
	free(fn2);

	return(EXIT_SUCCESS);
}
