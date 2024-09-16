#ifndef SWAP_STRINGS_H_
#define SWAP_STRINGS_H_

#include <stdlib.h>
#include <assert.h>
#include "read_from_file.h"

int swap_strings(char **str_to_swap_1, char **str_to_swap_2);
int swap_lines  (Line  *str_to_swap_1,  Line *str_to_swap_2);

int universal_swap(void *to_swap_1, void *to_swap_2, size_t el_size);

#endif // SWAP_STRINGS_H_
