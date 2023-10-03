#include "../cub3d.h"

int	is_in_border(t_map *map, int row, int col)
{
	if (row == 0 || col == 0 || row == map->max_rows || col == map->max_cols)
		return (1);
	return (0);
}

int	**copy_cells(t_map *map)
{
	int		**copy;
	int		*copy_row;
	int		row;
	int		col;

	row = -1;
	col = -1;
	copy = (int **) ft_calloc(map->max_rows, sizeof(int *));
	while (++row < map->max_rows)
	{
		copy_row = (int *) ft_calloc(map->max_cols, sizeof(int));
		copy[row] = copy_row;
		while (++col < map->max_cols)
		{
			copy_row[col] = map->cells[row][col];
		}
		col = -1;
	}
	return (copy);
}

int	recursive_cell_check(t_map *map, int **cells, int row, int col)
{
	if (is_in_border(map, row, col) && cells[row][col] != wall)
		return (0);
	if (cells[row][col] == outside)
		return (0);
	else if (cells[row][col] == checked)
		return (1);
	else if (cells[row][col] == wall)
	{
		cells[row][col] = checked;
		return (1);
	}
	else
	{
		cells[row][col] = checked;
		return (recursive_cell_check(map, cells, row - 1, col)
			&& recursive_cell_check(map, cells, row, col - 1)
			&& recursive_cell_check(map, cells, row + 1, col)
			&& recursive_cell_check(map, cells, row, col + 1));
	}
}

int	is_map_closed(t_map *map)
{
	int	**cells;
	int	is_closed;

	if (is_in_border(map, map->player->start_row, map->player->start_col))
		return (0);
	cells = copy_cells(map);
	is_closed = recursive_cell_check(map, cells, \
			map->player->start_row, map->player->start_col);
	// free map
	return (is_closed);	
}


