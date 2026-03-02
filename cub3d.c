/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:12:14 by aielo             #+#    #+#             */
/*   Updated: 2026/02/26 18:48:16 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration.h"
#include "execution.h"
#include "exit.h"
#include "parsing.h"
#include "render.h"
#include "utils.h"

static void	set_player(t_data *game);
//static void	print_map(char **map);

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
		return (error_msg(ERR_WRONG_INPUT, 1));
	init_data(&game);
	if (final_parser(argv[1], &game))
	{
//		printf("passed final parser tests\n");
		set_player(&game);
		game.texinfo.hex_ceiling = rgb_to_hex(game.id.cc);
		game.texinfo.hex_floor = rgb_to_hex(game.id.cf);
		init_mlx(&game);
//		printf("MLX initialized\n");
		init_textures(&game);
//		printf("Textures initialized\n");
		init_texture_pixels(&game);
//		printf("Texture pixels initialized\n");
		print_infos();
//		print_map(game.map);
		check_input(&game);
		mlx_loop_hook(game.mlx, render, &game);
		mlx_loop(game.mlx);
		return (0);
	}
	free_data(&game);
	free_config(&game);
	return (0);
}

static void	set_player(t_data *game)
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
				game->player.dir = find_player_char(game->map);
				if (game->player.dir == '0')
					error_msg(ERR_PLAYER, 1);
				init_player_direction(game);
				game->player.pos_x = x;
				game->player.pos_y = y;
			}
			x++;
		}
		y++;
	}
}
/*
static void	print_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}

}
*/