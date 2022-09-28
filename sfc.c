#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "stringutil.h"

/* returns

1 - issue with filenames
2 -  memory allocation issue

*/
#define VAL_ARGS  1 // validate arguments
#define BUILD_FN  2 // build filename
#define OPEN__FN  3 // open file
#define GET_NXLN -1 // no more line to treat
#define RMV_CMTS  5 // remove comments
#define RMV__SPC  6 // remove spaces


/*
** all functions return 0 when successful
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

  *fn = (char *) malloc(length);
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
int getNextLine(FILE *fp, char **line, size_t *len) {

  ssize_t read;
  char *newline;

  if((read = getline(line, len, fp)) == -1) 
    return(GET_NXLN);

  // trim line
  newline = trim(*line);

  // remove comments

  // remove spaces


  // is the line empty
  if(!strlen(newline)) return(getNextLine(fp, line, len));
  //else fprintf(stderr, "<%s>\n", newline);

  return(read);
}

/*
**
*/
int main(int argc, char **argv) {

  FILE *fp1, *fp2;  // file pointer
  char *fn1, *fn2;  // file name
  int length1, length2;

  if(validateArguments(argc, argv)) return(VAL_ARGS);

  if(buildFilename(argc, argv, 1, &fn1)) return(BUILD_FN);
  if(buildFilename(argc, argv, 2, &fn2)) return(BUILD_FN);

  if(openFile(fn1, &fp1)) return(OPEN__FN);
  if(openFile(fn2, &fp2)) return(OPEN__FN);


  char *line1 = NULL, *line2 = NULL;
  size_t len1 = 0, len2 = 0;
  int ln1 = 0, ln2 = 0; // line number
  int loop1 = 1, loop2= 1;

  while(loop1 && loop2) {    
    
    ln1++; ln2++;
    if(getNextLine(fp1, &line1, &len1) == -1) loop1=0;
    if(getNextLine(fp2, &line2, &len2) == -1) loop2=0;
    
    if(strlen(line1)) fprintf(stderr, "[%d][%s]\t", ln1, line1);
    if(strlen(line2)) fprintf(stderr, "[%d][%s]", ln2, line2);
    fprintf(stderr, "\n");
  }

  fprintf(stderr, "[%d|%d]\n", loop1, loop2);

  /*
  getNextLine(fp1, &line1, &len1);

  if(getNextLine(fp1, &line1, &len1)) 
    fprintf(stdout, "\n[%02zu] %s", len1, line1);
  else {
    fprintf(stdout, "\nE:[%02zu] %s", len1, line1);
  }
  */

  fprintf(stderr, "------------------\n");

  fclose(fp1);
  fclose(fp2);

  if(line1) free(line1);
  if(line2) free(line2);

  free(fn1);
  free(fn2);

  return(0);
}
