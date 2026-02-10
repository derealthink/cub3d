/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:17:57 by aielo             #+#    #+#             */
/*   Updated: 2026/01/30 00:10:22 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	frame_put_pixel(t_img *img, int x, int y, int color)
{
	char	*pxl;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	pxl = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)pxl = (unsigned int)color;
}
/*
void	minimap_put_pixel(t_data *game, int x, int y, int color)
{
	char	*pxl;

	if (x < 0 || x >= game->map_width * IMG_PXL
		|| y < 0 || y >= game->map_height * IMG_PXL)
		return ;
	pxl = game->minimap.addr + (y * game->minimap.line_length
			+ x * (game->minimap.bits_per_pixel / 8));
	*(unsigned int *)pxl = (unsigned int)color;
}
*/
// test, da eliminare

void	draw_wireframe_column(t_data *game, t_ray *ray, int x)
{
	int y;

	// 1. Draw the top boundary point
	frame_put_pixel(&game->frame, x, ray->draw_start, 0x8ba0a4);
	// 2. Draw the bottom boundary point
	frame_put_pixel(&game->frame, x, ray->draw_end, 0x8ba0a4);
	// 3. Optional: Draw vertical lines at grid intersections 
	y = ray->draw_start;	
	while (y <= ray->draw_end)
	{
		if (x % 20 == 0) // Adjust frequency of vertical bars
			frame_put_pixel(&game->frame, x, y, 0x8ba0a4);
		y++;
	}
}
