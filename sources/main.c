#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../cub3d.h"

void	ft_free_map(t_map *map)
{
	if (map->no_texture)
		free(map->no_texture);
	if (map->so_texture)
		free(map->so_texture);
	if (map->we_texture)
		free(map->we_texture);
	if (map->ea_texture)
		free(map->ea_texture);
	free(map->floor);
	free(map->ceiling);
	free(map->player);
	free(map);
}

char	*fill_texture(char *word, t_map *map, char *line)
{
	int		fd;
	char	*texture;
	char	*tmp;

	tmp = ft_strtrim(word, "\n");
	texture = ft_strtrim(tmp, " ");
	free(tmp);
	fd = open(texture, O_RDONLY);
	printf("Texture:%s\n", texture);
	if ((texture[ft_strlen(texture) - 1] != 'm'
			|| texture[ft_strlen(texture) - 2] != 'p'
			|| texture[ft_strlen(texture) - 3] != 'x'
			|| texture[ft_strlen(texture) - 4] != '.')
		|| fd == -1)
	{
		free(line);
		free(texture);
		ft_free_map(map);
		perror("Error opening texture file");
		exit (1);
	}
	close(fd);
	free(line);
	return (texture);
}

void	ft_error_and_free_map(t_map *map, char *error, char *line)
{
	free(line);
	ft_free_map(map);
	perror(error);
	exit (1);
}

int	check_before_number(char *number, t_map *map, char *line)
{
	int	i;

	i = 0;
	while (number[i] < '0' || number[i] > '9')
	{
		if (number[i] < '0' || number[i] > '9')
			ft_error_and_free_map(map, "Error, color must be a number", line);
		i++;
	}
	return (i);
}

int	check_valid_color_comma(t_map *map, char *number, char *line)
{
	int	i;
	int	color;

	i = check_before_number(number, map, line);
	while (number[i] != ' ' && number[i] != '\t' && number[i] != ',')
	{
		if (number[i] < '0' || number[i] > '9')
			ft_error_and_free_map(map, "Error, color must be a number", line);
		i++;
	}
	while (number[i] != ',')
	{
		if (!number[i] || (number[i] != ' ' && line[i] != '\t'))
			ft_error_and_free_map(map,
				"Error, colors must be separated by a comma", line);
		i++;
	}
	color = ft_atoi(number);
	if (color < 0 || color > 255)
		ft_error_and_free_map(map,
			"Error, color must be between 0 and 255", line);
	return (color);
}



int	check_valid_color(t_map *map, char *number, char *line)
{
	int	i;
	int	color;

	i = check_before_number(number, map, line);
	while (number[i] != ' ' && number[i] != '\t' && number[i] != '\n')
	{
		if (number[i] < '0' || number[i] > '9')
			ft_error_and_free_map(map, "Error, color must be a number", line);
		i++;
	}
	color = ft_atoi(number);
	while (number[i] != '\n')
	{
		if (number[i] != ' ' && number[i] != '\t')
			ft_error_and_free_map(map, "Error, color must be a number", line);
		i++;
	}
	if (color < 0 || color > 255)
		ft_error_and_free_map(map,
			"Error, color must be between 0 and 255", line);
	return (color);
}

void	fill_color(t_color *color, char *number, t_map *map, char *line)
{
	int	i;

	i = 0;
	while (number[i] == ' ' || number[i] == '\t')
		i++;
	color->r = check_valid_color_comma(map, number + i, line);
	while (number[i] != ',')
		i++;
	i++;
	while (number[i] == ' ' || number[i] == '\t')
		i++;
	color->g = check_valid_color_comma(map, number + i, line);
	while (number[i] != ',')
		i++;
	i++;
	while (number[i] == ' ' || number[i] == '\t')
		i++;
	color->b = check_valid_color(map, number + i, line);
	color->a = 0;
	printf("Color: %d, %d, %d, %d\n", color->r, color->g, color->b, color->a);
	free(line);
}

char	*aux_change_tabs_for_4_spaces(char *line, int i, int j, int tabs)
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
void	fill_cells_in_map_aux(int *cells, int i, t_map *map)
{
	while (i < map->max_x)
	{
		cells[i] = 2;
		i++;
	}
}

void	initialize_player(t_map *map, char direction, int i, int y)
{
	map->cells[y][i] = 3;
	map->player->x = 0;
	map->player->y = 0;
	if (direction == 'N')
		map->player->angle = PI / 2;
	else if (direction == 'S')
		map->player->angle = PI * 3 / 2;
	else if (direction == 'W')
		map->player->angle = PI;
	else if (direction == 'E')
		map->player->angle = 0;
	map->player->start_x = i;
	map->player->start_y = y;
}
void	ft_free_cells(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->max_y)
	{
		if (map->cells[i])
			free(map->cells[i]);
		i++;
	}
	free(map->cells);
}

void	fill_cells_in_map(char *line, int *cells, t_map *map, int y)
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
	if (i < map->max_x)
		fill_cells_in_map_aux(cells, i, map);
}

