#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_from_file.h"
#include "sort_strings.h"
#include "swap_strings.h"

int main()
{
    FILE *file_onegin_input = NULL;

    if (int err_num = open_file(&file_onegin_input, "texts/test/test_symbols.txt"))
    {
        printf("Error in opening file: %s", strerror(err_num));
        return EXIT_FAILURE;
    }

    printf("File size: %d\n", get_file_len(file_onegin_input));

    char *onegin_text = (char *) calloc(get_file_len(file_onegin_input), sizeof(char));
    // fread(onegin_text_full, sizeof(char), get_file_len(file_onegin_input), file_onegin_input);

    // char onegin_text[16][42] = {};
    char *onegin_ptrs[16] = {};

    read_n_lines(onegin_text, onegin_ptrs, 10, file_onegin_input);

    bubble_sort(onegin_ptrs, 10);

    printf("Sorted_onegin:----------------------------------\n");
    for (int i = 0; i < 10; i++)
    {
        // for (int j = 0; j < 42; j++)
        // {
        //     printf("<%c>(%d) ", onegin_text[i*10+j], onegin_text[i*10+j]);
        // }
        // printf("\n");
        printf("%s\n", onegin_ptrs[i]);
    }
    printf("End sorted onegin------------------------------\n");

    free(onegin_text);

    return EXIT_SUCCESS;
}
