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
	map->empty_line = 0;
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