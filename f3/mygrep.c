#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_FN_SIZE 20

int main(int argc, char* argv[]){
    FILE* filePtr = fopen(argv[2], "r");
    if(filePtr == NULL){
        printf("Invalid file! \n");
        return 1;
    }

    char* line = NULL;
    size_t len = 0;
    int numline = 1;
    int size = strlen(argv[1]);

    while( getline(&line, &len, filePtr) != -1){
        char* start = line;
        char* end = line + len;

        char* offset = line;
        while(offset < end){
            offset = strstr(offset, argv[1]);

            if(offset == NULL) break;
            if(offset + size >= end) break;

            printf("[%d:%ld]\n", numline, offset-start+1);
            offset += size;
        }
        numline++;
    }

    return 0;
}    