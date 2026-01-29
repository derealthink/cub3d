/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:56:25 by aielo             #+#    #+#             */
/*   Updated: 2026/01/29 14:19:54 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <math.h>
# include <stdint.h>
# include <stdlib.h>
# include "cub3d.h"
# include "execution.h"
# include "configuration.h"
# include "utils.h"

int		render(t_data *game);
void	render_loop(t_data *game);
int		render_frame(t_data *game);
int		render_minimap(t_data *game);

#endif