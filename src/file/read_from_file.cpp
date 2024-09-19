#include "read_from_file.h"

size_t read_line(char input_array[])
{
    char ch = 0;
    size_t index = 0;

    while ((ch = input_array[index++]) != EOF && ch != '\n')
    {
        DEBUG_ON(printf("<%c> (%d)", ch, ch);)
    }

    index--;

    DEBUG_ON(printf("Index at addr[%p] = %lu", input_array, index);)
    input_array[index++] = '\0';
    DEBUG_ON(printf("String: %c\n", input_array[index]);)

    return index;
}

int read_n_lines(char *input_array, Line *input_ptrs, size_t lines)
{
    assert(input_array != NULL);
    assert(input_ptrs  != NULL);

    for (size_t i = 0; i < lines; i++)
    {
        DEBUG_ON(printf("%p\n", input_array));
        // input_ptrs[i] = {input_array, read_line(input_array)};
        input_ptrs[i].line = input_array;
        input_array += (input_ptrs[i].len = read_line(input_array) - 1) + 1;
        // DEBUG_ON(printf("input_ptrs[i] = %s, size = %d\n", input_ptrs[i].line, input_ptrs[i].len);)
    }

    return SUCCESS;
}

int create_text(Text *text_to_fill, const char *filename)
{
    text_to_fill->filename = filename;

    text_to_fill->filesize = (size_t) get_file_len(text_to_fill->filename);
    DEBUG_ON(printf("File size: %lu\n", text_to_fill->filesize);)

    text_to_fill->full_text = (char  *) calloc(text_to_fill->filesize + 1, sizeof(char));

    if (text_to_fill->full_text == NULL)
    {
        PRINT_ERROR("Error in calloc for <onegin_text> with size: %lu\n", text_to_fill->filesize);

        return ERROR_CALLOC_IS_NULL;
    }

    if (work_file("r", text_to_fill, init_file))
    {
        PRINT_ERROR("Error in reading file <%s>:%s\n", text_to_fill->filename, strerror(errno));

        return EXIT_FAILURE;
    }

    return SUCCESS;
}

int init_file(Text *text, FILE *file_ptr)
{
    assert(text != NULL);

    fread(text->full_text, text->filesize, 1, file_ptr);
    DEBUG_ON(printf("Success in reading file %s\n", text->filename));

    text->lines_num = get_lines_num(text->full_text, text->filesize);
    DEBUG_ON(printf("Lines in file:%lu\n", text->lines_num));

    text->text_ptrs_right = (Line *) calloc(text->lines_num + 1, sizeof(Line));

    if (text->text_ptrs_right == NULL)
    {
        PRINT_ERROR("Error in calloc in line: %d\n", __LINE__); // TODO: Error enum / maybe lib

        return ERROR_CALLOC_IS_NULL;
    }

    text->text_ptrs_left = (Line *) calloc(text->lines_num + 1, sizeof(Line));

    if (text->text_ptrs_left == NULL)
    {
        PRINT_ERROR("Error in calloc in line: %d\n", __LINE__); // TODO: Error enum / maybe lib

        return ERROR_CALLOC_IS_NULL;
    }

    // text->text_ptrs_control = (Line *) calloc(text->lines_num + 1, sizeof(Line));

    // if (text->text_ptrs_control == NULL)
    {
        // PRINT_ERROR("Error in calloc in line: %d\n", __LINE__); // TODO: Error enum / maybe lib

        // return ERROR_CALLOC_IS_NULL;
    }

    read_n_lines(text->full_text,   text->text_ptrs_right, text->lines_num);
    memcpy(text->text_ptrs_left,    text->text_ptrs_right, text->lines_num * sizeof(Line));
    // memcpy(text->text_ptrs_control, text->text_ptrs_right, text->lines_num * sizeof(Line));

    printf("Size of pointers = %lu\n", sizeof(text->text_ptrs_right));

    return SUCCESS;
}

int work_file(const char *mode, Text *text, Parse_file_t parse_file)
{
    assert(text       != NULL);
    assert(mode       != NULL);
    assert(parse_file != NULL);

    FILE *file_input = NULL;

    if ((file_input = fopen(text->filename, mode)) == NULL)
    {
        return ERROR_FILE_IS_NULL;
    }

    if (int err_num = parse_file(text, file_input))
    {
        return err_num;
    }

    if (fclose(file_input))
    {
        return ERROR_FILE_IS_NULL;
    }

    DEBUG_ON(printf("Success in closing file %s\n", text->filename);)

    return SUCCESS;
}

__off_t get_file_len(const char *filename)
{
    assert(filename != NULL);

    struct stat st = {};
    stat(filename, &st);

    return st.st_size;
}

size_t get_lines_num(char *text, size_t text_len)
{
    assert(text != NULL);

    size_t lines_num = 0;

    for (size_t symbol = 0; symbol < text_len; symbol++)
    {
        if (text[symbol] == '\n')
        {
            lines_num++;
        }
    }

    return lines_num;
}
