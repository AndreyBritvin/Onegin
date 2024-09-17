#ifndef WRITE_TO_FILE_H_
#define WRITE_TO_FILE_H_

#include <stdio.h>
#include "read_from_file.h"
#include "my_errors.h"

int print_text(Line *onegin_ptrs, size_t lines_amount);

int write_to_file(Text *text, FILE *file_ptr);

#endif // WRITE_TO_FILE_H_
