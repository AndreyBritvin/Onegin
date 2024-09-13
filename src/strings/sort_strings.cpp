#include "sort_strings.h"

int bubble_sort(Line *ptrs_to_sort, size_t ptrs_num, comparator_t cmp_func) // compareFunc_t func1
{
    assert(ptrs_to_sort != NULL);
    assert(cmp_func     != NULL);

    for (size_t i = 0; i < ptrs_num; i++)
    {
        for (size_t j = 0; j < ptrs_num - i - 1; j++)
        {
            if (cmp_func(ptrs_to_sort[j].line, ptrs_to_sort[j + 1].line) > 0)
            {
                swap_strings(&(ptrs_to_sort[j].line), &(ptrs_to_sort[j + 1].line));
            }
            DEBUG_ON(printf("\ni = %lu j = %lu\n%s\n%s\n = %d\n", i, j, ptrs_to_sort[j], ptrs_to_sort[j + 1],
                                    cmp_func(ptrs_to_sort[j].line, ptrs_to_sort[j + 1].line));)
        }

        DEBUG_ON(
            printf("debug_onegin %lu:---------------------------------!!!!!!!!!!\n", i);
            for (size_t k = 0; k < ptrs_num; k++)
            {
                for (size_t h = 0; h < 3; h++)
                {
                    printf("<%c>(%d)", ptrs_to_sort[k].line[h], ptrs_to_sort[k].line[h]);
                }
                printf("\n");
            }
            printf("End debug onegin-----------------------------\n");
        )
    }

    return 0;
}

int my_strcmp_begin(void *vstr_1, void *vstr_2)
{
    assert(vstr_1 != NULL);
    assert(vstr_2 != NULL);

    char *str_1 = (char *) vstr_1;
    char *str_2 = (char *) vstr_2;

    for (int i = 0, j = 0; str_1[i] != '\0' && str_2[j] != '\0'; i++, j++)
    {
        while (!isalnum(str_1[i]) && str_1[i] != '\0')
        {
            i++;
        }
        while (!isalnum(str_2[j]) && str_2[j] != '\0')
        {
            j++;
        }

        if (tolower(str_1[i]) != tolower(str_2[j]))
        {
            DEBUG_ON(
            printf("ch1 =<%c>   %d, ch2 =<%c>   %d,\n"
                   "tolower1 = %d, tolower2 = %d\n", str_1[i], str_1[i], str_2[j], str_2[j], tolower(str_1[i]), tolower(str_2[j]));
            )

            return tolower(str_1[i]) - tolower(str_2[j]);
        }
    }

    return 0;
}

int my_strcmp_end(char *str_1, char *str_2) // TODO: redo this func
{
    for (int i = 0, j = 0; str_1[i] != '\0' && str_2[j] != '\0'; i++, j++)
    {
        while (!isalnum(str_1[i]) && str_1[i] != '\0')
        {
            i++;
        }
        while (!isalnum(str_2[j]) && str_2[j] != '\0')
        {
            j++;
        }

        if (tolower(str_1[i]) != tolower(str_2[j]))
        {
            // printf("ch1 =      %d, ch2 =      %d,\n"
            //        "tolower1 = %d, tolower2 = %d\n", str_1[i], str_2[j], tolower(str_1[i]), tolower(str_2[j]));
            return tolower(str_1[i]) - tolower(str_2[j]);
        }
    }

    return 0;
}
