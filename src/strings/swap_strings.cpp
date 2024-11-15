#include "swap_strings.h"

int swap_strings(char **str_to_swap_1, char **str_to_swap_2)
{
    assert(str_to_swap_1 != NULL);
    assert(str_to_swap_2 != NULL);

    char *tmp_c    = *str_to_swap_1;
    *str_to_swap_1 = *str_to_swap_2;
    *str_to_swap_2 = tmp_c;

    return SUCCESS;
}

int swap_lines(Line *str_to_swap_1, Line *str_to_swap_2)
{
    assert(str_to_swap_1 != NULL);
    assert(str_to_swap_2 != NULL);

    Line tmp_c     = *str_to_swap_1;
    *str_to_swap_1 = *str_to_swap_2;
    *str_to_swap_2 = tmp_c;

    return SUCCESS;
}

int universal_swap(void *to_swap_1, void *to_swap_2, size_t el_size)
{
    assert(to_swap_1 != NULL);
    assert(to_swap_2 != NULL);

    char buffer_byte = 0;

    char *byte_to_swap_1 = (char *) to_swap_1;
    char *byte_to_swap_2 = (char *) to_swap_2;

    for (size_t byte_swap = 0; byte_swap < el_size; byte_swap++)
    {
        buffer_byte = *byte_to_swap_1;
                      *byte_to_swap_1++ = *byte_to_swap_2;
                                          *byte_to_swap_2++ = buffer_byte;
    }

    return SUCCESS;
}
