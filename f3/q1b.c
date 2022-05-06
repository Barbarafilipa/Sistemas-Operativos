#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SYZE 64

int main(int argc, char* argv[]){
    char* p1 = (char*) malloc(MAX_STR_SYZE * sizeof(char));
    char* p2 = (char*) malloc(MAX_STR_SYZE * sizeof(char));

    if(argc != 3)
        return EXIT_FAILURE;

    if(strlen(argv[1]) > MAX_STR_SYZE || strlen(argv[2]) > MAX_STR_SYZE){
        printf("Exceed the string size!\n");
        return EXIT_FAILURE;
    }

    strcpy(p1, argv[1]);
    strcpy(p2, argv[2]);

    char* pointer = strstr(p2, p1);

    if(pointer != NULL){
        printf("True\n");
    }
    else{
        printf("False\n");
    }


    return EXIT_SUCCESS;
}