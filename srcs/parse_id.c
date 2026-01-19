#include "cub3d.h"

char    **read_prep(char *file)//maybe to throwaway
{
    char    **map;

    map = map(file);
    map = prep_id(map);

    return (map)
}

char    **split_idt(char *line)//different split in place for c 
{
    char    **id;
    int     i;

    if (!line)
        return (NULL);
    if (line[0] != '1' && (!is_sapce(line[0])))
    {
        id = ft_split(line, ' ');
    }
    i = 0;
    while (id[i] != NULL)
        i++;
    if (i < 2)
    {
        free(id);
        return (NULL);
    }
    return (id);
}

void    place_idt(char **id, t_config *config)
{
    int i;

    i = 0;
    if (!id)
        return ;
    while (id[i] != NULL)
    {
        if (ft_strcmp(id[i], "NO") == 0)
            config->no = ft_strdup(id[i + 1]);
        else if (ft_strcmp(id[i], "SO") == 0)
            config->so = ft_strdup(id[i + 1]);
        else if (ft_strcmp(id[i], "EA") == 0)
            config->ea = ft_strdup(id[i + 1]);
        else if (ft_strcmp(id[i], "WE") == 0)
            config->we = ft_strdup(id[i + 1]);
        i++;
    }
}

void    place_idc(char **id, t_config *config)
{
    int i;

    i = 0;
    if (!id)
        return ;
    while (id[i] != NULL)
    {
        if (ft_strcmp(id[i], "C") == 0)
            *config->cc = ft_split(id[i + 1], ',');
        else if (ft_strcmp(id[i], "F") == 0)
            *config->fc = ft_split(id[i + 1], ',');
        i++;
    }
}


