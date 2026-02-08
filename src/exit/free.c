/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:15:02 by aielo             #+#    #+#             */
/*   Updated: 2026/02/08 18:40:47 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	free_data(t_data *game)
{
	if (game->textures)
		free_tab((void **)game->textures);
	if (game->texture_pixels)
		free_tab((void **)game->texture_pixels);
//	free_texinfo(&game->texinfo);
//	free_map(game);
	return (1);
}
/*
static void	free_map(t_data *data)
{
	if (data->mapinfo.fd > 0)
		close(data->mapinfo.fd);
	if (data->mapinfo.file)
		free_tab((void **)data->mapinfo.file);
	if (data->map)
		free_tab((void **)data->map);
}
*/
void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}
