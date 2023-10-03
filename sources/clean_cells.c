#include "../cub3d.h"

static int	set_new_max_y(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	new_max_y;

	i = 0;
	x = 0;
	map->check = 0;
	new_max_y = map->max_y;
	while (i < map->max_y)
	{
		j = 0;
		while (j < map->max_x)
		{
			if (map->cells[i][j] == 2)
				x++;
			j++;
		}
		if (x == map->max_x)
			new_max_y--;
		x = 0;
		i++;
	}
	return (new_max_y);
}

static void	aux_set_new_max_x(t_map *map, int *new_max_x, int y)
{
	if (y == map->max_y)
		*new_max_x -= 1;
	else
		map->check++;
	if (map->check == 0)
		map->top_x++;
}

static void	set_new_max_x(t_map *map, int new_max_y)
{
	int	i;
	int	j;
	int	y;
	int	new_max_x;

	j = 0;
	y = 0;
	map->top_x = 0;
	new_max_x = map->max_x;
	while (j < map->max_x)
	{
		i = 0;
		while (i < map->max_y)
		{
			if (map->cells[i][j] == 2)
				y++;
			i++;
		}
		aux_set_new_max_x(map, &new_max_x, y);
		y = 0;
		j++;
	}
	map->max_x = new_max_x;
	map->max_y = new_max_y;
}

void	clean_cells_from_empty_lines(t_map *map)
{
	int	**new_cells;
	int	i;
	int	j;
	int	x;

	i = 0;
	set_new_max_x(map, set_new_max_y(map));
	printf("New Max X: %d, New Max Y: %d\n", map->max_x, map->max_y);
	new_cells = (int **)ft_calloc(map->max_y, sizeof(int *));
	while (i < map->max_y)
	{
		new_cells[i] = (int *)ft_calloc(map->max_x, sizeof(int));
		j = 0;
		x = 0;
		if (map->top_x > 0)
			x = map->top_x;
		while (j < map->max_x)
		{
			new_cells[i][j] = map->cells[i][x];
			j++;
			x++;
		}
		i++;
	}
	ft_free_cells(map);
	map->cells = new_cells;
}
