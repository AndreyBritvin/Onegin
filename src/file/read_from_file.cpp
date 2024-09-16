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
    assert(input_ptrs != NULL);

    for (size_t i = 0; i < lines; i++)
    {
        DEBUG_ON(printf("%p\n", input_array));
        // input_ptrs[i] = {input_array, read_line(input_array)};
        input_ptrs[i].line = input_array;
        input_array += (input_ptrs[i].len = read_line(input_array) - 1) + 1;
        // DEBUG_ON(printf("input_ptrs[i] = %s, size = %d\n", input_ptrs[i].line, input_ptrs[i].len);)
    }

    return 0;
}

int init_file(Text *text, FILE *file_ptr)
{
    assert(text != NULL);

    fread(text->full_text, text->filesize, 1, file_ptr);
    DEBUG_ON(printf("Success in reading file %s\n", text->filename));

    text->lines_num = get_lines_num(text->full_text, text->filesize);
    DEBUG_ON(printf("Lines in file:%lu\n", text->lines_num));

    text->text_ptrs = (Line *) calloc(text->lines_num + 1, sizeof(Line));

    if (text->text_ptrs == NULL)
    {
        fprintf(stderr, "Error in calloc in line: %d\n", __LINE__); // TODO: Error enum / maybe lib
        return 1;
    }

    read_n_lines(text->full_text, text->text_ptrs, text->lines_num);

    return 0;
}

int work_file(const char *mode, Text *text, Parse_file_t parse_file)
{
    assert(text       != NULL);
    assert(mode       != NULL);
    assert(parse_file != NULL);

    FILE *file_input = NULL;

    if ((file_input = fopen(text->filename, mode)) == NULL)
    {
        return errno;
    }

    parse_file(text, file_input);

    if (fclose(file_input))
    {
        return errno;
    }

    DEBUG_ON(printf("Success in closing file %s\n", text->filename);)

    return 0;
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
