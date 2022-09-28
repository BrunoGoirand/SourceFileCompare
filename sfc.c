# include <stdio.h>

int main(int argc, char **argv) {

  FILE *fp;

  // command line arguments management
  fprintf(stderr, "# args: %d\n", argc);
  for(int i=1; i<argc; i++)
    fprintf(stderr, "arg[%d]: %s\n", i, argv[i]);

  if(argc != 4)
    fprintf(stdout, "Usage: sfc dir1 dir2 file\n");





  fp = fopen(argv[1], "r");



  fclose(fp);

}

