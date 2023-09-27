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
	printf("Texture:%s, %d, %c\n", texture, fd, texture[ft_strlen(texture)]);
	if ((texture[ft_strlen(texture) - 1] != 'm'
		|| texture[ft_strlen(texture) - 2] != 'p'
		|| texture[ft_strlen(texture) - 3] != 'x'
		|| texture[ft_strlen(texture) - 4] != '.')
		|| fd == -1)
	{
		free(line);                                     
		ft_free_map(map);
		perror("Error opening texture file");
		exit (1);
	}
	close(fd);
	return (texture);
}

void	fill_color(t_color *color, char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	color->r = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	color->g = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	color->b = ft_atoi(line + i);
	color->a = 0;
	printf("Color: %d, %d, %d, %d\n", color->r, color->g, color->b, color->a);
}

void 	fill_map_data(char *line, t_map *map)
{
	int i;

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
	//else if (line[i] == 'F')
	//	fill_color(map->floor, (line + i + 1));
	//else if (line[i] == 'C')
	//	fill_color(map->ceiling, (line + i + 1));
	//else if (line[i] == '1')
	//	printf("Map\n");
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
	return (map);
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
	line = get_next_line(fd);
	fill_map_data(line, map);
	while (line)
	{
		//printf("%s", line);
		fill_map_data(line, map);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
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
	ft_free_map(map);
	return (0);
}
