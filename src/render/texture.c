/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:07:54 by aielo             #+#    #+#             */
/*   Updated: 2026/02/08 18:21:44 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	init_texture_pixels(t_data *game)
{
	int	i;

	if (game->texture_pixels)
		free_tab((void **)game->texture_pixels);
	game->texture_pixels = ft_calloc(game->win_height + 1,
			sizeof * game->texture_pixels);
	if (!game->texture_pixels)
		clean_exit(game, error_msg(ERR_MALLOC, 1));
	i = 0;
	while (i < game->win_height)
	{
		game->texture_pixels[i] = ft_calloc(game->win_width + 1,
				sizeof * game->texture_pixels);
		if (!game->texture_pixels[i])
			clean_exit(game, error_msg(ERR_MALLOC, 1));
		i++;
	}
}
/*
static void	get_texture_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->texinfo.index = WEST;
		else
			data->texinfo.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->texinfo.index = SOUTH;
		else
			data->texinfo.index = NORTH;
	}
}

void	update_texture_pixels(t_data *data, t_texinfo *tex, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_index(data, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - data->win_height / 2
			+ ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = data->textures[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->texture_pixels[y][x] = color;
		y++;
	}
}
*/