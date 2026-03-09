#include "parsing.h"

int is_val_chars(char c)
{
    return((c >= '0' && c <= '9') || c == ' ' || c == ',' || c == '\n');
}

int color_check(t_ulines *head)
{
    t_ulines    *current;
    int         i;

    current = head;
    while (current)
    {
        if (current->type == CC_LINE || current->type == CF_LINE)
        {
            i = 1;
            while (current->line[i])
            {
                if (!is_val_chars(current->line[i]))
                    return (0);
                i++;
            }
        }
        current = current->next;
    }
    return (1);
}


