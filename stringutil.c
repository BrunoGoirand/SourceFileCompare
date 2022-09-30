#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "stringutil.h"



/**
 *  transform a string to lower case
 * 
 */
char *lowerCase(char *str) {

	int len = strlen(str);
	char *result = (char *) malloc(len+1);

	for(int i = 0; i < len; i++)
		result[i] = (str[i] >= 65 && str[i] <=90) ? str[i] + 32 : str[i];
	
	return(result);
}


/**
 *  transform a string to upper case
 * 
 */
char *upperCase(char *str) {

	int len = strlen(str);
	char *result = (char *) malloc(len+1);

	for(int i = 0; i < len; i++)
		result[i] = (str[i] >= 97 && str[i] <=122) ? str[i] - 32 : str[i];
	
	return(result);
}


/**
 * count the number of occurrence of the character 'c' in the string str
 * 
 */
int charOccurrence(char *str, char c) {

	int found = 0;
	for(int i = 0; i < strlen(str); i++) {
		if(str[i] == c)
			found++;
	}

	return(found);
}

/**
 * trim functions
 * 
 * "spaces" treated by 'isspace()' include:
 * 
 * ' '  (0x20) space (SPC)
 * '\t' (0x09) horizontal tab (TAB)
 * '\n' (0x0a) newline (LF)
 * '\v' (0x0b) vertical tab (VT)
 * '\f' (0x0c) feed (FF)
 * '\r' (0x0d) carriage return (CR)
 * 
 */
char *ltrim(char *str) {

	while(isspace(*str)) str++;
	return(str);
}

char *rtrim(char *str) {

	char *end = str + strlen(str);
	while(isspace(*--end));
	*(end+1) = '\0';
	return(str);
}

char *trim(char *str) {

	return(rtrim(ltrim(str)));
}

/**
 *
 */
