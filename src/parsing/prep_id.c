#include "parsing.h"

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

char    *trim_lead(char *line)
{
    int i;
    int start;

    if (!line)
        return (NULL);
    i = 0;
    while (is_space(line[i]))
        i++;
    if (line[i] != '1')
    {
        start = 0;
        while (line[start] && line[start] <= 32)
            start++;
        if (start > 0)
            ft_memmove(line, line + start, ft_strlen(line + start) + 1);
    }
    return (line);
}

char    *trim_trail(char *line)
{
    int len;

    if (!line)
        return (NULL);
    len = ft_strlen(line);
    len--;
    if (line[0] != '1')
    {
        while(is_space(line[len]))
        {
            line[len] = '\0';
            len--;
        }
    }
    return (line);
}

char    **prep_id(char **map)
{

    int i;

    printf("entered prep id\n");
    map = del_empty(map);
    i = 0;
    while (map[i] != NULL)
    {
        map[i] = trim_lead(map[i]);
        map[i] = trim_trail(map[i]);
        i++;
    }
    map = del_empty(map);// in case a line becomes empty
    return (map);
}
