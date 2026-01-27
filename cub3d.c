/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:12:14 by aielo             #+#    #+#             */
/*   Updated: 2026/01/27 14:20:00 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration.h"
#include "execution.h"
#include "exit.h"
#include "parsing.h"
#include "render.h"
#include "utils.h"

	static void	set_player_for_test(t_player *player);

int main(int argc, char **argv)
{
	(void) argv;
	t_data  game;

	if (argc != 2)
		return (error_msg(ERR_WRONG_INPUT, 1));
	init_data(&game);
//	if (parse_args(&game, argv) != 0)
//		return (1);
game.map = call_map(argv[1]);
set_player_for_test(&game.player);
init_player_direction(&game); // in parse_args

	init_mlx(&game);
	print_infos();
	check_input(&game);

	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	return (0);
}

static void	set_player_for_test(t_player *player)
{
	player->dir = 'N';
	player->pos_x = 15.0;
	player->pos_y = 15.0;
}