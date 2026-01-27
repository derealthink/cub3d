/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:33:39 by aielo             #+#    #+#             */
/*   Updated: 2026/01/26 16:25:43 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "libft.h"
# include "cub3d.h"

int		error_msg(char *description, int exit_code);
void	clean_exit(t_data *game, int exit_code);
int		quit_game(t_data *game);

#endif