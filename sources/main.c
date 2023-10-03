#include "../cub3d.h"

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
	printf("Player: %d, %d, %f\n", map->player->start_x,
		map->player->start_y, map->player->angle);
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
