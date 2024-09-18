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

    return SUCCESS;
}

int write_to_file(Text *text, FILE *file_ptr)
{
    DEBUG_ON(printf("Entering write_to_file_func\n");)

    fprintf(file_ptr, "Sorted right edge MeOwnegin:\n\n");
    for (size_t i = 0; i < text->lines_num; i++)
    {
        fprintf(file_ptr, "%s\n", text->text_ptrs_right[i].line);
    }
    DEBUG_ON(printf("Printed Right Sorted MeowNegin\n");)

    fprintf(file_ptr, "\nSorted right edge MeOwnegin:\n\n");
    for (size_t i = 0; i < text->lines_num; i++)
    {
        fprintf(file_ptr, "%s\n", text->text_ptrs_left[i].line);
    }
    DEBUG_ON(printf("Printed Left Sorted MeowNegin\n");)

    fprintf(file_ptr, "\nOriginal Onegin:\n\n");
    char *full_text = text->full_text;
    for (size_t i = 0; i < text->lines_num; i++)
    {
        full_text += fprintf(file_ptr, "%s\n", full_text);
    }
    DEBUG_ON(printf("Printed original Onegin\n");)

    return SUCCESS;
}

int destroy(void *arr_to_destroy, size_t arr_len, size_t el_size)
{
    assert(arr_to_destroy != NULL);

    memset(arr_to_destroy, 0, el_size * arr_len);

    free(arr_to_destroy);

    return SUCCESS;
}
