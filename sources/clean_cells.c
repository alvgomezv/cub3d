#include "../cub3d.h"

static int	set_new_max_rows(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	new_max_rows;

	i = 0;
	x = 0;
	map->check = 0;
	new_max_rows = map->max_rows;
	while (i < map->max_rows)
	{
		j = 0;
		while (j < map->max_cols)
		{
			if (map->cells[i][j] == 2)
				x++;
			j++;
		}
		if (x == map->max_cols)
			new_max_rows--;
		x = 0;
		i++;
	}
	return (new_max_rows);
}

static void	aux_set_new_max_cols(t_map *map, int *new_max_cols, int y)
{
	if (y == map->max_rows)
		*new_max_cols -= 1;
	else
		map->check++;
	if (map->check == 0)
		map->top_x++;
}

static void	set_new_max_cols(t_map *map, int new_max_rows)
{
	int	i;
	int	j;
	int	y;
	int	new_max_cols;

	j = 0;
	y = 0;
	map->top_x = 0;
	new_max_cols = map->max_cols;
	while (j < map->max_cols)
	{
		i = 0;
		while (i < map->max_rows)
		{
			if (map->cells[i][j] == 2)
				y++;
			i++;
		}
		aux_set_new_max_cols(map, &new_max_cols, y);
		y = 0;
		j++;
	}
	map->max_cols = new_max_cols;
	map->max_rows = new_max_rows;
}

void	clean_cells_from_empty_lines(t_map *map)
{
	int	**new_cells;
	int	i;
	int	j;
	int	x;

	i = 0;
	set_new_max_cols(map, set_new_max_rows(map));
	new_cells = (int **)ft_calloc(map->max_rows, sizeof(int *));
	while (i < map->max_rows)
	{
		new_cells[i] = (int *)ft_calloc(map->max_cols, sizeof(int));
		j = 0;
		x = 0;
		if (map->top_x > 0)
			x = map->top_x;
		while (j < map->max_cols)
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
