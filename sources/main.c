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

void	get_test_map(t_map *data) {
	int rows = 7;
	int cols = 9;
    int **map = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        map[i] = (int *)malloc(cols * sizeof(int));
    }
    int map_cells[7][9] = {
        {2, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 1, 0, 0, 1, 1, 0, 0, 1},
        {2, 1, 0, 0, 1, 0, 0, 0, 1},
        {2, 1, 0, 0, 1, 0, 0, 0, 1},
        {2, 1, 0, 0, 1, 1, 0, 0, 1},
        {2, 1, 1, 0, 0, 1, 1, 0, 2},
        {2, 2, 2, 1, 1, 2, 2, 2, 2}
    };
    // Copy values from map_cells to the dynamically allocated map
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            map[i][j] = map_cells[i][j];
        }
    }
    data->cells = map;
	data->max_cols = cols;
	data->max_rows = rows;
	data->player = (t_player *) ft_calloc(1, sizeof(t_player));
	data->player->start_col = 3;
	data->player->start_row = 3;
	data->player->x = (data->player->start_col - 1) * (MM_C_SIZE + MM_C_SEP) + ((MM_C_SIZE + MM_C_SEP) / 2);
	data->player->y = (data->player->start_row - 1) * (MM_C_SIZE + MM_C_SEP) + ((MM_C_SIZE + MM_C_SEP) / 2);
	data->player->angle = M_PI_2 * 3;
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_pxl	tl_minmap;

	get_test_map(&map);
	cub_parsing(initial_checks(argc, argv[1]));
	map.mlx = mlx_init(WIN_WIDTH, WIN_HEIGTH, "Cub3d", 1);
	if (!map.mlx)
		return (1);
	// get canvas img size
	map.canvas = mlx_new_image(map.mlx, 300, 300);
	if (!map.canvas)
		return (1);
	// get minmap img size
	map.minmap = mlx_new_image(map.mlx, map.max_cols * (MM_C_SIZE + MM_C_SEP), \
						map.max_rows * (MM_C_SIZE + MM_C_SEP));
	if (!map.minmap)
		return (1);
	tl_minmap.x = MM_TL_X;
	tl_minmap.y = MM_TL_Y;

	mlx_image_to_window(map.mlx, map.minmap, 0, 0);
	draw_minmap(&map, &tl_minmap);

	mlx_key_hook(map.mlx, &disc_hook, &map);
	mlx_loop_hook(map.mlx, cont_hook, &map);

	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	return (0);
	return (0);
}
