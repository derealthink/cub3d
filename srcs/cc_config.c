#include "cub3d.h"

void    cc_config(t_ulines *head, t_config *id)
{
    t_ulines    *current;
    char        **res;
    int         i;
    int         j;

    current = head;
    i = 1;
    j = 0;
    while (current)
    {
        if (current->type == CC_LINE)
        {
            res = ft_split(current->line, ',');
            if (!res || !res[1])
                return ;
            while(res[i])
            {
                id->cc[j] = ft_strdup(res[i]);
                i++;
                j++;
            }
            free_split(res);
        }
        current = current->next;
    }
}

void    cf_config(t_ulines *head, t_config *id)
{
    t_ulines    *current;
    char        **res;
    int         fd;

    current = head;
    while (current)
    {
        if (current->type == NO_LINE)
        {
            res = ft_split(current->line, ' ');
            if (!res || !res[1])
                return ;
            fd = open(res[1], O_RDONLY);
            if (fd == -1)
            {
                perror("NO texture");
                free_split(res);
                return ;
            }
            close(fd);
            id->no = ft_strdup(res[1]);
            free_split(res);
        }
        current = current->next;
    }
}

int range_val(char **arr)
{

}