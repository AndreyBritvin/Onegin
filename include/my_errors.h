#ifndef MY_ERRORS_H_
#define MY_ERRORS_H_

#include <stdio.h>

enum MY_ERRORS
{
    SUCCESS                 = 0,
    ERROR_CALLOC_IS_NULL    = 1,
    ERROR_FILE_IS_NULL      = 2,
    ERROR_UNIT_TEST         = 3,
};

#define PRINT_ERROR(...); fprintf(stderr, __VA_ARGS__);

#endif // MY_ERRORS_H
