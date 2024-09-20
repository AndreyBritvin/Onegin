#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_from_file.h"
#include "write_to_file.h"

#include "sort_strings.h"
#include "swap_strings.h"

#include "my_errors.h"

int main(const int argc, const char **argv)
{
    if (argc != 3)
    {
        PRINT_ERROR("You should call this func %s <filename_input> <filename_output>\n", argv[0]);

        return EXIT_SUCCESS;
    }

    struct Text Onegin = {};

    create_text(&Onegin, argv[1]);

    DEBUG_ON(print_text(Onegin.text_ptrs_right, Onegin.lines_num);)
    DEBUG_ON(
        for (size_t i = 0; i < Onegin.lines_num; i++)
        {
            printf("Len %lu of line %s\n", Onegin.text_ptrs_left[i].len, Onegin.text_ptrs_left[i].line);
        }
            )

    #ifndef STALIN
    my_qsort(Onegin.text_ptrs_right, Onegin.lines_num, sizeof(Onegin.text_ptrs_right[0]), my_strcmp_begin);
    DEBUG_ON(printf("Ended begin sort. Now gonna meowdoing left sort--------------------------------------------------\n"));
    my_qsort(Onegin.text_ptrs_left,  Onegin.lines_num, sizeof(Onegin.text_ptrs_left[0]) , my_strcmp_end);
    DEBUG_ON(printf("We are in quick sort\n");)

    print_text(Onegin.text_ptrs_right, Onegin.lines_num);
    print_text(Onegin.text_ptrs_left, Onegin.lines_num);
    #endif
    // sorting_unit_test(Onegin, my_strcmp_begin);
    #ifdef STALIN
    stalin_sort(Onegin.text_ptrs_right, Onegin.lines_num, sizeof(Line), my_strcmp_begin);
    DEBUG_ON(printf("Ended begin sort. Now gonna meowdoing left sort--------------------------------------------------\n"));
    stalin_sort(Onegin.text_ptrs_left,  Onegin.lines_num, sizeof(Line), my_strcmp_end);
    DEBUG_ON(printf("We are in stalin\n");)
    DEBUG_ON(
        printf("Printed right_edge sorted:\n");
        for (size_t i = 0; i < Onegin.lines_num; i++)
        {
            printf("Len %lu of line %p\n", Onegin.text_ptrs_right[i].len, Onegin.text_ptrs_right[i].line);
        }
            )
    DEBUG_ON(
        printf("\n\nPrinted left edged stalin\n");
        for (size_t i = 0; i < Onegin.lines_num; i++)
        {
            printf("Len %lu of line %p\n", Onegin.text_ptrs_left[i].len, Onegin.text_ptrs_left[i].line);
        }
            )
    #endif

    Onegin.filename = argv[2]; // TODO? Move to another func???
    if (work_file("w", &Onegin, write_to_file))
    {
        PRINT_ERROR("Error in writing file <%s>:%s\n", Onegin.filename, strerror(errno));

        return EXIT_FAILURE;
    }

    destroy_text(&Onegin);

    return EXIT_SUCCESS;
}
