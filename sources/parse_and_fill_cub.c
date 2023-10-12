#include "../cub3d.h"

static void	fill_map_data(char *line, t_map *map, int fd)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		map->no_texture = fill_texture((line + i + 2), map, line);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		map->so_texture = fill_texture((line + i + 2), map, line);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		map->we_texture = fill_texture((line + i + 2), map, line);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		map->ea_texture = fill_texture((line + i + 2), map, line);
	else if (line[i] == 'F')
		fill_color(map->floor, (line + i + 1), map, line);
	else if (line[i] == 'C')
		fill_color(map->ceiling, (line + i + 1), map, line);
	else if (line[i] == '1')
		fill_cells(line, map, fd);
	else if (line[i] != '\n')
		ft_error_and_free_map(map, "Error, invalid map data", line);
	else
		free(line);
}

static void	aux_count_lines_and_columns_of_the_map(char *line,
		t_map *map, int fd)
{
	char	*new_line;

	while (line)
	{
		new_line = change_tabs_for_4_spaces(line);
		check_cells_for_errors(new_line, map);
		map->max_rows++;
		if (map->max_cols < ft_strlen(new_line))
			map->max_cols = ft_strlen(new_line);
		if (new_line)
			free(line);
		free(new_line);
		new_line = get_next_line(fd);
		line = new_line;
	}
	if (map->check == 0)
		ft_error_and_free_map(map, "Error, invalid map data", line);
}

static void	count_lines_and_columns_of_the_map(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] == '1' || line[i] == '0')
			break ;
		free(line);
		i = 0;
		line = get_next_line(fd);
	}
	aux_count_lines_and_columns_of_the_map(line, map, fd);
	close(fd);
}

void	cub_parsing(char *map_route, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map_route, O_RDONLY);
	if (fd == -1)
	{
		ft_free_map(map);
		ft_printf_fd("Error opening file\n", 2);
		exit (1);
	}
	count_lines_and_columns_of_the_map(map, fd);
	close(fd);
	fd = open(map_route, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		fill_map_data(line, map, fd);
		line = get_next_line(fd);
	}
	close(fd);
	check_all_map_data(map);
}
