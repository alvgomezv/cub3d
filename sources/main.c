#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../cub3d.h"

void 	fill_map_data(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		printf("North texture: %s", line + i + 2);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		printf("South texture: %s", line + i + 2);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		printf("West texture: %s", line + i + 2);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		printf("East texture: %s", line + i + 2);
	else if (line[i] == 'F')
		printf("Floor color: %s", line + i + 1);
	else if (line[i] == 'C')
		printf("Ceiling color: %s", line + i + 1);
	else if (line[i] == '1')
		printf("Map\n");
}

void	cub_parsing(char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit (1);
	}
	line = get_next_line(fd);
	
	while (line)
	{
		//printf("%s", line);
		fill_map_data(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);

	close(fd);
}

char	*initial_checks(int argc, char *argv)
{	
	if (argc != 2 || argv[ft_strlen(argv) - 1] != 'b'
		|| argv[ft_strlen(argv) - 2] != 'u'
		|| argv[ft_strlen(argv) - 3] != 'c'
		|| argv[ft_strlen(argv) - 4] != '.')
	{
		perror("Error, must include a map (.cub file)");
		exit (1);
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	cub_parsing(initial_checks(argc, argv[1]));
	return (0);
}
