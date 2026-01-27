/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:54:08 by aielo             #+#    #+#             */
/*   Updated: 2026/01/27 17:22:52 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

static void my_put_pixel(t_data *game, int x, int y, int color);
static void	draw_map_to_buffer(t_data *game);
static void	draw_tile_to_buffer(t_data *game, size_t x, size_t y);
static void draw_rectangle(t_data *game, int x, int y, int size, int color);

//static void draw_line(void *img, int x0, int y0, int x1, int y1, uint32_t color);
//static void my_put_pixel_img(void *img, int x, int y, int color);

int	render_loop_moves(t_data *game)
{

	size_t	y = 0;
	size_t	x;

	while (y < MINI_H)
	{
		x = 0;
		while (x < MINI_W)
		{
			my_put_pixel(game, x, y, 0x000000);
			x++;
		}
		y++;
	}
/*
	PLAYER MOVES
	// Normal test
	int screen_x = (int)(game->player.pos_x * 32);
	int screen_y = (int)(game->player.pos_y * 32);
	if (screen_x >= 0 && screen_x < WIDTH && screen_y >= 0 && screen_y < HEIGHT)
		my_put_pixel(game, screen_x, screen_y, 0xFFFFFF);

	// Pac-Man wrap
	int screen_x = (int)fmod(game->player.pos_x * 32, WIDTH);
	int screen_y = (int)fmod(game->player.pos_y * 32, HEIGHT);
	if (screen_x < 0)
		screen_x = screen_x + WIDTH;
	if (screen_y < 0)
		screen_y = screen_y + HEIGHT;
	my_put_pixel(game, screen_x, screen_y, 0xFF0000);

	// Print Vector
	int px = screen_x, py = screen_y;  // player center
	int ex = (int)fmod((game->player.pos_x + game->player.plane_x) * 32, WIDTH);
	int ey = (int)fmod((game->player.pos_y + game->player.plane_y) * 32, HEIGHT);
	if (ex < 0) 
		ex = ex + WIDTH;
	if (ey < 0)
		ey = ey + HEIGHT;
	draw_line(game->minimap.img, px, py, ex, ey, 0xFFFF00);
*/
	draw_map_to_buffer(game);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap.img, 0, 0);
//	printf("pos_x:%f pos_y:%f rotate:%d\r",
//		game->player.pos_x,
//		game->player.pos_y,
//		game->player.rotate);
	fflush(stdout);
	return (0);
}

static void	draw_map_to_buffer(t_data *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (size_t)game->map_height && y * IMG_PXL < MINI_H)
	{
		x = 0;
		while (x < (size_t)game->map_width && x * IMG_PXL < MINI_W && game->map[y][x] != '\0') 
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
		draw_rectangle(game, x * IMG_PXL, y * IMG_PXL, IMG_PXL, 0xFF0000);
	else if (game->map[y][x] == '0')
		draw_rectangle(game, x * IMG_PXL, y * IMG_PXL, IMG_PXL, 0xFFFF00);
	else if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
		|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
	{
		draw_rectangle(game, x * IMG_PXL, y * IMG_PXL, IMG_PXL, 0x000000);
		game->player.pos_x = x;
		game->player.pos_y = y;
	}
}

static void draw_rectangle(t_data *game, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_put_pixel(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

static void my_put_pixel(t_data *game, int x, int y, int color)
{
	char *pxl;
	
	if (x < 0 || x >= MINI_W || y < 0 || y >= MINI_H)
		return ;
	pxl = game->minimap.addr
		+ (y * game->minimap.line_length
		+ x * (game->minimap.bits_per_pixel / 8));
	*(unsigned int *)pxl = (unsigned int)color;
}

/*
static void draw_line(void *img, int x0, int y0, int x1, int y1, uint32_t color)
{
    int dx = abs(x1 - x0), dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1, sy = y0 < y1 ? 1 : -1;
    int err = dx - dy, e2;
    
    while (1) {
        if (x0 >= 0 && x0 < WIDTH && y0 >= 0 && y0 < HEIGHT)
            my_put_pixel_img(img, x0, y0, color);  // Use image-specific pixel func
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}

static void my_put_pixel_img(void *img, int x, int y, int color)
{
    char    *dst;
    int     bpp;
    int     size_line;
    int     endian;

    dst = mlx_get_data_addr(img, &bpp, &size_line, &endian);
    
    // Ensure coordinates are within image bounds
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    
    // Calculate pixel offset (assuming 32bpp/4 bytes per pixel)
    dst += (y * size_line + x * (bpp / 8));
    
    // Handle endianness for 32-bit color
    if (endian == 1)
    {
        // Big-endian: ARGB
        ((unsigned char *)dst)[0] = (color >> 24) & 0xFF; // A
        ((unsigned char *)dst)[1] = (color >> 16) & 0xFF; // R
        ((unsigned char *)dst)[2] = (color >> 8) & 0xFF;  // G
        ((unsigned char *)dst)[3] = color & 0xFF;         // B
    }
    else
    {
        // Little-endian: BGRA
        ((unsigned char *)dst)[0] = color & 0xFF;         // B
        ((unsigned char *)dst)[1] = (color >> 8) & 0xFF;  // G
        ((unsigned char *)dst)[2] = (color >> 16) & 0xFF; // R
        ((unsigned char *)dst)[3] = (color >> 24) & 0xFF; // A
    }
}
*/
