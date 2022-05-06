#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_FN_SIZE 20

int main(int argc, char* argv[]){
    char mode = 'r';
    for(int i = 1; i < argc; i++){
        char* filename = (char*)malloc(MAX_FN_SIZE * sizeof(char));
        strcpy(filename, argv[i]);
        FILE* filePtr = fopen(filename, &mode);
        if(filePtr == NULL){
            printf("Invalid file!\n");
            return 1;
        }

        //DESCOBRIR O TAMANHO DO FICHEIRO
        fseek(filePtr, 0, SEEK_END);
        long int size = ftell(filePtr); 

        fseek(filePtr, 0, SEEK_SET);
        char* p1 = malloc(size);
        fread(p1, 1, size, filePtr);

        fclose(filePtr);

        printf("%s", p1);
        free(p1);
        free(filename);
    }

    return EXIT_SUCCESS;
}