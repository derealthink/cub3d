/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:49:24 by aielo             #+#    #+#             */
/*   Updated: 2026/01/27 15:09:48 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#define IMG_PXL 5

static void	draw_tile_to_buffer(t_data *game, size_t x, size_t y);
//static void	draw_sprite_to_buffer(t_data *game, t_img *sprite,
//				int pos_x, int pos_y);
//static int	get_sprite_pixel_color(t_img *sprite, int x, int y);
//static void	put_pixel(t_img *img, int x, int y, int color);

void	draw_map_to_buffer(t_data *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_tile_to_buffer(game, x, y);
			x++;
		}
		y++;
	}
}

static void	draw_tile_to_buffer(t_data *game, size_t x, size_t y)
{
	int	pos_x;
	int	pos_y;

	pos_x = x * IMG_PXL;
	pos_y = y * IMG_PXL;
	if (game->map[y][x] == '1') // Wall
		mlx_pixel_put(game->mlx, game->win, x * 5, y * 5, 0xFF0000);
	if (game->map[y][x] == '0') // Empty
		mlx_pixel_put(game->mlx, game->win, x * 5, y * 5, 0xFFFF00);
	else if (game->map[y][x] == 'N') // Player
	{	mlx_pixel_put(game->mlx, game->win, x * 5, y * 5, 0x008000);
		game->player.pos_x = x;
		game->player.pos_y = y;
	}
}
/*
static void	draw_sprite_to_buffer(t_data *game, t_img *sprite,
	int pos_x, int pos_y)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < IMG_PXL)
	{
		x = 0;
		while (x < IMG_PXL)
		{
			color = get_sprite_pixel_color(sprite, x, y);
			if (color != TRANSPARENT_COLOR)
				put_pixel(&game->img_buffer, pos_x + x, pos_y + y, color);
			x++;
		}
		y++;
	}
}

static int	get_sprite_pixel_color(t_img *sprite, int x, int y)
{
	char	*pixel_addr;
	int		color;

	pixel_addr = sprite->addr + (y * sprite->line_length
			+ x * (sprite->bits_per_pixel / 8));
	color = *(int *)pixel_addr;
	return (color);
}

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pxl;

	if (x < 0 || x >= (int)img->line_length / (img->bits_per_pixel / 8)
		|| y < 0)
		return ;
	pxl = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pxl = color;
}
*/