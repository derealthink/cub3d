#include "parsing.h"

void    no_config(t_ulines *head, t_config *id)
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
                perror("NO texture invalid");
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

void    so_config(t_ulines *head, t_config *id)
{
    t_ulines    *current;
    char        **res;
    int         fd;

    current = head;
    while (current)
    {
        if (current->type == SO_LINE)
        {
            res = ft_split(current->line, ' ');
            if (!res || !res[1])
                return ;
            fd = open(res[1], O_RDONLY);
            if (fd == -1)
            {
                perror("SO texture invalid");
                free_split(res);
                return ;
            }
            close(fd);
            id->so = ft_strdup(res[1]);
            free_split(res);
        }
        current = current->next;
    }
}

void    we_config(t_ulines *head, t_config *id)
{
    t_ulines    *current;
    char        **res;
    int         fd;

    current = head;
    while (current)
    {
        if (current->type == WE_LINE)
        {
            res = ft_split(current->line, ' ');
            if (!res || !res[1])
                return ;
            fd = open(res[1], O_RDONLY);
            if (fd == -1)
            {
                perror("WE texture invalid");
                free_split(res);
                return ;
            }
            close(fd);
            id->we = ft_strdup(res[1]);
            free_split(res);
        }
        current = current->next;
    }
}

void    ea_config(t_ulines *head, t_config *id)
{
    t_ulines    *current;
    char        **res;
    int         fd;

    current = head;
    while (current)
    {
        if (current->type == EA_LINE)
        {
            res = ft_split(current->line, ' ');
            if (!res || !res[1])
                return ;
            fd = open(res[1], O_RDONLY);
            if (fd == -1)
            {
                perror("EA texture invalid");
                free_split(res);
                return ;
            }
            close(fd);
            id->ea = ft_strdup(res[1]);
            free_split(res);
        }
        current = current->next;
    }
}

t_ulines    *id_config(char *file, t_config *id, t_valid *d)
{
    t_ulines    *head;

    head = parse_to_list(file);
    if (val_txt_count(head, d))
    {
        no_config(head, id);
        so_config(head, id);
        ea_config(head, id);
        we_config(head, id);
    }
    if (val_cc_count(head, d) && is_dig_cc(head))
    {
        cc_config(head, id);
        cf_config(head, id);
    }
    /*while (head)
    {
        if (head->type != MAP_LINE)
            free(head);
        head = head->next;
    }
    clean_colors(id->cc);
    clean_colors(id->cf);
    return (head);
    not preserving head*/
}



