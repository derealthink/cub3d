/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:56:25 by aielo             #+#    #+#             */
/*   Updated: 2026/01/29 01:32:43 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "configuration.h"
# include "utils.h"

int		render(t_data *game);
void	render_loop(t_data *game);
int		render_minimap(t_data *game);

#endif