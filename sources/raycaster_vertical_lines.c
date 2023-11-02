/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_vertical_lines.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:46:16 by alvgomez          #+#    #+#             */
/*   Updated: 2023/11/02 10:51:21 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	vertical_lines_ray_angle_check(t_map *map, int *depth, float ntan)
{
	map->ray->v_dist = 10000;
	if (map->ray->angle == (float)M_PI_2
		|| map->ray->angle == (float)(M_PI_2 * 3))
	{
		map->ray->y = map->player->y;
		map->ray->x = map->player->x;
		map->ray->v_y = 10000;
		map->ray->v_x = 10000;
		*depth = 30;
	}
	else if (map->ray->angle > M_PI_2 && map->ray->angle < M_PI_2 * 3)
	{
		map->ray->x = (map->player->x / (int)SQ_SIZE) * SQ_SIZE - 0.0001;
		map->ray->y = (map->player->x - map->ray->x) * ntan + map->player->y;
		map->ray->x_offset = -SQ_SIZE;
		map->ray->y_offset = -map->ray->x_offset * ntan;
	}
	else if (map->ray->angle < M_PI_2 || map->ray->angle > M_PI_2 * 3)
	{
		map->ray->x = (map->player->x / (int)SQ_SIZE) * SQ_SIZE + SQ_SIZE;
		map->ray->y = (map->player->x - map->ray->x) * ntan + map->player->y;
		map->ray->x_offset = SQ_SIZE;
		map->ray->y_offset = -map->ray->x_offset * ntan;
	}
}

void	vertical_lines_depth_check(t_map *map, int depth)
{
	while (depth < 30)
	{
		map->ray->map_x = ((int)map->ray->x / SQ_SIZE);
		map->ray->map_y = ((int)map->ray->y / SQ_SIZE);
		keep_variables_inside_map(map);
		map->ray->map_pos = map->cells[map->ray->map_y][map->ray->map_x];
		if (map->ray->map_pos > 0
			&& map->cells[map->ray->map_y][map->ray->map_x] == 1)
		{
			map->ray->v_x = map->ray->x;
			map->ray->v_y = map->ray->y;
			map->ray->v_dist = distance_between_points(map->player->x,
					map->player->y, map->ray->v_x, map->ray->v_y);
			break ;
		}
		else
		{
			map->ray->x += map->ray->x_offset;
			map->ray->y += map->ray->y_offset;
			depth++;
		}
	}
}
