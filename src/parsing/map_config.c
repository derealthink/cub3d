/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:28:55 by aielo             #+#    #+#             */
/*   Updated: 2026/01/29 17:29:29 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
/*
// after you allocate/fill game->map, which is NULL-terminated
int	get_map_height(char **map)
{
	int h;

	h = 0;
	while (map[h])
		h++;
	return h;
}

//	in your init/parsing code
//	game->map_height = get_map_height(game->map);

int	get_map_width(char **map)
{
	int w;
	int i;
	int len;

	w = 0;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > w)
			w = len;
		i++;
	}
	return (w - 1);
}

//	after reading the map:
//	game->map_width = get_map_width(game->map);
*/

int	map_line_count(t_ulines *head)
{
	t_ulines	*current;
	int			count;

	current = head;
	count = 0;
	while (current)
	{
		if (current->type == MAP_LINE)
			count++;
		current = current->next;
	}
	return (count);
}
int	fill_map_array(char **arr, t_ulines *head, int len)
{
	t_ulines	*current;
	int			i;

	current = head;
	i = 0;
	while (current)
	{
		if (current->type == MAP_LINE)
		{
			arr[i] = ft_strdup(current->line);
			if (!arr[i])
			{
				free_map(arr);
				return (0);
			}
			i++;
		}
		current = current->next;
	}
	arr[len] = NULL;
	return (1);
}

char	**map_config(t_data *game, t_ulines *head)
{
	int		len;
	char	**arr;

	(void)game;
	len = map_line_count(head);
	arr = malloc(sizeof(char *) * (len + 1));
	if (!arr)
		return (NULL);
	if (!fill_map_array(arr, head, len))
		return (NULL);
	return (arr);
}

