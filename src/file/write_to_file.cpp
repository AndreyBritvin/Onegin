#include "write_to_file.h"

int print_text(Line *onegin_ptrs, size_t lines_amount)
{
    printf("Sorted_onegin:----------------------------------\n\n");
    for (size_t i = 0; i < lines_amount; i++)
    {
        printf("%p\n", onegin_ptrs[i].line);
        printf("%s\n", onegin_ptrs[i].line);
    }

    printf("\n");
    printf("End sorted onegin------------------------------\n");

    return 0;
}

int write_to_file(Text *text, FILE *file_ptr)
{
    fprintf(file_ptr, "Sorted right edge MeOwnegin:\n\n");
    for (size_t i = 0; i < text->lines_num; i++)
    {
        fprintf(file_ptr, "%s\n", text->text_ptrs_right[i].line);
    }

    fprintf(file_ptr, "\nSorted right edge MeOwnegin:\n\n");
    for (size_t i = 0; i < text->lines_num; i++)
    {
        fprintf(file_ptr, "%s\n", text->text_ptrs_left[i].line);
    }

    fprintf(file_ptr, "Original Onegin:\n\n");
    char *full_text = text->full_text;
    for (size_t i = 0; i < text->lines_num; i++)
    {
        full_text += fprintf(file_ptr, "%s\n", full_text);
    }

    return 0;
}
