/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:58:38 by aielo             #+#    #+#             */
/*   Updated: 2026/01/26 19:31:22 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <math.h>
# include <stdbool.h>
# include <X11/X.h>
# include "X11/keysym.h"
# include "exit.h"
# include "cub3d.h"

void	check_input(t_data *game);
int		player_move(t_data *game);
int		player_rotate(t_data *game, int rotate);
int		is_valid_move(t_data *game, double x, double y);
void	init_player_direction(t_data *game);


#endif