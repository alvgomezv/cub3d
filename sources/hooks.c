/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:45:41 by alvgomez          #+#    #+#             */
/*   Updated: 2023/11/01 20:03:55 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	apply_movement(t_map *map)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
		move_if_no_collision(map, MLX_KEY_A);
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		move_if_no_collision(map, MLX_KEY_D);
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
		move_if_no_collision(map, MLX_KEY_W);
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
		move_if_no_collision(map, MLX_KEY_S);
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		map->player->angle = normalize_angle(map->player->angle - P_ROT);
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->player->angle = normalize_angle(map->player->angle + P_ROT);
}

void	cont_hook(void *param)
{
	t_map	*map;
	t_pxl	mm_tl_corner;

	map = (t_map *) param;
	mm_tl_corner.x = MM_TL_X;
	mm_tl_corner.y = MM_TL_Y;
	apply_movement(map);
	draw_player(map);
	draw_camera(map);
}

void	disc_hook(mlx_key_data_t key, void *param)
{
	t_map	*map;

	map = (t_map *) param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		mlx_close_window(map->mlx);
	}
}
