/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:02:49 by aielo             #+#    #+#             */
/*   Updated: 2026/01/27 17:35:09 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <fcntl.h>
# include "cub3d.h"
# include "libft.h"

int 	    is_empty_line(char *line);
int 	    is_space(char c);
char        **call_map(char *file);
char        **prep_id(char **map);
t_ulines	*parse_to_list(char *file);
int get_map_height(char **map);
int get_map_width(char **map);
void	    free_list(t_ulines *head);
void    	free_map(char **map);
int         val_txt_count(t_ulines *head, t_valid *d);
int         val_cc_count(t_ulines *head, t_valid *d);
int         str_has_digit(char *s);
int         is_mapc_val(char c);
int         val_mp_count(t_ulines *head);
int         is_dig_cc(t_ulines *head);
char        **map_config(t_data *game, t_ulines *head);

#endif