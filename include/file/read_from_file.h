#ifndef READ_FROM_FILE_H_
#define READ_FROM_FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

#include "macros.h"

struct Line
{
    char              *line;
    size_t              len;
};

struct Text
{
    char         *full_text;
    Line         *text_ptrs;
    size_t         filesize;
    size_t        lines_num;
    const char    *filename;
    FILE          *file_ptr;
};

typedef int (*Parse_file)(Text *);

size_t read_line(char *input_array);

int read_n_lines(char *input_array, Line *input_ptrs, size_t lines);

int init_file(Text *text);

int work_file(const char *mode, Text *text, Parse_file parse_func);

__off_t get_file_len(const char *filename);

size_t get_lines_num(char *text, size_t text_len);

#endif // READ_FROM_FILE_H_
