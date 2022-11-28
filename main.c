#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"

char* expected_readString(char* fileName){
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

char* expected_mysteryExplode(const char* str){
    int len_of_str = strlen(str);
    int size_of_explode_str = len_of_str*(len_of_str+1)/2+1;

    char* explode_str = (char*)malloc(sizeof(char)*size_of_explode_str);
    memset(explode_str,'\0',size_of_explode_str);
    for(int index=0; index < len_of_str && explode_str != NULL; index++){
        strncat(explode_str, str, index+1);
    }
    return explode_str;
}

/**********************************************
 *     DO NOT MODIFY THIS FILE IN ANY WAY!    *
 **********************************************/

int main(int argc, char** argv)
{
    char* actual_explodedString = NULL;
    char* expected_explodedString = NULL;
    char* expected = NULL;
    char* actual = NULL;
    int result = SUCCESS;
    int grade = 0;
    
    char* filename[4] = {"test1.txt", "test2.txt", "test3.txt", "test4.txt"};
    
    
    for(int index = 0; index < 4; index++){
        actual = readString(filename[index]);
        expected = expected_readString(filename[index]);
        if (strcmp(actual,expected) == 0){
            grade += 10;
        } else {
            printf("Read: Assertion Error!\nExpected: %s(%ld)\nActual: %s(%ld)",expected,strlen(expected),actual,strlen(actual));
        }
        if (expected != NULL){
            actual_explodedString = mysteryExplode(expected);
            expected_explodedString = expected_mysteryExplode(expected);
        }
        if (strcmp(actual_explodedString,expected_explodedString) == 0){
            grade += 15;
        } else {
            printf("Explode: Assertion Error!\nExpected: %s(%ld)\nActual: %s(%ld)",expected_explodedString,strlen(expected_explodedString),actual_explodedString,strlen(actual_explodedString));
        }
        free(actual);
        free(expected);
        free(actual_explodedString);
        free(expected_explodedString);
    }
    printf("\n\nGrade is %d\n\n",grade);
    return SUCCESS;
}
