/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:42:48 by alvgomez          #+#    #+#             */
/*   Updated: 2023/10/25 17:35:09 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	deg_rad(float angle, int to_rad)
{
	if (to_rad)
		return (angle * M_PI / 180.0);
	return (angle * 180.0 / M_PI);
}

int	get_cell_type_for_pxl(t_map *map, int x, int y)
{
	int	row;
	int	col;

	col = x / (SQ_SIZE);
	row = y / (SQ_SIZE);
	return (map->cells[row][col]);
}

int	circle_overlaps(t_map *map, int x_c, int y_c)
{
	float	angle;

	angle = 0;
	while (angle < 360)
	{
		if (get_cell_type_for_pxl(map, x_c + P_COL * cos(deg_rad(angle, 1)),
				y_c + P_COL * sin(deg_rad(angle, 1))) == wall)
			return (1);
		angle += 1;
	}
	return (0);
}

void	find_new_pos(t_map *map, int key, int *new_x, int *new_y)
{
	float	mov_x;
	float	mov_y;

	if (key == MLX_KEY_W)
	{
		mov_x = (P_MOV * cos(map->player->angle));
		mov_y = (P_MOV * sin(map->player->angle));
	}
	else if (key == MLX_KEY_S)
	{
		mov_x = -(P_MOV * cos(map->player->angle));
		mov_y = -(P_MOV * sin(map->player->angle));
	}
	else if (key == MLX_KEY_D)
	{
		mov_x = (P_MOV * -sin(map->player->angle));
		mov_y = (P_MOV * cos(map->player->angle));
	}
	else
	{
		mov_x = -(P_MOV * -sin(map->player->angle));
		mov_y = -(P_MOV * cos(map->player->angle));
	}
	*new_x = map->player->x + roundf(mov_x);
	*new_y = map->player->y + roundf(mov_y);
}

void	move_if_no_collision(t_map *map, int key)
{
	int	new_x;
	int	new_y;

	new_x = 0;
	new_y = 0;
	find_new_pos(map, key, &new_x, &new_y);
	if (!circle_overlaps(map, new_x, new_y))
	{
		map->player->x = new_x;
		map->player->y = new_y;
		map->minmap->instances->x = MM_RADIUS - (map->player->x * MM_SCALE);
		map->minmap->instances->y = MM_RADIUS - (map->player->y * MM_SCALE);
	}
}
