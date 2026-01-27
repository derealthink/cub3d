/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:31:49 by aielo             #+#    #+#             */
/*   Updated: 2026/01/27 15:00:46 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include "cub3d.h"
# include "libft.h"

typedef struct s_data	t_data;

void	print_infos(void);
int		render_loop_moves(t_data *param);

#endif