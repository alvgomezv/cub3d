/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:46:20 by alvgomez          #+#    #+#             */
/*   Updated: 2023/10/19 18:33:40 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	normalize_angle(float angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrtf(powf(x2 - x1, 2) + powf(y2 - y1, 2)));
}

void	choose_shortest_distance(t_map *map)
{
	if (map->ray->h_dist < map->ray->v_dist)
	{
		map->ray->x = map->ray->h_x;
		map->ray->y = map->ray->h_y;
		map->ray->dist = map->ray->h_dist;
		if (map->ray->angle > M_PI)
			map->ray->wall_type = N_wall;
		else if (map->ray->angle < M_PI)
			map->ray->wall_type = S_wall;
	}
	else
	{
		map->ray->x = map->ray->v_x;
		map->ray->y = map->ray->v_y;
		map->ray->dist = map->ray->v_dist;
		if (map->ray->angle > M_PI_2 && map->ray->angle < M_PI_2 * 3)
			map->ray->wall_type = W_wall;
		else if (map->ray->angle < M_PI_2 || map->ray->angle > M_PI_2 * 3)
			map->ray->wall_type = E_wall;
	}
}

void	check_horizontal_and_vertical_lines(t_map *map)
{
	float	a_tan;
	float	ntan;
	int		depth;

	depth = 0;
	a_tan = -1 / tan(map->ray->angle);
	horizontal_lines_ray_angle_check(map, &depth, a_tan);
	horizontal_lines_depth_check(map, depth);
	depth = 0;
	ntan = -tan(map->ray->angle);
	vertical_lines_ray_angle_check(map, &depth, ntan);
	vertical_lines_depth_check(map, depth);
}

void	raycaster(t_map *map)
{
	int		num_rays;

	num_rays = 0;
	map->ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
	map->ray->angle = normalize_angle(map->player->angle - DR * FOV / 2);
	while (num_rays < FOV / RAY_DEG)
	{
		check_horizontal_and_vertical_lines(map);
		choose_shortest_distance(map);
		map->ray->iangle = normalize_angle(map->player->angle)
			- normalize_angle(map->ray->angle);
		map->ray->dist *= pow(cos(map->ray->iangle), 1);
		map->ray->iray = num_rays;
		draw_wall_rect(map, map->ray);
		num_rays++;
		map->ray->angle = normalize_angle(map->ray->angle + DR * RAY_DEG);
	}
	free(map->ray);
}
