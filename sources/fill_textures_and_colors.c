#include "../cub3d.h"

char	*fill_texture(char *word, t_map *map, char *line)
{
	int		fd;
	char	*texture;
	char	*tmp;

	tmp = ft_strtrim(word, "\n");
	texture = ft_strtrim(tmp, " ");
	free(tmp);
	fd = open(texture, O_RDONLY);
	// if ((texture[ft_strlen(texture) - 1] != 'm'
	// 		|| texture[ft_strlen(texture) - 2] != 'p'
	// 		|| texture[ft_strlen(texture) - 3] != 'x'
	// 		|| texture[ft_strlen(texture) - 4] != '.')
	// 	|| fd == -1)
	// {
	// 	free(line);
	// 	free(texture);
	// 	ft_free_map(map);
	// 	perror("Error opening texture file");
	// 	exit (1);
	// }
	(void)map;
	close(fd);
	free(line);
	return (texture);
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

static int	check_valid_color_comma(t_map *map, char *number, char *line)
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

static int	check_valid_color(t_map *map, char *number, char *line)
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
	free(line);
}
