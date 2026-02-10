/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:31:49 by aielo             #+#    #+#             */
/*   Updated: 2026/01/29 01:47:25 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include "cub3d.h"
# include "libft.h"

//typedef struct s_data	t_data; questo causava un errore

void	print_infos(void);
double	get_time_ms(void);

#endif