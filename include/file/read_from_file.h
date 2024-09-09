#ifndef READ_FROM_FILE_H_
#define READ_FROM_FILE_H_

#include <stdio.h>
#include <errno.h>

int read_line(char input_array[], FILE *fp);

int read_n_lines(char input_array[], char *input_ptrs[], size_t lines, FILE *fp);

int open_file(FILE **fp, const char filename[]);

int get_file_len(FILE *fp);

#endif // READ_FROM_FILE_H_
