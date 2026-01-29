/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:54:08 by aielo             #+#    #+#             */
/*   Updated: 2026/01/29 18:03:51 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	minimap_put_pixel(t_data *game, int x, int y, int color);
static void	draw_map_to_buffer(t_data *game);
static void	draw_tile_to_buffer(t_data *game, size_t x, size_t y);
static void	draw_rectangle(t_data *game, int x, int y, int size, int color);

int	render_minimap(t_data *game)
{
	size_t	y;
	size_t	x;

	y = 0;
//	ft_memset(game->minimap.addr, 0,
//		game->minimap.line_length * game->map_height * IMG_PXL);
	while (y < (size_t)game->map_height * IMG_PXL)
	{
		x = 0;
		while (x < (size_t)game->map_width * IMG_PXL)
		{
			minimap_put_pixel(game, x, y, MAP_BG_COLOR);
			x++;
		}
		y++;
	}
	draw_map_to_buffer(game);
	draw_rectangle(game,
		(game->player.pos_x * IMG_PXL),
		(game->player.pos_y * IMG_PXL),
		IMG_PXL / 2, MAP_PLAYER_COLOR);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap.img,
		10, HEIGHT - (game->map_height * IMG_PXL) - 10);

	printf("pos_x:%f pos_y:%f rotate:%d\r",
		game->player.pos_x,
		game->player.pos_y,
		game->player.rotate);
	fflush(stdout);

	return (0);
}

static void	draw_map_to_buffer(t_data *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (size_t)game->map_height)
	{
		x = 0;
		while (x < (size_t)game->map_width && game->map[y][x] != '\0')
		{
			draw_tile_to_buffer(game, x, y);
			x++;
		}
		y++;
	}
}

static void	draw_tile_to_buffer(t_data *game, size_t x, size_t y)
{
	if (game->map[y][x] == '1')
		draw_rectangle(game, x * IMG_PXL, y * IMG_PXL,
			IMG_PXL / 2, MAP_WALL_COLOR);
	else if (game->map[y][x] == ' ')
		draw_rectangle(game, x * IMG_PXL, y * IMG_PXL,
			IMG_PXL, MAP_BG_COLOR);
	else if (game->map[y][x] == '0')
		draw_rectangle(game, x * IMG_PXL, y * IMG_PXL,
			IMG_PXL, MAP_FLOOR_COLOR);
	else if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
		|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
		draw_rectangle(game, x * IMG_PXL, y * IMG_PXL,
			IMG_PXL, MAP_FLOOR_COLOR);
}

static void	draw_rectangle(t_data *game, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			minimap_put_pixel(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

static void	minimap_put_pixel(t_data *game, int x, int y, int color)
{
	char	*pxl;

	if (x < 0 || x >= game->map_width * IMG_PXL
		|| y < 0 || y >= game->map_height * IMG_PXL)
		return ;
	pxl = game->minimap.addr + (y * game->minimap.line_length
			+ x * (game->minimap.bits_per_pixel / 8));
	*(unsigned int *)pxl = (unsigned int)color;
}
