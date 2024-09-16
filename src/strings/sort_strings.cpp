#include "sort_strings.h"

int bubble_sort(void *void_arr_to_sort, size_t arr_num, size_t el_size, comparator_t cmp_func) // compareFunc_t func1
{
    assert(void_arr_to_sort != NULL);
    assert(cmp_func         != NULL);

    char *arr_to_sort = (char *) void_arr_to_sort;

    for (size_t i = 0; i < arr_num; i++)
    {
        for (size_t j = 0; j < arr_num - i - 1; j++)
        {
            void *el_1 = &arr_to_sort[j*el_size];
            void *el_2 = &arr_to_sort[j*el_size + el_size];

            if (cmp_func(el_1, el_2) > 0)
            {
                universal_swap(el_1, el_2, el_size);
            }
            // DEBUG_ON(printf("\ni = %lu j = %lu\n%s\n%s\n = %d\n", i, j, arr_to_sort[j], arr_to_sort[j + 1],
                                    // cmp_func(arr_to_sort[j].line, arr_to_sort[j + 1].line));)
        }
    }

    return 0;
}

char *skip_non_alpha_right(char *str_ptr)
{
    assert(str_ptr != NULL);

    while (!isalnum(*str_ptr) && *str_ptr != '\0')
    {
        str_ptr++;
    }

    return str_ptr;
}


char *skip_non_alpha_left(char *str_ptr, char *min_ptr)
{
    assert(str_ptr != NULL);
    assert(min_ptr != NULL);

    // DEBUG_ON(printf("Str_ptr = %p\nMin_ptr = %p\n", str_ptr, min_ptr);)
    while (!isalnum(*str_ptr) && str_ptr - min_ptr > 0)
    {
        str_ptr--;
    }

    return str_ptr;
}

int my_strcmp_begin(void *vstr_1, void *vstr_2)
{
    assert(vstr_1 != NULL);
    assert(vstr_2 != NULL);

    Line *line_1 = (Line *) vstr_1;
    Line *line_2 = (Line *) vstr_2;

    char *str_1 = line_1->line;
    char *str_2 = line_2->line;

    DEBUG_ON(printf("Strings to compare:\n%p: %s\n%p: %s\n\n",
                                        line_1->line,
                                        line_1->line,
                                        line_2->line,
                                        line_2->line);
            )

    for (; *str_1 != '\0' && *str_2 != '\0'; str_1++, str_2++)
    {
        str_1 = skip_non_alpha_right(str_1);
        str_2 = skip_non_alpha_right(str_2);

        if (tolower(*str_1) != tolower(*str_2))
        {
            // DEBUG_ON(
            // printf("ch1 =<%c>   %d, ch2 =<%c>   %d,\n"
                //    "tolower1 = %d, tolower2 = %d\n", *str_1, *str_1, *str_2, *str_2, tolower(*str_1), tolower(*str_2));
            // )

            return tolower(*str_1) - tolower(*str_2);
        }
    }

    return 0;
}

int my_strcmp_end(void *vstr_1, void *vstr_2)
{
    assert(vstr_1 != NULL);
    assert(vstr_2 != NULL);

    Line *line_1 = (Line *) vstr_1;
    Line *line_2 = (Line *) vstr_2;

    size_t len_1 = line_1->len;
    size_t len_2 = line_2->len;

    char *str_1 = line_1->line + len_1;
    char *str_2 = line_2->line + len_2;

    DEBUG_ON(printf("Strings to compare:\n%p: %s\n%p: %s\n\n",
                                        line_1->line,
                                        line_1->line,
                                        line_2->line,
                                        line_2->line);
            )

    for (; str_1 - line_1->line > 0 && str_2 - line_2->line > 0; str_1--, str_2--)
    {
        str_1 = skip_non_alpha_left(str_1, line_1->line);
        str_2 = skip_non_alpha_left(str_2, line_2->line);

        if (tolower(*str_1) != tolower(*str_2))
        {
            // DEBUG_ON(
            // printf("ch1 =<%c>   %d, ch2 =<%c>   %d,\n"
            //        "tolower1 = %d, tolower2 = %d\n", *str_1, *str_1, *str_2, *str_2, tolower(*str_1), tolower(*str_2));
            // )

            return tolower(*str_1) - tolower(*str_2);
        }
    }

    return 0;
}
