
#include "../cub3d.h"

void	apply_movement(t_map *map)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
	{
		map->player->x -= P_MOV;
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
	{
		map->player->x += P_MOV;
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
	{
		map->player->y -= P_MOV;
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
	{
		map->player->y += P_MOV;
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
	{
		map->player->angle += P_ROT;
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
	{
		map->player->angle -= P_ROT;
	}
}

void	cont_hook(void *param)
{
	t_map	*map;
	t_pxl	mm_tl_corner;

	map = (t_map *) param;
	mm_tl_corner.x = MM_TL_X;
	mm_tl_corner.y = MM_TL_Y;
	apply_movement(map);
	draw_minmap(map, &mm_tl_corner);
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
