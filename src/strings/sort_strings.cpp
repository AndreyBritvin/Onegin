#include "sort_strings.h"

int bubble_sort(char text_to_sort[][42])
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16 - i - 1; j++)
        {
            if (strcmp(text_to_sort[j], text_to_sort[j + 1]) > 0)
            {
                swap_strings(text_to_sort[j], text_to_sort[j + 1]);
            }
            printf("%s\n - %s\n = %d\n", text_to_sort[j], text_to_sort[j + 1],
                                         strcmp(text_to_sort[j], text_to_sort[j + 1]));
        }
    }

    return 0;
}
