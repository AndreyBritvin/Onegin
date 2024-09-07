#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_from_file.h"
#include "sort_strings.h"
#include "swap_strings.h"

int main()
{
    FILE *file_onegin_input = NULL;

    if (int err_num = open_file(&file_onegin_input, "texts/input/onegin_english.txt"))
    {
        printf("Error in opening file: %s", strerror(err_num));
        return EXIT_FAILURE;
    }

    char onegin_text[16][42] = {};

    read_n_lines(onegin_text, 16, 42, file_onegin_input);

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j<42; j++)
        {
            printf("%c", onegin_text[i][j]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
