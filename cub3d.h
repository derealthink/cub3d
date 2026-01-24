/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:29:22 by aielo             #+#    #+#             */
/*   Updated: 2026/01/07 16:58:14 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>
# include "X11/keysym.h"
# include "libft.h"

//# define IMG_PXL 32
//# define TRANSPARENT_COLOR 0xFF00FF
# define WND_NAME "cub3d"
/*
typedef struct s_tile
{
	int		x;
	int		y;
	char	character;
	bool	is_player;
	bool	is_space;
	bool	is_wall;
	bool	has_coin;
	bool	has_villain;
	bool	is_exit;
	bool	flood_check;
}	t_tile;

typedef struct s_check
{
	size_t	width;
	size_t	height;
	bool	no_rectangle;
	size_t	coins;
	size_t	start;
	size_t	villain;
	size_t	exit;
	size_t	start_x;
	size_t	start_y;
	size_t	coins_check;
	size_t	exit_check;
}	t_check;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_player
{
	size_t	x;
	size_t	y;
//vector?
}	t_player;

typedef struct s_map
{
	t_tile		**map;
	t_img		sprite_player; //sprite N
	t_img		sprite_space; //sprite S
	t_img		sprite_wall; //sprite E
	t_img		sprite_coin; //sprite W
	t_img		sprite_villain;
	t_img		sprite_exit;
	t_player	player;
	size_t		width;
	size_t		height;
	size_t		total_coins;
	size_t		collect_coins;
	size_t		start_x;
	size_t		start_y;
	size_t		start_direction;
//	int			moves;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img_buffer;
}	t_map;
*/

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	**cc;
	char	**fc;
}	t_config;

typedef	struct s_map
{
	char	**grid;
}	t_map;

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
	struct s_list	*next;
	int				len;
	int				valid;
}	t_ulines;


typedef struct	s_cube
{
	t_config	*id;
	char		**map;
}	t_cube;


int 	is_empty_line(char *line);
int 	is_space(char c);
char    **call_map(char *file);
char    **prep_id(char **map);
t_list	*parse_to_list(char *file);
void	free_list(t_list *head);
void	free_map(char **map);

#endif
