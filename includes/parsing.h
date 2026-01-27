/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:02:49 by aielo             #+#    #+#             */
/*   Updated: 2026/01/27 14:11:24 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <fcntl.h>
# include "cub3d.h"
# include "libft.h"

int 	is_empty_line(char *line);
int 	is_space(char c);
char    **call_map(char *file);
char    **prep_id(char **map);
t_ulines	*parse_to_list(char *file);
void	free_list(t_ulines *head);
void	free_map(char **map);

#endif