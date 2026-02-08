/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:27:06 by aielo             #+#    #+#             */
/*   Updated: 2026/02/08 18:41:45 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	clean_exit(t_data *game, int exit_code)
{
	if (!game)
		exit(exit_code);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		mlx_loop_end(game->mlx);
		free(game->mlx);
	}
	free_data(game);
	printf("\n");
	exit(exit_code);
}

int	quit_game(t_data *game)
{
	clean_exit(game, 0);
	return (0);
}
