#include "write_to_file.h"

int print_text(Line *onegin_ptrs, size_t lines_amount)
{
    printf("Sorted_onegin:----------------------------------\n\n");
    for (size_t i = 0; i < lines_amount; i++)
    {
        printf("%s\n", onegin_ptrs[i].line);
    }
    printf("\nEnd sorted onegin------------------------------\n");

    return 0;
}

int write_to_file(Text *text)
{
    for (size_t i = 0; i < text->lines_num; i++)
    {
        fprintf(text->file_ptr, "%s\n", text->text_ptrs[i].line);
    }

    return 0;
}
