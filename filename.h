#ifndef FILENAME_H
#define FILENAME_H

#define FILE_NAME_SIZE 256

void clear_input_buffer();

int filename_check(char fileName[]);

char* get_valid_filename(char *text);

#endif
