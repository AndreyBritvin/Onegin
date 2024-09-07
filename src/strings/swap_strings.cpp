#include "swap_strings.h"

int swap_strings(char *str_to_swap_1, char *str_to_swap_2)
{
    for (int i = 0; i < 42; i++)
    {
        char tmp_c = str_to_swap_1[i];
        str_to_swap_1[i] = str_to_swap_2[i];
        str_to_swap_2[i] = tmp_c;
    }

    return 0;
}
