#ifndef MY_ERRORS_H_
#define MY_ERRORS_H_

#include <stdio.h>

enum MY_ERRORS
{
    SUCCESS                 ,
    ERROR_CALLOC_IS_NULL    ,
    ERROR_FILE_IS_NULL      ,
};

#define PRINT_ERROR(...); fprintf(stderr, __VA_ARGS__);

#endif // MY_ERRORS_H
