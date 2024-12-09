#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filename.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int filename_check(char fileName[]) {
    int len = strlen(fileName);
    if ((len > 4) && (strcmp(fileName + len - 4, ".txt") == 0)) {
        return 1;
    }
    return 0; 
}

char* get_valid_filename(char *text) {
    int valid = 0;

    char *fileName = malloc(FILE_NAME_SIZE * sizeof(char));

    if (fileName == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    while (!valid) {
        printf("%s", text);
        scanf("%255s", fileName);
        if (getchar() != '\n') {
            printf("Invalid input. Try again.\n");
            clear_input_buffer();
            continue;
        }
        valid = filename_check(fileName);
        if (!valid) {
            printf("Invalid file name '%s'. Please use a .txt file.\n", fileName);
        }
    }

    if (strlen(fileName) < FILE_NAME_SIZE) {
        char *resized = realloc(fileName, (strlen(fileName) + 1) * sizeof(char));     
        if (resized == NULL) {
            printf("Memory allocation failed\n");
            free(fileName);
            return NULL;
        }
        fileName = resized;
    }

    return fileName;
}
