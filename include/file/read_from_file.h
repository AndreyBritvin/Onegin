#ifndef READ_FROM_FILE_H_
#define READ_FROM_FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "macros.h"
#include "my_errors.h"

struct Line
{
    char                  *line;
    size_t                  len;
};

struct Text
{
    char             *full_text;
    Line       *text_ptrs_right;
    Line        *text_ptrs_left;
    Line     *text_ptrs_control;
    size_t             filesize;
    size_t            lines_num;
    const char        *filename;
};

struct File_info
{
    FILE          *file_ptr;
    char          *filename;
    char              *mode;
};

typedef int (*Parse_file_t)(Text *, FILE *);

size_t read_line(char *input_array);

int read_n_lines(char *input_array, Line *input_ptrs, size_t lines);

int init_file(Text *text, FILE *file_ptr);

int work_file(const char *mode, Text *text, Parse_file_t parse_func);

__off_t get_file_len(const char *filename);

size_t get_lines_num(char *text, size_t text_len);

int create_text(Text *text_to_fill, char *filename);

#endif // READ_FROM_FILE_H_
