#ifndef SORT_STRINGS_H_
#define SORT_STRINGS_H_

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "swap_strings.h"

int bubble_sort(char *text_to_sort[], int ptrs_num);

int my_strcmp(char *str_1, char *str_2);

#endif // SORT_STRINGS_H_
