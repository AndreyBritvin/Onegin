#ifndef READ_FROM_FILE_H_
#define READ_FROM_FILE_H_

#include <stdio.h>
#include <errno.h>

int read_n_lines(char input_array[][42], size_t lines, int line_len, FILE *fp);

int open_file(FILE **fp, const char filename[]);

#endif // READ_FROM_FILE_H_
