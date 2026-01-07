/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:12:14 by aielo             #+#    #+#             */
/*   Updated: 2026/01/07 16:57:45 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>
#include <mlx.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_data
{
    void    *mlx;
    void    *win;
}   t_data;

static void put_pixel(void *mlx, void *win, int x, int y, int color)
{
    /* Easiest way to debug MLX setup: draw a 1x1 rectangle (pixel) */
    mlx_pixel_put(mlx, win, x, y, color);
}

static void draw_circle(t_data *data, int xc, int yc, int r, int color)
{
    int x = 0;
    int y = r;
    int d = 1 - r;

    while (x <= y)
    {
        put_pixel(data->mlx, data->win, xc + x, yc + y, color);
        put_pixel(data->mlx, data->win, xc - x, yc + y, color);
        put_pixel(data->mlx, data->win, xc + x, yc - y, color);
        put_pixel(data->mlx, data->win, xc - x, yc - y, color);
        put_pixel(data->mlx, data->win, xc + y, yc + x, color);
        put_pixel(data->mlx, data->win, xc - y, yc + x, color);
        put_pixel(data->mlx, data->win, xc + y, yc - x, color);
        put_pixel(data->mlx, data->win, xc - y, yc - x, color);
        if (d < 0)
            d += 2 * x + 3;
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

int main(void)
{
    t_data  data;

    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "MLX Circle");
    if (!data.win)
        return (1);

    /* Draw circle in the middle of the window */
    draw_circle(&data, WIDTH / 2, HEIGHT / 2, 100, 0x00FFFFFF);

    mlx_loop(data.mlx);
    return (0);
}

/*
static void	init_map(t_map *game)
{
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->total_coins = 0;
	game->collect_coins = 0;
	game->start_x = 0;
	game->start_y = 0;
	game->moves = 0;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
}
*/