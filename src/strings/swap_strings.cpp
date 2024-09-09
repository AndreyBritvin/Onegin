#include "swap_strings.h"

int swap_strings(char **str_to_swap_1, char **str_to_swap_2)
{
    char *tmp_c   =  *str_to_swap_1;
    *str_to_swap_1 = *str_to_swap_2;
    *str_to_swap_2 = tmp_c;

    return 0;
}