void	print_map_cells(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->max_y)
	{
		j = 0;
		while (j < map->max_x)
		{
			printf("%d", map->cells[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("Player: %d, %d, %f\n", map->player->start_x, map->player->start_y, map->player->angle);
}

void	check_cells_for_errors(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'E' && line[i] != '\t')
			ft_error_and_free_map(map, "Error, invalid map data 55", line);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
			map->check++;
		i++;
	}
	if (map->check > 1)
		ft_error_and_free_map(map, "Error, invalid map data 55", line);
}

// int	set_new_max_y(t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	x;
// 	int	new_max_y;

// 	i = 0;
// 	x = 0;
// 	map->check = 0;
// 	new_max_y = map->max_y;
// 	while (i < map->max_y)
// 	{
// 		j = 0;
// 		while (j < map->max_x)
// 		{
// 			if (map->cells[i][j] == 2)
// 				x++;
// 			j++;
// 		}
// 		if (x == map->max_x)
// 			new_max_y--;
// 		x = 0;
// 		i++;
// 	}
// 	return (new_max_y);
// }

// void	set_new_max_x(t_map *map, int new_max_y)
// {
// 	int	i;
// 	int	j;
// 	int	y;
// 	int	new_max_x;

// 	j = 0;
// 	y = 0;
// 	map->top_x = 0;
// 	new_max_x = map->max_x;
// 	while (j < map->max_x)
// 	{
// 		i = 0;
// 		while (i < map->max_y)
// 		{
// 			if (map->cells[i][j] == 2)
// 				y++;
// 			i++;
// 		}
// 		if (y == map->max_y)
// 			new_max_x--;
// 		else
// 			map->check++;
// 		if (map->check == 0)
// 			map->top_x++;
// 		y = 0;
// 		j++;
// 	}
// 	map->max_x = new_max_x;
// 	map->max_y = new_max_y;
// }

// void	clean_cells_from_empty_lines(t_map *map)
// {
// 	int	**new_cells;
// 	int	i;
// 	int	j;

// 	i = 0;
// 	set_new_max_x(map, set_new_max_y(map));
// 	//printf("New Max X: %d, New Max Y: %d\n", map->max_x, map->max_y);
// 	printf("Top X: %d\n", map->top_x);
// 	new_cells = (int **)ft_calloc(map->max_y, sizeof(int *));
// 	while (i < map->max_y)
// 	{
// 		new_cells[i] = (int *)ft_calloc(map->max_x, sizeof(int));
// 		j = 0;
// 		while (j < map->max_x)
// 		{
// 			if (map->top_x > 0)
// 				j += map->top_x;
// 			new_cells[i][j] = map->cells[i][j];
// 			j++;
// 		}
// 		i++;
// 	}
// 	ft_free_cells(map);
// 	map->cells = new_cells;
// 	print_map_cells(map);
// }

void	fill_cells(char *line, t_map *map, int fd)
{
	int		i;
	char	*new_line;

	i = 0;
	map->cells = (int **)ft_calloc(map->max_y, sizeof(int *));
	while (line)
	{
		new_line = change_tabs_for_4_spaces(line);
		if (new_line)
			free(line);
		map->cells[i] = (int *)ft_calloc(map->max_x, sizeof(int));
		fill_cells_in_map(new_line, map->cells[i], map, i);
		free(new_line);
		new_line = get_next_line(fd);
		line = new_line;
		i++;
	}
	// clean_cells_from_empty_lines(map);
	print_map_cells(map);
}

void 	fill_map_data(char *line, t_map *map, int fd)
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

t_map	*initialize_map_data(void)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		perror("Error allocating memory");
		exit (1);
	}
	map->player = (t_player *)ft_calloc(1, sizeof(t_player));
	map->ceiling = (t_color *)ft_calloc(1, sizeof(t_color));
	map->floor = (t_color *)ft_calloc(1, sizeof(t_color));
	map->ceiling->r = -1;
	map->ceiling->g = -1;
	map->ceiling->b = -1;
	map->ceiling->a = -1;
	map->floor->r = -1;
	map->floor->g = -1;
	map->floor->b = -1;
	map->floor->a = -1;
	map->max_x = 0;
	map->max_y = 0;
	map->check = 0;
	return (map);
}

void	check_all_map_data(t_map *map)
{
	if (!map->no_texture || !map->so_texture || !map->we_texture
		|| !map->ea_texture || map->floor->r == -1 || map->floor->g == -1
		|| map->floor->b == -1 || map->floor->a == -1 || map->ceiling->r == -1
		|| map->ceiling->g == -1 || map->ceiling->b == -1
		|| map->ceiling->a == -1)
	{
		ft_free_map(map);
		perror("Error, missing map data");
		exit (1);
	}
}

void	count_lines_and_columns_of_the_map(t_map *map, int fd)
{
	char	*line;
	int		i;
	char	*new_line;

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
	while (line)
	{
		new_line = change_tabs_for_4_spaces(line);
		check_cells_for_errors(new_line, map);
		map->max_y++;
		if (map->max_x < ft_strlen(new_line))
			map->max_x = ft_strlen(new_line);
		if (new_line)
			free(line);
		free(new_line);
		new_line = get_next_line(fd);
		line = new_line;

	}
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
		perror("Error opening file");
		exit (1);
	}
	count_lines_and_columns_of_the_map(map, fd);
	//map->cube = (char **)ft_calloc(map->lines, sizeof(char *));
	close(fd);
	fd = open(map_route, O_RDONLY);
	printf("Max X: %d\n", map->max_x);
	printf("Max Y: %d\n", map->max_y);
	line = get_next_line(fd);
	while (line)
	{
		fill_map_data(line, map, fd);
		line = get_next_line(fd);
	}
	close(fd);
	//check_all_map_data(map);
}

char	*initial_checks(int argc, char *argv, t_map *map)
{	
	if (argc != 2 || argv[ft_strlen(argv) - 1] != 'b'
		|| argv[ft_strlen(argv) - 2] != 'u'
		|| argv[ft_strlen(argv) - 3] != 'c'
		|| argv[ft_strlen(argv) - 4] != '.')
	{
		ft_free_map(map);
		perror("Error, must include a map (.cub file)");
		exit (1);
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = initialize_map_data();
	cub_parsing(initial_checks(argc, argv[1], map), map);
	ft_free_cells(map);
	ft_free_map(map);
	return (0);
}
