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

	w = 0;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > w)
			w = len;
		i++;
	}
	return (w);//stripped of newlines
}


