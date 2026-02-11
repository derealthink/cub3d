#include "parsing.h"

int	get_map_height(char **map)
{
	int h;

	h = 0;
	while (map[h])
		h++;
	return h;
}

int	get_map_width(char **map)
{
	int w;
	int i;
	int len;

	printf("entering map width\n");
	w = 0;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > w)
			w = len;
		i++;
	}
	return (w);
}

int	final_parser(char *filename, t_data *game)
{
	printf("entered final parser\n");
	if (!list_to_struct(filename,game))
		return (0);
	game->map_height = get_map_height(game->map);
	game->map_width = get_map_width(game->map);
	if (!flood_fill(game))
		return (0);
	return (1);
}
