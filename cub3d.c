/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:12:14 by aielo             #+#    #+#             */
/*   Updated: 2026/01/29 17:37:36 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration.h"
#include "execution.h"
#include "exit.h"
#include "parsing.h"
#include "render.h"
#include "utils.h"

	static void	set_player_for_test(t_data *game);

int main(int argc, char **argv)
{
	(void) argv;
	t_data  game;

	if (argc != 2)
		return (error_msg(ERR_WRONG_INPUT, 1));
	init_data(&game);
//	if (parse_args(&game, argv) != 0)
//		return (1);
/*game.map = call_map(argv[1]);
game.map_height = get_map_height(game.map);
game.map_width = get_map_width(game.map);*/
set_player_for_test(&game);
if (final_parser(argv[1], &game))
{
	//init_player_direction(&game); // da spostare in parse_args?

	init_mlx(&game);
	print_infos();
	check_input(&game);
//	render_frame(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
}
	return (0);
}

static void	set_player_for_test(t_data *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (size_t)game->map_height)
	{
		x = 0;
		while (x < (size_t)game->map_width && game->map[y][x] != '\0') 
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
			{
				game->player.dir = 'N';
				init_player_direction(game);
				game->player.pos_x = x;
				game->player.pos_y = y;
			}
			x++;
		}
		y++;
	}
}
