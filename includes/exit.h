/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:33:39 by aielo             #+#    #+#             */
/*   Updated: 2026/02/13 12:38:19 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <stdio.h>
# include "libft.h"
# include "cub3d.h"

int		error_msg(char *description, int exit_code);

void	clean_exit(t_data *game, int exit_code);
int		quit_game(t_data *game);

int		free_data(t_data *game);
void	free_tab(void **tab);

#endif