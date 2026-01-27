/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:29:22 by aielo             #+#    #+#             */
/*   Updated: 2026/01/27 16:15:48 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>

# define WND_NAME "cub3d"
# define WIDTH 800
# define HEIGHT 600
# define IMG_PXL 6
# define MINI_W 300
# define MINI_H 300

# define SPEED 0.01

# define ERR_WRONG_INPUT "wrong input: ./cub3d <path/to/map.cub>"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_IMG "Could not create mlx image"

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	**cc;
	char	**cf;
}	t_config;

typedef enum e_tline
{
	NO_LINE,
	SO_LINE,
	EA_LINE,
	WE_LINE,
	CC_LINE,
	CF_LINE,
	MAP_LINE,
}	t_tline;

typedef struct s_ulines
{
	char			*line;
	t_tline			type;
	struct s_ulines	*next;
	int				len;
	int				valid;
}	t_ulines;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
//	t_mapinfo	mapinfo;
	char		**map;
	int			map_height;
	int			map_width;
	t_player	player;
	t_config	*id; //da rinominare texture_id
//	int			**texture_pixels;
//	int			**textures;
//	t_texinfo	texinfo;
//	t_ray		ray;
	t_img		minimap;
}	t_data;

#endif
