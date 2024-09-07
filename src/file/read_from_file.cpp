#include "read_from_file.h"

int read_n_lines(char input_array[][42], size_t lines, int line_len, FILE *fp)
{
    for (size_t i = 0; i < lines; i++)
    {
        fgets(input_array[i], line_len, fp);
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
