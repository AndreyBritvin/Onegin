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

    fprintf(file_ptr, "Sorted left edge MeOwnegin:\n\n");
    for (size_t i = 0; i < text->lines_num; i++)
    {
        #ifdef STALIN
        DEBUG_ON(
                printf("Len %lu of line %p\n", text->text_ptrs_left[i].len, text->text_ptrs_left[i].line);
                )
        if (text->text_ptrs_right[i].line == GULAG_ADDR)
        {
            DEBUG_ON(printf("Yes_yes\n"));
            continue;
        }
        #endif
        fprintf(file_ptr, "%s\n", text->text_ptrs_right[i].line);
    }
    DEBUG_ON(printf("Printed Right Sorted MeowNegin\n");)

    fprintf(file_ptr, "\nSorted right edge MeOwnegin:\n\n");
    for (size_t i = 0; i < text->lines_num; i++)
    {
        #ifdef STALIN
        DEBUG_ON(
                printf("Len %lu of line %p, %lu\n", text->text_ptrs_left[i].len, text->text_ptrs_left[i].line,
                                                    text->text_ptrs_left[i].line);
                )
        if (text->text_ptrs_left[i].line == GULAG_ADDR)
        {
            DEBUG_ON(printf("no_no\n"));
            continue;
        }
        #endif
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

int destroy_text(Text *text_to_destr)
{
    destroy(text_to_destr->full_text,       text_to_destr->filesize,  sizeof(text_to_destr->full_text[0]));
    destroy(text_to_destr->text_ptrs_left,  text_to_destr->lines_num, sizeof(Line));
    destroy(text_to_destr->text_ptrs_right, text_to_destr->lines_num, sizeof(Line));

    return SUCCESS;
}
