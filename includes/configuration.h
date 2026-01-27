/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:58:38 by aielo             #+#    #+#             */
/*   Updated: 2026/01/27 15:46:55 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGURATION_H
# define CONFIGURATION_H

# include <stdlib.h>
# include "cub3d.h"
# include "exit.h"

void	init_data(t_data *game);
void	init_mlx(t_data *game);
void	init_img_data(t_img *img);
void	init_image(t_data *game, t_img *image, int width, int height);

#endif