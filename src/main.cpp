#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_from_file.h"
#include "write_to_file.h"

#include "sort_strings.h"
#include "swap_strings.h"

#include "my_errors.h"

int main()
{
    struct Text Onegin = {};

    Onegin.filename = "texts/test/test_symbols.txt";
    //Onegin.filename = "texts/input/onegin_english.txt";

    Onegin.filesize = (size_t) get_file_len(Onegin.filename);
    DEBUG_ON(printf("File size: %lu\n", Onegin.filesize);)

    Onegin.full_text = (char  *) calloc(Onegin.filesize + 1, sizeof(char));

    if (Onegin.full_text == NULL)
    {
        PRINT_ERROR("Error in calloc for <onegin_text> with size: %lu\n", Onegin.filesize);

        return ERROR_CALLOC_IS_NULL;
    }

    if (work_file("r", &Onegin, init_file))
    {
        PRINT_ERROR("Error in reading file <%s>:%s\n", Onegin.filename, strerror(errno));

        return EXIT_FAILURE;
    }

    DEBUG_ON(print_text(Onegin.text_ptrs_right, Onegin.lines_num);)
    DEBUG_ON(
        for (size_t i = 0; i < Onegin.lines_num; i++)
        {
            printf("Len %lu of line %s\n", Onegin.text_ptrs_left[i].len, Onegin.text_ptrs_left[i].line);
        }
            )

    my_qsort(Onegin.text_ptrs_right, Onegin.lines_num, sizeof(Line), my_strcmp_begin);
    DEBUG_ON(printf("Ended begin sort. Now gonna meowdoing left sort--------------------------------------------------\n"));
    my_qsort(Onegin.text_ptrs_left,  Onegin.lines_num, sizeof(Line), my_strcmp_end);

    print_text(Onegin.text_ptrs_right, Onegin.lines_num);
    print_text(Onegin.text_ptrs_left, Onegin.lines_num);

    Onegin.filename = "texts/output/onegin_english.txt";
    if (work_file("w", &Onegin, write_to_file))
    {
        PRINT_ERROR("Error in writing file <%s>:%s\n", Onegin.filename, strerror(errno));

        return EXIT_FAILURE;
    }

    destroy(Onegin.full_text,       Onegin.filesize,  sizeof(Onegin.full_text[0]));
    destroy(Onegin.text_ptrs_left,  Onegin.lines_num, sizeof(Line));
    destroy(Onegin.text_ptrs_right, Onegin.lines_num, sizeof(Line)); // Add Destroy (All to zeros)

    /*int a[] = {9, 5, 2, 3, 1, 5, 6, 3};
    // quick_sort(a, 0, sizeof(a)/sizeof(int) - 1, sizeof(int), cmp_int);
    my_qsort(a, sizeof(a)/sizeof(int), sizeof(int), cmp_int);
    for (int i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
*/
    return EXIT_SUCCESS;
}
