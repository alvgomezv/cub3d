#include "../cub3d.h"

void	print_map_cells(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->max_rows)
	{
		j = 0;
		while (j < map->max_cols)
		{
			printf("%d", map->cells[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

// t_map	*get_test_map(void) {
// 	t_map	*data;
// 	int	rows = 7;
// 	int	cols = 9;
// 	data = (t_map *)ft_calloc(1, sizeof(t_map));
// 	int	**map = (int **)malloc(rows * sizeof(int *));
// 	for (int i = 0; i < rows; i++) {
// 		map[i] = (int *)malloc(cols * sizeof(int));
// 	}
// 	int map_cells[7][9] = {
// 		{2, 1, 1, 1, 1, 1, 1, 1, 2},
// 		{2, 1, 0, 0, 1, 1, 0, 0, 1},
// 		{2, 1, 0, 0, 1, 0, 0, 0, 1},
// 		{2, 1, 0, 0, 1, 0, 0, 0, 1},
// 		{2, 1, 0, 0, 1, 1, 0, 0, 1},
// 		{2, 1, 1, 0, 0, 1, 1, 0, 2},
// 		{2, 2, 2, 1, 1, 2, 2, 2, 2}
// 	};
// 	// Copy values from map_cells to the dynamically allocated map
// 	for (int i = 0; i < rows; i++) {
// 		for (int j = 0; j < cols; j++) {
// 			map[i][j] = map_cells[i][j];
// 		}
// 	}
// 	data->cells = map;
// 	data->max_cols = cols;
// 	data->max_rows = rows;
// 	data->player = (t_player *) ft_calloc(1, sizeof(t_player));
// 	data->player->start_col = 3;
// 	data->player->start_row = 3;
// 	data->player->x = (data->player->start_col - 1) * (MM_C_SIZE + MM_C_SEP) + ((MM_C_SIZE + MM_C_SEP) / 2);
// 	data->player->y = (data->player->start_row - 1) * (MM_C_SIZE + MM_C_SEP) + ((MM_C_SIZE + MM_C_SEP) / 2);
// 	data->player->angle = M_PI_2 * 3;
// 	return data;
// }

int	main(int argc, char **argv)
{
	t_pxl	tl_minmap;
	t_map	*map;

	map = initialize_map_data();
	cub_parsing(initial_checks(argc, argv[1], map), map);
	map->mlx = mlx_init(WIN_WIDTH, WIN_HEIGTH, "Cub3d", 1);
	if (!map->mlx)
		return (1);
	// get canvas img size
	map->cam = mlx_new_image(map->mlx, VP_W, VP_H);
	if (!map->cam)
		return (1);
	
	map->N_tex = mlx_texture_to_image(map->mlx, mlx_load_png(map->no_texture));
	map->S_tex = mlx_texture_to_image(map->mlx, mlx_load_png(map->so_texture));
	map->E_tex = mlx_texture_to_image(map->mlx, mlx_load_png(map->ea_texture));
	map->W_tex = mlx_texture_to_image(map->mlx, mlx_load_png(map->we_texture));
	// get minmap img size
	map->minmap = mlx_new_image(map->mlx, map->max_cols
			* (MM_C_SIZE + MM_C_SEP), map->max_rows * (MM_C_SIZE + MM_C_SEP));
	if (!map->minmap)
		return (1);
	tl_minmap.x = MM_TL_X;
	tl_minmap.y = MM_TL_Y;
	mlx_image_to_window(map->mlx, map->minmap, 0, 0);
	mlx_image_to_window(map->mlx, map->cam, map->max_cols
			* (MM_C_SIZE + MM_C_SEP), 0);
	draw_minmap(map, &tl_minmap);
	mlx_key_hook(map->mlx, &disc_hook, map);
	mlx_loop_hook(map->mlx, cont_hook, map);
	mlx_loop(map->mlx);
	ft_free_cells(map);
	ft_free_map(map);
	mlx_terminate(map->mlx);
	return (0);
}
