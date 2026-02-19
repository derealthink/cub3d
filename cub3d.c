/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:12:14 by aielo             #+#    #+#             */
/*   Updated: 2026/02/19 14:26:38 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration.h"
#include "execution.h"
#include "exit.h"
#include "parsing.h"
#include "render.h"
#include "utils.h"

static void	set_player(t_data *game);

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
		return (error_msg(ERR_WRONG_INPUT, 1));
	init_data(&game);
	if (final_parser(argv[1], &game))
	{
		printf("passed final parser tests\n");
		set_player(&game);
		game.texinfo.hex_ceiling = rgb_to_hex(game.id.cc); //da spostare in parsing
		game.texinfo.hex_floor = rgb_to_hex(game.id.cf); //da spostare in parsing
		init_mlx(&game);
		printf("MLX initialized\n");
		init_textures(&game);
		printf("Textures initialized\n");
		init_texture_pixels(&game);
		printf("Texture pixels initialized\n");
		print_infos();
		check_input(&game);
		mlx_loop_hook(game.mlx, render, &game);
		mlx_loop(game.mlx);
		return (0);
	}
	return (0);
}

static void	set_player(t_data *game) // settare il player con spawn
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
				game->player.dir = 'N'; // info spawn da parsing - 
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
if (final_parser(argv[1], &game))
{
	//init_player_direction(&game); // da spostare in parse_args?
	printf("passed final parser tests\n");
	set_player_for_test(&game);
	init_mlx(&game);
	init_textures(&game);
	print_infos();
	check_input(&game);
//--DELETE!	render_frame(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	return (0);
}
	printf("Texture size: %d\n", game.texinfo.size);
	printf("Texture NORTH: %p\n", (void *)game.textures[NORTH]);
	printf("Texture SOUTH: %p\n", (void *)game.textures[SOUTH]);
	printf("Texture EAST: %p\n", (void *)game.textures[EAST]);
	printf("Texture WEST: %p\n", (void *)game.textures[WEST]);
	*/