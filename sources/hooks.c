
#include "../cub3d.h"

void	apply_movement(t_map *map)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
	{
		// fdf->img->instances[0].y += 5;
		// fdf->mov_y += 5;
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
	{
		// fdf->img->instances[0].y -= 5;
		// fdf->mov_y -= 5;
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
	{
		// fdf->img->instances[0].x += 5;
		// fdf->mov_x += 5;
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
	{
		// fdf->img->instances[0].x -= 5;
		// fdf->mov_x -= 5;
	}
}

void	cont_hook(void *param)
{
	t_map		*map;

	map = (t_map *) param;
	// draw_map(fdf);
	// apply_movement(fdf);
}

void	disc_hook(mlx_key_data_t key, void *param)
{
	t_map	*map;

	map = (t_map *) param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		// Clean everything
		mlx_close_window(map->mlx);
	}
}
