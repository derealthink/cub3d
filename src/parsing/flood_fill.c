#include "parsing.h"

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
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

static int	flood_fill_rec(char **map, int width, int height, int x, int y)
{
	char	c;

	if (x < 0 || y < 0 || y >= height || x >= width)
		return (0);
	c = map[y][x];
	if (c == '1' || c == 'V')
		return (1);
	if (c == ' ')
		return (0);
	if (!(c == '0' || is_player_char(c)))
	{
		error_msg("player", 1);
		return (0);
	}
	map[y][x] = 'V';
	if (!flood_fill_rec(map, width, height, x + 1, y))
		return (0);
	if (!flood_fill_rec(map, width, height, x - 1, y))
		return (0);
	if (!flood_fill_rec(map, width, height, x, y + 1))
		return (0);
	if (!flood_fill_rec(map, width, height, x, y - 1))
		return (0);
	return (1);
}

int	flood_fill(t_data *game)
{
	int	px;
	int	py;
	char	**map_copy;
	int		ok;

	printf("entereing floodfill\n");
	if (!game || !game->map)
		return (0);
	if (game->map_height <= 0 || game->map_width <= 0)
		return (0);
	map_copy = copy_map(game->map, game->map_height);
	if (!map_copy)
		return (0);
	px = (int)game->player.pos_x;
	py = (int)game->player.pos_y;
	ok = flood_fill_rec(map_copy, game->map_width, game->map_height, px, py);
	free_map(map_copy);
	printf("exiting flood fill %d\n", ok);
	return (ok);
}
