#ifndef SORT_STRINGS_H_
#define SORT_STRINGS_H_

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "read_from_file.h"

#include "swap_strings.h"
#include "macros.h"

typedef int (*comparator_t)(void *, void *);

int bubble_sort(Line *text_to_sort, size_t ptrs_num, size_t el_size, comparator_t cmp_func);

char *skip_non_alpha_right(char *str_ptr);
char *skip_non_alpha_left (char *str_ptr, char *min_ptr);

int my_strcmp_begin(void *str_1, void *str_2);
int my_strcmp_end(void *str_1, void *str_2);

#endif // SORT_STRINGS_H_xo
