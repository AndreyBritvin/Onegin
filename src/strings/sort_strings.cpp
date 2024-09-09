#include "sort_strings.h"

int bubble_sort(char *ptrs_to_sort[], int ptrs_num)
{
    for (int i = 0; i < ptrs_num; i++)
    {
        for (int j = 0; j < ptrs_num - i - 2; j++)
        {
            if (my_strcmp(ptrs_to_sort[j], ptrs_to_sort[j + 1]) > 0)
            {
                swap_strings(&ptrs_to_sort[j], &ptrs_to_sort[j + 1]);
            }
            // printf("\ni = %d j = %d\n%s\n%s\n = %d\n", i, j, text_to_sort[j], text_to_sort[j + 1],
                                        //  my_strcmp(text_to_sort[j], text_to_sort[j + 1]));
        }

        if (0)
        {
            printf("debug_onegin %d:----------------------------------!!!!!!!!!!\n", i);
            for (int k = 0; k < ptrs_num; k++)
            {
                for (int h = 0; h < 3; h++)
                {
                    printf("<%c>(%d)", ptrs_to_sort[k][h], ptrs_to_sort[k][h]);
                }
                printf("\n");
            }
            printf("End debug onegin------------------------------\n");
        }
    }

    return 0;
}

int my_strcmp(char *str_1, char *str_2)
{
    for (int i = 0, j = 0; str_1[i] != '\0' && str_2[j] != '\0'; i++, j++)
    {
        while (!isalnum(str_1[i]))
        {
            i++;
        }
        while (!isalnum(str_2[j]))
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
