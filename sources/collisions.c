/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:42:48 by alvgomez          #+#    #+#             */
/*   Updated: 2023/10/18 19:18:41 by fgomez-d         ###   ########.fr       */
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

void	move_if_no_collision(t_map *map, int key)
{
	int	new_x;
	int	new_y;

	if (key == MLX_KEY_W)
	{
		new_x = (double)map->player->x + floor((double)P_MOV * cos(map->player->angle));
		new_y = (double)map->player->y + floor((double)P_MOV * sin(map->player->angle));
	}
	else if (key == MLX_KEY_S)
	{
		new_x = (double)map->player->x - floor((double)P_MOV * cos(map->player->angle));
		new_y = (double)map->player->y - floor((double)P_MOV * sin(map->player->angle));
	}
	else if (key == MLX_KEY_D)
	{
		new_x = (double)map->player->x + ceil((double)P_MOV * cos(normalize_angle(map->player->angle + M_PI_2)));
		new_y = (double)map->player->y + ceil((double)P_MOV * sin(normalize_angle(map->player->angle + M_PI_2)));
	}
	else
	{
		new_x = (double)map->player->x - ceil((double)P_MOV * cos(normalize_angle(map->player->angle + M_PI_2)));
		new_y = (double)map->player->y - ceil((double)P_MOV * sin(normalize_angle(map->player->angle + M_PI_2)));
	}
	if (!circle_overlaps(map, new_x, new_y))
	{
		map->player->x = new_x;
		map->player->y = new_y;
		map->minmap->instances->x = MM_RADIUS - (map->player->x * MM_SCALE);
		map->minmap->instances->y = MM_RADIUS - (map->player->y * MM_SCALE);
	}
}
