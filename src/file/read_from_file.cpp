#include "read_from_file.h"

int read_line(char input_array[], FILE *fp)
{
    char ch = 0;
    int index = 0;

    while (fscanf(fp, "%c", &ch) != EOF && ch != '\n')
    {
        input_array[index++] = ch;
    }

    // printf("Index at addr[%p] = %d", input_array, index);
    input_array[index++] = '\0';
    // printf("String: %c\n", input_array[index]);
    return index;
}

int read_n_lines(char input_array[], char *input_ptrs[], size_t lines, FILE *fp)
{
    for (size_t i = 0; i < lines; i++)
    {
        input_ptrs[i] = input_array;
        input_array += read_line(input_array, fp);
        // printf("%p\n", input_array);
    }

    return 0;
}

int open_file(FILE **fp, const char filename[])
{
    if ((*fp = fopen(filename, "r")) == NULL)
    {
        return errno;
    }

    return 0;
}

int get_file_len(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    int size =ftell(fp);
    fseek(fp, 0, SEEK_SET);

    return size;
}
