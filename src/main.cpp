#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_from_file.h"
#include "sort_strings.h"
#include "swap_strings.h"

int main()
{
    const int lines_amount = 1000;
    // const char filename[] = "texts/test/test_symbols.txt";
    const char filename[] = "texts/input/onegin_english.txt";

    FILE *file_onegin_input = NULL;

    if (int err_num = open_file(&file_onegin_input, filename))
    {
        printf("Error in opening file: %s", strerror(err_num));
        return EXIT_FAILURE;
    }

    printf("File size: %ld\n", get_file_len(file_onegin_input));

    char *onegin_text = (char *) calloc((size_t) get_file_len(file_onegin_input), sizeof(char));
    char *onegin_ptrs[lines_amount] = {};

    read_n_lines(onegin_text, onegin_ptrs, lines_amount, file_onegin_input);
    printf("First chars:<%c>(%d) <%c>(%d) <%c>(%d)\n", onegin_text[0], onegin_text[0],
                       onegin_text[1], onegin_text[1], onegin_text[2], onegin_text[2]);

    bubble_sort(onegin_ptrs, lines_amount);

    printf("Sorted_onegin:----------------------------------\n\n");
    for (int i = 0; i < lines_amount; i++)
    {
        printf("%s\n", onegin_ptrs[i]);
    }
    printf("\nEnd sorted onegin------------------------------\n");

    free(onegin_text);

    return EXIT_SUCCESS;
}
