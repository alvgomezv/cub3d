#include "../cub3d.h"

static char	*aux_change_tabs_for_4_spaces(char *line, int i, int j, int tabs)
{
	char	*new_line;

	new_line = (char *)ft_calloc(ft_strlen(line) + tabs * 3 + 1, sizeof(char));
	while (line[i])
	{
		if (line[i] == '\t')
		{
			new_line[j] = ' ';
			new_line[j + 1] = ' ';
			new_line[j + 2] = ' ';
			new_line[j + 3] = ' ';
			j += 4;
		}
		else
		{
			new_line[j] = line[i];
			j++;
		}
		i++;
	}
	return (new_line);
}

char	*change_tabs_for_4_spaces(char *line)
{
	int		i;
	char	*new_line;
	int		j;
	int		tabs;

	i = 0;
	j = 0;
	tabs = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			tabs++;
		i++;
	}
	i = 0;
	new_line = aux_change_tabs_for_4_spaces(line, i, j, tabs);
	return (new_line);
}

static void	fill_cells_in_map_aux(int *cells, int i, t_map *map)
{
	while (i < map->max_rows)
	{
		cells[i] = 2;
		i++;
	}
}

static void	fill_cells_in_map(char *line, int *cells, t_map *map, int y)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ')
			cells[i] = 2;
		else if (line[i] == '1')
			cells[i] = 1;
		else if (line[i] == '0')
			cells[i] = 0;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
			initialize_player(map, line[i], i, y);
		else
		{
			ft_free_cells(map);
			ft_error_and_free_map(map, "Error, invalid map data 55", line);
		}
		i++;
	}
	if (i < map->max_rows)
		fill_cells_in_map_aux(cells, i, map);
}

void	fill_cells(char *line, t_map *map, int fd)
{
	int		i;
	char	*new_line;

	i = 0;
	map->cells = (int **)ft_calloc(map->max_cols, sizeof(int *));
	while (line)
	{
		new_line = change_tabs_for_4_spaces(line);
		if (new_line)
			free(line);
		map->cells[i] = (int *)ft_calloc(map->max_rows, sizeof(int));
		fill_cells_in_map(new_line, map->cells[i], map, i);
		free(new_line);
		new_line = get_next_line(fd);
		line = new_line;
		i++;
	}
	clean_cells_from_empty_lines(map);
	print_map_cells(map);
}
