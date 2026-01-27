#include "parsing.h"

void    cc_config(t_ulines *head, t_config *id)
{
    t_ulines    *current;
    char        **res;
    int         i;
//    int         j;

    current = head;
    i = 1;
    while (current)
    {
        if (current->type == CC_LINE)
        {
            res = ft_split(current->line, ',');
            if (!res || !res[1])
                return ;
            free(res[0]);
            id->cc = res;
        }
        current = current->next;
    }
}

void    cf_config(t_ulines *head, t_config *id)
{
    t_ulines    *current;
    char        **res;
    int         i;
//    int         j;

    current = head;
    i = 1;
    while (current)
    {
        if (current->type == CF_LINE)
        {
            res = ft_split(current->line, ',');
            if (!res || !res[1])
                return ;
            free(res[0]);
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
