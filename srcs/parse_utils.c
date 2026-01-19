#include "cub3d.h"

int is_space(char c)
{
    if (c <= 32)
        return (1);
    return (0);
}

int is_empty_line(char *line)
{
    int i;

    i = 0;
    if (!line)
        return (0);
    while (line[i] && is_space(line[i]))
    {
        i++;
    }
    return (line[i] == '\0');
}