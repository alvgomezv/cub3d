#include "../cub3d.h"

void	check_cells_for_errors(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n')
		map->empty_line++;
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
		if (map->empty_line > 0 && line[i] != ' ')
			ft_error_and_free_map(map, "Error, invalid map data 30", line);
		i++;
	}
	if (map->check > 1)
		ft_error_and_free_map(map, "Error, invalid map data 55", line);
}

void	ft_error_and_free_map(t_map *map, char *error, char *line)
{
	free(line);
	ft_free_map(map);
	perror(error);
	exit (1);
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