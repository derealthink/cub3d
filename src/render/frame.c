/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:05:46 by aielo             #+#    #+#             */
/*   Updated: 2026/01/29 17:58:24 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	frame_put_pixel(t_img *img, int x, int y, int color);

int	render_frame(t_data *game)
{
	size_t	y;
	size_t	x;

	y = 0;
//	ft_memset(game->frame.addr, 0, game->frame.line_length * HEIGHT);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			frame_put_pixel(&game->frame, x, y, MAP_TRANSPARENT);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	return (0);
}

static void	frame_put_pixel(t_img *img, int x, int y, int color)
{
	char	*pxl;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	pxl = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)pxl = (unsigned int)color;
}
