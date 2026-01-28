#include "parsing.h"

int is_first_val(t_ulines *head)
{
    t_ulines    *current;
    int         i;

    current = head;
    while (current)
    {
        if(current->type = MAP_LINE)
        {
            i = 0;
            while ( is_space(current->line[i]))
                i++;
            if (current->line[i] != '1')
                return (0);
        }
        current = current->next;
    }
    return (1);
}

int is_last_val(t_ulines *head)
{
    t_ulines    *current;
    int         i;
    int         len;

    current = head;
    while (current)
    {
        if (current->type = MAP_LINE)
        {
            len = ft_strlen(current->line);
            i = len;
            while (i > 0 && is_space(current->line[i]))
                i--;
            if (current->line[i] != '1')
                return (0);
        }
        current = current->next;
    }
    return (1);
}

int is_fline_val(t_ulines *head)
{
    t_ulines    *current;
    int         i;
    int         len;

    current = head;
    while (current->type != MAP_LINE)
        current = current->next;
    if (current->type == MAP_LINE)
    {
        i = 0;
        while (is_space(current->line[i]))
            i++;
        len = ft_strlen(current->line);
        while (is_space(current->line[len]) && len > 0)
            len--;
        while(i > len)// could be >= unsure
        {
            if (is_mapc_val(current->line[i]))
                return (0);
            i++;
        }        
    }
    return (1);
}

int is_mapc_val(char c)
{
    if (c == '1' || c == '0' ||
    c == 'N' || c == 'S' || c == 'E' ||
    c == 'W')
        return (1);
    return (0);
}
