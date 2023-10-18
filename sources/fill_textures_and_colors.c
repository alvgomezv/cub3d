/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures_and_colors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:45:31 by alvgomez          #+#    #+#             */
/*   Updated: 2023/10/18 12:42:26 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if ((texture[ft_strlen(texture) - 1] != 'g'
			|| texture[ft_strlen(texture) - 2] != 'n'
			|| texture[ft_strlen(texture) - 3] != 'p'
			|| texture[ft_strlen(texture) - 4] != '.')
		|| fd == -1 || (line[0] == 'N' && map->no_texture) || (line[0] == 'S'
			&& map->so_texture) || (line[0] == 'W' && map->we_texture)
		|| (line[0] == 'E' && map->ea_texture))
	{
		free(texture);
		ft_error_and_free_map(map, "Error, texture file must be png", line);
	}
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
	color->a = 255;
	free(line);
}
