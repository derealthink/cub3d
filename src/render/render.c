/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:54 by aielo             #+#    #+#             */
/*   Updated: 2026/01/26 18:32:32 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "execution.h"


int	render(t_data *game)
{
	game->player.has_moved = game->player.has_moved + player_move(game);
	if (game->player.has_moved == 0)
		return (0);
	render_loop(game);
	return (0);
}

/*
int render(t_data *game)
{
	// Just call player_move every frame for testing
	int moves = player_move(game);
	
	// Always render for testing
	render_loop(game);
	
	printf("MOVES: %d | pos_x:%.2f pos_y:%.2f\r", moves, 
		   game->player.pos_x, game->player.pos_y);
	fflush(stdout);
	return (0);
}
*/

void	render_loop(t_data *game)
{
	render_loop_moves(game);
}