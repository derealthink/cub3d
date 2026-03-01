#include "parsing.h"

static int player_char(char c)
{
    return (c == 'W'|| c == 'E' || c == 'N' || c == 'S');
}

int validate_player(t_ulines *head)
{
    t_ulines    *current;
    int         i;
    int         res;

    current = head;
    res = 0;
    while (current)
    {
        i = 0;
        if (current->type == MAP_LINE)
        {
            while (current->line[i])
            {
                if (player_char(current->line[i]))
                    res++;
                i++;
            }
        }
        current = current->next;
    }
    if (res != 1)
        return (0);
    return (1);
}
