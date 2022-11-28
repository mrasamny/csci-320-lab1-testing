#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"
/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 * 
 * fileName is c-string representing the file to read.
 * 
 */
char* readString(char* fileName){
    FILE *fp = NULL;
    char* line_read = NULL;

    line_read = (char*)malloc(sizeof(char)*MAX_LINE_LEN);
    if (line_read != NULL){
        fp = fopen(fileName,"r");
        if (fp != NULL){
            fgets(line_read,MAX_LINE_LEN,fp);
            line_read[strlen(line_read)-1] = '\0';
            fclose(fp);
        } else {
            free(line_read);
            line_read = NULL;
        }
    }
    return line_read;
}

/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 * 
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 * 
 */
char* mysteryExplode(const char* str){
    int len_of_str = strlen(str);
    int size_of_explode_str = len_of_str*(len_of_str+1)/2+1;

    char* explode_str = (char*)malloc(sizeof(char)*size_of_explode_str);
    memset(explode_str,'\0',size_of_explode_str);
    for(int index=0; index < len_of_str && explode_str != NULL; index++){
        strncat(explode_str, str, index+1);
    }
    return explode_str;
}
