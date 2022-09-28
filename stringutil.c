#include <string.h>
#include <ctype.h>

#include "stringutil.h"


/*

*trim functions

"spaces" treated by 'isspace()' include:

' ' (0x20) space (SPC)
'\t' (0x09) horizontal tab (TAB)
'\n' (0x0a) newline (LF)
'\v' (0x0b) vertical tab (VT)
'\f' (0x0c) feed (FF)
'\r' (0x0d) carriage return (CR)

*/


char *ltrim(char *str)
{
  while(isspace(*str)) str++;
  return(str);
}

char *rtrim(char *str)
{
  char* back = str + strlen(str);
  while(isspace(*--back));
  *(back+1) = '\0';
  return(str);
}

char *trim(char *str)
{
  return(rtrim(ltrim(str))); 
}

/*
*/