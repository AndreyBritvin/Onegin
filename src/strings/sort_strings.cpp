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
            void *el_1 = &arr_to_sort[j * el_size];
            void *el_2 = &arr_to_sort[j * el_size + el_size];

            if (cmp_func(el_1, el_2) > 0)
            {
                universal_swap(el_1, el_2, el_size);
            }
        }
    }

    return 0;
}

int my_qsort(void *arr, size_t arr_size, size_t el_size, comparator_t cmp_func)
{
    assert(arr      != NULL);
    assert(arr_size != NULL);

    quick_sort(arr, 0, arr_size - 1, el_size, cmp_func);

    return 0;
}

int quick_sort(void *arr, int left, int right, size_t el_size, comparator_t cmp_func)
{
    assert(arr != NULL);

    if (left < right)
    {
        int partition_num = partition(arr, left, right, el_size, cmp_func);
        quick_sort(arr, partition_num + 1, right, el_size, cmp_func);
        quick_sort(arr, left, partition_num - 1, el_size, cmp_func);
    }

    return 0;
}


int partition(void *arr, int left, int right, size_t el_size, comparator_t cmp_func)
{
    assert(arr != NULL);

    void *pivot = (char *) arr + right * el_size;
    int x = left - 1;

    for (int i = left; i <= right; i++)
    {
        if (cmp_func(((char *)arr + i * el_size), pivot) > 0)
        {
            x++;
            universal_swap((char *) arr + i * el_size, (char *)arr + x * el_size, el_size);
        }
    }
    universal_swap((char *)arr + right * el_size, (char *)arr + (++x) * el_size, el_size);

    return x;
}

int stalin_sort(Line *arr_to_sort, size_t arr_num, size_t el_size, comparator_t cmp_func)
{
    assert(arr_to_sort != NULL);

    // char *arr_to_sort = (char *) void_arr_to_sort;
    Line *last_normal_line = &arr_to_sort[0];
    bool is_gulag = false;
    bool is_first = true;

    for (size_t i = 0; i < arr_num - 1; i++)
    {
        Line *el_2 = &arr_to_sort[i + 1];

        if (cmp_func(last_normal_line, el_2) > 0)
        {
            arr_to_sort[i + 1].line = GULAG_ADDR;
        }
        else
        {
            last_normal_line = el_2;
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

int my_strcmp_begin(const void *vstr_1, const void *vstr_2)
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

int my_strcmp_end(const void *vstr_1, const void *vstr_2)
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


int sorting_unit_test(Text text, comparator_t cmp_func)
{
    DEBUG_ON(printf("Entered Sorting");)
    qsort(   text.text_ptrs_control, text.lines_num, sizeof(Line), cmp_func);
    my_qsort(text.text_ptrs_right,   text.lines_num, sizeof(Line), cmp_func);

    for (size_t i = 0; i < text.lines_num; i++)
    {
        if (text.text_ptrs_control[i].line != text.text_ptrs_right[i].line)
        {
            PRINT_ERROR("Wrong order at i = %lu:\n"
                        "Control:    %s"
                        "My sorting: %s", i, text.text_ptrs_control[i].line, text.text_ptrs_right[i].line);

            return ERROR_UNIT_TEST;
        }
    }

    return SUCCESS;
}
