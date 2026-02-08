/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:56:25 by aielo             #+#    #+#             */
/*   Updated: 2026/02/08 18:17:45 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <math.h>
# include <stdint.h>
# include <stdlib.h>
# include "cub3d.h"
# include "execution.h"
# include "exit.h"
# include "configuration.h"
# include "utils.h"

int		render(t_data *game);
//void	render_loop(t_data *game);
void	render_frame(t_data *game);
void	render_minimap(t_data *game);

void	init_texture_pixels(t_data *game);
int		raycasting(t_player *player, t_data *game);
void	frame_put_pixel(t_img *img, int x, int y, int color);
//void	minimap_put_pixel(t_data *game, int x, int y, int color);

void	draw_wireframe_column(t_data *game, t_ray *ray, int x);

#endif