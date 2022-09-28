#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* returns

1 - issue with filenames
2 -  memory allocation issue

*/

int main(int argc, char **argv) {

  FILE *fp1, *fp2;
  char *file1, *file2;
  int length1, length2;

  // command line arguments management
  fprintf(stderr, "# args: %d\n", argc);
  for(int i=1; i<argc; i++)
    fprintf(stderr, "arg[%d]: %s(%lu)\n", i, argv[i], strlen(argv[i]));

  if(argc != 4)
    fprintf(stdout, "Usage: sfc dir1 dir2 file\n");

  // build filenames
  length1 = argv[1])+strlen(argv[3])+2;
  if(length1 > FILENAME_MAX) {
    fprintf(stderr, "filename1 is too long\n");
    return(1);
  }

  file1 = (char *) malloc(strlen(length1);
  if(!file1) {
    fprintf(stderr, "unable to allocate file 1\n");
    return(2);
  }

  strcpy(file1, argv[1]);
  strcat(file1, "//");
  strcat(file1, argv[3]);

  fprintf(stderr, "file 1: %s\n", file1);

  length2 = argv[2])+strlen(argv[3])+2;
  if(length2 > FILENAME_MAX) {
    fprintf(stderr, "filename2 is too long\n");
    return(1);
  }

  file2 = (char *) malloc(length2);
  if(!file2) {
    fprintf(stderr, "unable to allocate file 2\n");
    return(2);
  }

  strcpy(file2, argv[2]);
  strcat(file2, "//");
  strcat(file2, argv[3]);

  fprintf(stderr, "file 2: %s\n", file2);

  // open files
  fp1 = fopen(file1, "r");
  if(!fp1) {
    fprintf(stderr, "unable to open file 1\n");
    return(3);
  }



  fp2 = fopen(file2, "r");
  if(!fp2) {
    fprintf(stderr, "unable to open file 2\n");
    return(3);
  }




  fclose(fp1);
  fclose(fp2);

  free(file1);
  free(file2);

  return(0);
}
