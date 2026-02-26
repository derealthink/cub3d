#include "parsing.h"
#include "utils.h"

static int	has_space_neighbor(char **map, int width, int height, int x, int y)
{
	int	nx;
	int	ny;

	nx = x + 1;
	ny = y;
	if (nx < 0 || ny < 0 || ny >= height || nx >= width)
		return (1);
	if (map[ny][nx] == ' ')
		return (1);
	nx = x - 1;
	if (nx < 0 || ny < 0 || ny >= height || nx >= width)
		return (1);
	if (map[ny][nx] == ' ')
		return (1);
	nx = x;
	ny = y + 1;
	if (nx < 0 || ny < 0 || ny >= height || nx >= width)
		return (1);
	if (map[ny][nx] == ' ')
		return (1);
	ny = y - 1;
	if (nx < 0 || ny < 0 || ny >= height || nx >= width)
		return (1);
	if (map[ny][nx] == ' ')
		return (1);
	return (0);
}

static int	all_zero_enclosed(char **map, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == '0'
				&& has_space_neighbor(map, width, height, x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static char	**copy_map(char **map, int height)
{
	char	**dup;
	int		i;

	dup = malloc(sizeof(char *) * (height + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < height)
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup[i])
		{
			free_map(dup);
			return (NULL);
		}
		i++;
	}
	dup[height] = NULL;
	return (dup);
}

int	flood_fill(t_data *game)
{
	char	**map_copy;

	printf("entereing floodfill\n");
	if (!game || !game->map)
		return (0);
	if (game->map_height <= 0 || game->map_width <= 0)
		return (0);
	map_copy = copy_map(game->map, game->map_height);
	if (!map_copy)
		return (0);
	if (!all_zero_enclosed(map_copy, game->map_width, game->map_height))
	{
		free_map(map_copy);
		error_msg(ERR_FLOOD, 1);
		return (0);
	}
	free_map(map_copy);
	return (1);
}
