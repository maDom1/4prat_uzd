#ifndef FILENAME_H
#define FILENAME_H

#define FILE_NAME_SIZE 256

// Clears the input buffer
void clearInputBuffer();

// Validates if a file name ends with .txt
int filename_check(char fileName[]);

// Gets a valid file name with .txt extension
char* get_valid_filename(char *text);

#endif
