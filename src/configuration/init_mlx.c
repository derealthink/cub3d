/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:25:05 by aielo             #+#    #+#             */
/*   Updated: 2026/01/29 01:52:01 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration.h"

void	init_mlx(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		clean_exit(game, error_msg(ERR_MLX_START, 1));
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3d");
	if (!game->win)
		clean_exit(game, error_msg(ERR_MLX_START, 1));
	init_image(game, &game->minimap, MINI_W, MINI_H);
	return ;
}

void	init_image(t_data *game, t_img *image, int width, int height)
{
	init_img_data(image);
	image->img = mlx_new_image(game->mlx, width, height);
	if (image->img == NULL)
		clean_exit(game, error_msg(ERR_MLX_IMG, 1));
	image->addr = mlx_get_data_addr(image->img,
		&image->bits_per_pixel,
		&image->line_length,
		&image->endian);
//	image->width = width;
//	image->height = height;
	return ;
}
