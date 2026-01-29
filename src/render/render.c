/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:54 by aielo             #+#    #+#             */
/*   Updated: 2026/01/29 02:11:52 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "execution.h"
/*
int render(t_data *game)
{
    static double   last_frame = 0;
    static double   last_move_time = 0;
    double          now = get_time_ms();
    double          frame_time;
    double          target = 1000.0 / 60.0;

    if (last_frame == 0)
        last_frame = now;

    frame_time = now - last_frame;

    // Move ONLY once per ~16ms (60 times/sec)
    if (now - last_move_time >= 1000.0/60.0)
    {
        game->player.has_moved += player_move(game);
        last_move_time = now;
    }

    // Only render if enough time passed
    if (frame_time >= target)
    {
        if (game->player.has_moved > 0)
            render_loop(game);
        last_frame = now;
        game->player.has_moved = 0;  // Reset for next frame
    }
    return (0);
}
*/
int	render(t_data *game)
{
	game->player.has_moved = game->player.has_moved + player_move(game);
	if (game->player.has_moved == 0)
		return (0);
	render_loop(game);
	return (0);
}

void	render_loop(t_data *game)
{
	render_minimap(game);
}