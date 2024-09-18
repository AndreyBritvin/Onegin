#ifndef SORT_STRINGS_H_
#define SORT_STRINGS_H_

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "read_from_file.h"

#include "swap_strings.h"
#include "macros.h"
#include "my_errors.h"

typedef int (*comparator_t)(const void *, const void *);

int bubble_sort(void *text_to_sort, size_t ptrs_num, size_t el_size, comparator_t cmp_func);

char *skip_non_alpha_right(char *str_ptr);
char *skip_non_alpha_left (char *str_ptr, char *min_ptr);

int my_strcmp_begin(const void *str_1, const void *str_2);
int my_strcmp_end  (const void *str_1, const void *str_2);

int my_qsort  (void *arr_to_sort,     size_t arr_size, size_t el_size, comparator_t cmp_func);
int quick_sort(void *arr_to_sort, int left, int right, size_t el_size, comparator_t cmp_func);
int partition (void *arr_to_sort, int left, int right, size_t el_size, comparator_t cmp_func);

int stalin_sort(void *void_arr_to_sort, size_t arr_num, size_t el_size, comparator_t cmp_func);

int sorting_unit_test(Text text, comparator_t cmp_func);

#endif // SORT_STRINGS_H_xo
