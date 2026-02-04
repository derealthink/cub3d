#include "parsing.h"

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	flood_fill_rec(t_data *game, int x, int y)
{
	char	c;

	if (x < 0 || y < 0 || y >= game->map_height || x >= game->map_width)
		return (0);
	c = game->map[y][x];
	if (c == '1' || c == 'V')
		return (1);
	if (c == ' ')
		return (0);
	if (!(c == '0' || is_player_char(c)))
		return (0);
	game->map[y][x] = 'V';
	if (!flood_fill_rec(game, x + 1, y))
		return (0);
	if (!flood_fill_rec(game, x - 1, y))
		return (0);
	if (!flood_fill_rec(game, x, y + 1))
		return (0);
	if (!flood_fill_rec(game, x, y - 1))
		return (0);
	return (1);
}

int	flood_fill(t_data *game)
{
	int	px;
	int	py;

	if (!game || !game->map)
		return (0);
	if (game->map_height <= 0 || game->map_width <= 0)
		return (0);
	px = (int)game->player.pos_x;
	py = (int)game->player.pos_y;
	return (flood_fill_rec(game, px, py));
}
