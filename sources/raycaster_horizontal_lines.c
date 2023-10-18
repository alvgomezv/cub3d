/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_horizontal_lines.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:46:13 by alvgomez          #+#    #+#             */
/*   Updated: 2023/10/18 11:46:14 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	keep_variables_inside_map(t_map *map)
{
	while (map->ray->map_x > map->max_cols - 1)
		map->ray->map_x--;
	while (map->ray->map_x < 0)
		map->ray->map_x++;
	while (map->ray->map_y > map->max_rows - 1)
		map->ray->map_y--;
	while (map->ray->map_y < 0)
		map->ray->map_y++;
}

void	horizontal_lines_ray_angle_check(t_map *map, int *depth, float a_tan)
{
	if (map->ray->angle == 0 || map->ray->angle == (float)M_PI)
	{
		map->ray->y = map->player->y;
		map->ray->x = map->player->x;
		map->ray->h_y = 10000;
		map->ray->h_x = 10000;
		map->ray->h_dist = 10000;
		*depth = 30;
	}
	else if (map->ray->angle > M_PI)
	{
		map->ray->y = (map->player->y / SQ_SIZE) * SQ_SIZE - 0.0001;
		map->ray->x = (map->player->y - map->ray->y) * a_tan + map->player->x;
		map->ray->y_offset = -SQ_SIZE;
		map->ray->x_offset = -map->ray->y_offset * a_tan;
	}
	else if (map->ray->angle < M_PI)
	{
		map->ray->y = (map->player->y / SQ_SIZE) * SQ_SIZE + SQ_SIZE;
		map->ray->x = (map->player->y - map->ray->y) * a_tan + map->player->x;
		map->ray->y_offset = SQ_SIZE;
		map->ray->x_offset = -map->ray->y_offset * a_tan;
	}
}

void	horizontal_lines_depth_check(t_map *map, int depth)
{
	while (depth < 30)
	{
		map->ray->map_x = (map->ray->x / SQ_SIZE);
		map->ray->map_y = (map->ray->y / SQ_SIZE);
		keep_variables_inside_map(map);
		map->ray->map_pos = map->cells[map->ray->map_y][map->ray->map_x];
		if (map->ray->map_pos > 0
			&& map->cells[map->ray->map_y][map->ray->map_x] == 1)
		{
			map->ray->h_x = map->ray->x;
			map->ray->h_y = map->ray->y;
			map->ray->h_dist = distance_between_points(map->player->x,
					map->player->y, map->ray->h_x, map->ray->h_y);
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
