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
