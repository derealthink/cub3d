#include "parsing.h"

void    cc_config(t_ulines *head, t_config *id)
{
    t_ulines    *current;
    char        **res;
    int         i;

    current = head;
    i = 1;
    while (current)
    {
        if (current->type == CC_LINE)
        {
            res = ft_split(current->line, ',');
            if (!res)
                return ;
            res = clean_colors(res);
            if (range_val(res))
                id->cc = res;
        }
        current = current->next;
    }
}

void    cf_config(t_ulines *head, t_config *id)
{
    t_ulines    *current;
    char        **res;

    current = head;
    while (current)
    {
        if (current->type == CF_LINE)
        {
            res = ft_split(current->line, ',');
            if (!res)
                return ;
            res = clean_colors(res);
            if (range_val(res))
                id->cf = res;
        }
        current = current->next;
    }
}

int range_val(char **arr)
{
    int i;
    int num;
    int count;

    i = 0;
    num = 0;
    count = 0;
    while (arr[i] != NULL)
    {
        num = ft_atoi(arr[i]);
        if (num >= 0 && num <= 255)
            count++;
        i++;
    }
    return (count == 3);
}


char **clean_colors(char **arr)
{
    int i;
    int read;
    int write;

    if (!arr)
        return NULL;

    i = 0;
    while (arr[i])
    {
        read = 0;
        write = 0;

        while (arr[i][read])
        {
            if (ft_isdigit(arr[i][read]))
                arr[i][write++] = arr[i][read];
            read++;
        }
        arr[i][write] = '\0';
        if (write == 0)
            return (NULL);
        i++;
    }
    return (arr);
}

