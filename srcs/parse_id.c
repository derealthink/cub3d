#include "cub3d.h"

char    **del_empty(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i] != NULL)
    {
        if (!is_empty_line(map[i]))
        {
            map[j] = map[i];
            j++;
        }
        else
            free(map[i]);
        i++;
    }
    map[j] = NULL;
    return (map);
}

char    **trim_lead(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i] !== NULL)
    {
        
    }
}

