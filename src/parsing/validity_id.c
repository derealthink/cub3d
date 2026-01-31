#include "parsing.h"

int val_txt_count(t_ulines *head, t_valid *d)
{
    t_ulines    *current;

    if (!head)
        return (0);
    current = head;
    while (current)
    {
        if (current->type == MAP_LINE)
            return (0);
        else if (current->type == NO_LINE)
            d->no = 1;
        else if (current->type == SO_LINE)
            d->so = 1;
        else if (current->type == EA_LINE)
            d->ea = 1;
        else if (current->type == WE_LINE)
            d->we = 1;
        current = current->next;
    }
    if (d->no && d->so && d->ea && d->we)
        return (1);
    return (0);
}

int val_cc_count(t_ulines *head, t_valid *d)
{
    t_ulines    *current;

    if (!head)
        return (0);
    current = head;
    while (current)
    {
        if (current->type == MAP_LINE)
            return (0);
        else if (current->type == CC_LINE)
            d->cc = 1;
        else if (current->type == CF_LINE)
            d->cf = 1;
        current = current->next;
    }
    if (d->cc && d->cf)
        return (1);
    return (0); 
}

int is_dig_cc(t_ulines *head)
{
    t_ulines    *current;
    int         d;
    int         i;

    current = head;
    i = 0;
    d = 0;
    while (current)
    {
        if (current->type == CC_LINE)
        {
           while(current->line[i])      //make here one loop for both cahnge the condition 
           {
                if(is_digit(current->line[i]))
                    d = 1;
           }
        }
        if (current->type == CF_LINE && d)
        {
            if (ft_isdigit(current->line))      //change flag shorten
                return (1);
        }
        current = current->next;
    }
    return (0);
}

int val_mp_count(t_ulines *head)
{
    int         mp_count;
    t_ulines    *current;

    if (!head)
        return (0);
    mp_count = 0;
    current = head;
    while (current)
    {
        if (current->type == MAP_LINE)
            mp_count++;
        current = current->next;
    }
    if (mp_count > 2)
        return (1);
    return (0);
}

