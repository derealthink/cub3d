/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:54 by aielo             #+#    #+#             */
/*   Updated: 2026/01/29 17:51:47 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

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
		game->player.has_moved += player_move(game);
		last_move_time = now;
	}
	if (frame_time >= FRAME_RATE_MS)
	{
		render_loop(game);
		last_frame = now;
		game->player.has_moved = 0;
	}
	return (0);
}

/*
int	render(t_data *game)
{
	game->player.has_moved = game->player.has_moved + player_move(game);
	if (game->player.has_moved == 0)
		return (0);
	usleep(16667);
	render_loop(game);
	return (0);
}
*/

void	render_loop(t_data *game)
{
	//mlx_clear_window(game->mlx, game->win);
	render_frame(game);
	render_minimap(game);
}

/*
// render 60fps e refresh movimento
int render(t_data *game)
{
    static double   last_frame = 0;
    static double   last_move_time = 0;
    static int      first_frame = 1;
    static int      refresh_counter = 0;
    double          now;
    double          frame_time;

    now = get_time_ms();
    if (last_frame == 0)
        last_frame = now;
    if (last_move_time == 0.0)
        last_move_time = now;
    
    frame_time = now - last_frame;
    
    // Fixed-rate movement (60 Hz)
    if (now - last_move_time >= FRAME_RATE_MS)
    {
        game->player.has_moved += player_move(game);
        last_move_time = now;
    }
    
    // Render at 60 FPS with smart refresh logic
    if (frame_time >= FRAME_RATE_MS)
    {
        refresh_counter++;
        
        // Render on: first frame OR player moved OR every 300 frames (~5 seconds at 60fps)
        if (first_frame || game->player.has_moved > 0 || refresh_counter % 300 == 0)
        {
            render_loop(game);
            first_frame = 0;
        }
        
        last_frame = now;
        game->player.has_moved = 0;
    }
    return (0);
}


//always render
int render(t_data *game)
{
    static double   last_frame = 0;
    static double   last_move_time = 0;
    double          now;
    double          frame_time;

    now = get_time_ms();
    if (last_frame == 0)
        last_frame = now;
    if (last_move_time == 0.0)
        last_move_time = now;
    
    frame_time = now - last_frame;
    
    // Fixed-rate movement (60 Hz)
    if (now - last_move_time >= FRAME_RATE_MS)
    {
        game->player.has_moved += player_move(game);
        last_move_time = now;
    }
    
    // ALWAYS render at 60 FPS - bulletproof window refresh
    if (frame_time >= FRAME_RATE_MS)
    {
        render_loop(game);           // ← Always render (no has_moved check)
        last_frame = now;
        game->player.has_moved = 0;
    }
    return (0);
}

*/