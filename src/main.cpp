#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_from_file.h"
#include "write_to_file.h"

#include "sort_strings.h"
#include "swap_strings.h"

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
        fprintf(stderr, "Error in calloc for <onegin_text> with size: %lu\n", Onegin.filesize);
        return EXIT_FAILURE;
    }

    if (int err_num = work_file("r", &Onegin, init_file))
    {
        fprintf(stderr, "Error in reading file <%s>:%s\n", Onegin.filename, strerror(err_num));
    }
    DEBUG_ON(print_text(Onegin.text_ptrs, Onegin.lines_num);)
    bubble_sort(Onegin.text_ptrs, Onegin.lines_num, my_strcmp_begin);
    print_text(Onegin.text_ptrs, Onegin.lines_num);

    Onegin.filename = "texts/output/onegin_english.txt";
    if (int err_num = work_file("w", &Onegin, write_to_file))
    {
        fprintf(stderr, "Error in writing file <%s>:%s\n", Onegin.filename, strerror(err_num));
    }

    free(Onegin.full_text);
    free(Onegin.text_ptrs);

    return EXIT_SUCCESS;
}
