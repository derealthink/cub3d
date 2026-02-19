/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:20:51 by uponci            #+#    #+#             */
/*   Updated: 2026/01/27 15:24:47 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int  open_map(char *file)
{
    int     fd;

    fd = 0;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (-1);
    return (fd);
}

static int  count_lines(int fd)
{
    char    *line;
    int     count;

    count = 0;
    while ((line = get_next_line(fd)))
    {
        count ++;
        free(line); //may be not needed 
    }
    return (count);
}

static char  **create_map(int count, char *file)
{
    char    **res;
    int     i;
    char    *line;
    int     fd;

    fd = open_map(file);
    res = malloc(sizeof(char *) * (count + 1));
    if (!res)
        return (NULL);
    i = 0;
    while (i < count)
    {
        line = get_next_line(fd);
        if (line == NULL)
        {
            free(res);
            return (NULL);
        }
        res[i] = line;
        i++;
    }
    res[count] = NULL;
    close(fd);
    return (res);
}

char    **call_map(char *file)
{
    int     count;
    int     fd;
    char    **map;

//    printf("entered call map\n");
    fd = open_map(file);
    if (fd < 0)
    {
        error_msg("map file cannot be opened", 1);
        return (NULL);
    }
    count = count_lines(fd);
    close(fd);
    map = create_map(count, file);

    return (map);
}
