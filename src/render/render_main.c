/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:54 by aielo             #+#    #+#             */
/*   Updated: 2026/01/30 00:05:08 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	render_raycasting(t_data *game);
static void	draw_background(t_data *game);

int	render(t_data *game)
{
	static double	last_frame = 0;
	static double	last_move_time = 0;
	double			now;
	double			frame_time;

	now = get_time_ms();
	if (last_frame == 0)
		last_frame = now;
	if (last_move_time == 0.0)
		last_move_time = now;
	frame_time = now - last_frame;
	if (now - last_move_time >= FRAME_RATE_MS)
	{
		game->player.has_moved = game->player.has_moved + player_move(game);
		last_move_time = now;
	}
	if (frame_time >= FRAME_RATE_MS)
	{
		render_frame(game);
		last_frame = now;
		game->player.has_moved = 0;
	}
	return (0);
}

void	render_frame(t_data *game)
{
	draw_background(game);
	render_raycasting(game);
	render_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap.img,
		10, HEIGHT - (game->map_height * IMG_PXL) - 10);
	printf("pos_x:%.2f pos_y:%.2f\r", game->player.pos_x, game->player.pos_y);
	fflush(stdout);
}

static void	draw_background(t_data *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < HEIGHT / 2)
			color = 0x183e4b; //game->texinfo.hex_ceiling;
		else
			color = 0xd74a49; //game->texinfo.hex_floor;
		x = 0;
		while (x < WIDTH)
		{
			frame_put_pixel(&game->frame, x, y, color);
			x++;
		}
		y++;
	}
}

static void	render_raycasting(t_data *game)
{
//	init_texture_pixels(game);
//	init_ray(&game->ray);
	raycasting(&game->player, game);
}

/*
void	render_frame(t_data *game)
{
//	mlx_clear_window(game->mlx, game->win);
	printf("pos_x:%.2f pos_y:%.2f\r", game->player.pos_x, game->player.pos_y);
	fflush(stdout);
	render_frame(game);
	render_minimap(game);
}

int	render(t_data *game)
{
	game->player.has_moved = game->player.has_moved + player_move(game);
	if (game->player.has_moved == 0)
		return (0);
//	usleep(16667);
	render_loop(game);
	return (0);
}
*/