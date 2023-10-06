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

void	horizontal_lines_ray_angle_check(t_map *map, int *depth, float a_tan)
{
	if (map->ray->angle == 0 || map->ray->angle == (float)M_PI) // looking straight left or right
		{
			map->ray->y = map->player->y;
			map->ray->x = map->player->x;
			map->ray->h_y = 10000;
			map->ray->h_x = 10000;
			map->ray->h_dist = 10000;
			*depth = 30;
		}
		else if (map->ray->angle > M_PI) // looking up
		{
			map->ray->y = (map->player->y / MM_C_SIZE) * MM_C_SIZE - 0.0001;
			map->ray->x = (map->player->y - map->ray->y) * a_tan + map->player->x;
			map->ray->y_offset = -MM_C_SIZE;
			map->ray->x_offset = -map->ray->y_offset * a_tan;
		}
		else if (map->ray->angle < M_PI) // looking down
		{
			map->ray->y = (map->player->y / MM_C_SIZE) * MM_C_SIZE + MM_C_SIZE;
			map->ray->x = (map->player->y - map->ray->y) * a_tan + map->player->x;
			map->ray->y_offset = MM_C_SIZE;
			map->ray->x_offset = -map->ray->y_offset * a_tan;
		}
}

void	horizontal_lines_depth_check(t_map *map, int depth)
{
	while (depth < 30)
	{
		map->ray->map_x = (map->ray->x / MM_C_SIZE);
		//temporal fix
		while (map->ray->map_x > map->max_cols - 1)
			map->ray->map_x--;
		while (map->ray->map_x < 0)
			map->ray->map_x++;
		map->ray->map_y = (map->ray->y / MM_C_SIZE);
		//temporal fix
		while (map->ray->map_y > map->max_rows - 1)
			map->ray->map_y--;
		while (map->ray->map_y < 0)
			map->ray->map_y++;
		map->ray->map_pos = map->cells[map->ray->map_y][map->ray->map_x];
		// printf("map_x: %d, map_y: %d, map_pos: %d\n", map->ray->map_x, map->ray->map_y, map->ray->map_pos);
		if (map->ray->map_pos > 0 && map->cells[map->ray->map_y][map->ray->map_x] == 1)
		{
			map->ray->h_x = map->ray->x;
			map->ray->h_y = map->ray->y;
			map->ray->h_dist = distance_between_points(map->player->x, map->player->y, map->ray->h_x, map->ray->h_y);
			// printf("hit a wall\n");
			break; // hit a wall
		}	
		else
		{
			map->ray->x += map->ray->x_offset;
			map->ray->y += map->ray->y_offset;
			depth++;
		}
	}
}

void	print_ray(t_map *map, int color)
{
	t_pxl	*pxl_player;
	t_pxl	*pxl_ray;

	pxl_player = (t_pxl *)ft_calloc(1, sizeof(t_pxl));
	pxl_player->x = map->player->x;
	pxl_player->y = map->player->y;
	pxl_player->color = int_to_color(color);
	pxl_ray = (t_pxl *)ft_calloc(1, sizeof(t_pxl));
	pxl_ray->x = map->ray->x;
	pxl_ray->y = map->ray->y;
	pxl_ray->color = int_to_color(color);
	draw_line(map->minmap, pxl_player, pxl_ray, int_to_color(color));
}

void	vertical_lines_ray_angle_check(t_map *map, int *depth, float ntan)
{
	if (map->ray->angle == (float)M_PI_2 || map->ray->angle == (float)(M_PI_2 * 3)) // looking straight up or down
	{
		map->ray->y = map->player->y;
		map->ray->x = map->player->x;
		map->ray->v_y = 10000;
		map->ray->v_x = 10000;
		map->ray->v_dist = 10000;
		*depth = 30;
	}
	else if (map->ray->angle > M_PI_2 && map->ray->angle < M_PI_2 * 3 ) // looking left
	{
		map->ray->x = (map->player->x / MM_C_SIZE) * MM_C_SIZE - 0.0001;
		map->ray->y = (map->player->x - map->ray->x) * ntan + map->player->y;
		map->ray->x_offset = -MM_C_SIZE;
		map->ray->y_offset = -map->ray->x_offset * ntan;
	}
	else if (map->ray->angle < M_PI_2 || map->ray->angle > M_PI_2 * 3) // looking right
	{
		map->ray->x = (map->player->x / MM_C_SIZE) * MM_C_SIZE + MM_C_SIZE;
		map->ray->y = (map->player->x - map->ray->x) * ntan + map->player->y;
		map->ray->x_offset = MM_C_SIZE;
		map->ray->y_offset = -map->ray->x_offset * ntan;
	}
}

void	vertical_lines_depth_check(t_map *map, int depth)
{
	while (depth < 30)
	{
		map->ray->map_x = ((int)map->ray->x / MM_C_SIZE);
		//temporal fix
		while (map->ray->map_x > map->max_cols - 1)
			map->ray->map_x--;
		while (map->ray->map_x < 0)
			map->ray->map_x++;
		map->ray->map_y = ((int)map->ray->y / MM_C_SIZE);
		//temporal fix
		while (map->ray->map_y > map->max_rows - 1)
			map->ray->map_y--;
		while (map->ray->map_y < 0)
			map->ray->map_y++;
		map->ray->map_pos = map->cells[map->ray->map_y][map->ray->map_x];
		if (map->ray->map_pos > 0 && map->cells[map->ray->map_y][map->ray->map_x] == 1)
		{
			map->ray->v_x = map->ray->x;
			map->ray->v_y = map->ray->y;
			map->ray->v_dist = distance_between_points(map->player->x, map->player->y, map->ray->v_x, map->ray->v_y);
			break; // hit a wall
		}	
		else
		{
			map->ray->x += map->ray->x_offset;
			map->ray->y += map->ray->y_offset;
			depth++;
		}
	}
}

void	choose_shortest_distance(t_map *map)
{
	if (map->ray->h_dist < map->ray->v_dist)
	{
		map->ray->x = map->ray->h_x;
		map->ray->y = map->ray->h_y;
		map->ray->distance = map->ray->h_dist;
	}
	else
	{
		map->ray->x = map->ray->v_x;
		map->ray->y = map->ray->v_y;
		map->ray->distance = map->ray->v_dist;
	}
}

void	raycaster(t_map *map)
{
	float	a_tan;
	float	ntan;
	int		num_rays;
	int		depth;

	num_rays = 0;
	map->ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
	map->ray->angle = normalize_angle(map->player->angle - DR * FOV / 2);
	while (num_rays < FOV * RAY_DEG)
	{
		// check horizontal lines
		depth = 0;
		a_tan = -1 / tan(map->ray->angle);
		horizontal_lines_ray_angle_check(map, &depth, a_tan);
		horizontal_lines_depth_check(map, depth);
		
		// check vertical lines
		depth = 0;
		ntan = -tan(map->ray->angle);
		vertical_lines_ray_angle_check(map, &depth, ntan);
		vertical_lines_depth_check(map, depth);
		
		choose_shortest_distance(map);
		print_ray(map, 0xFF00FFFF);

		// fix fish eye effect
		map->ray->cos_angle = normalize_angle(map->player->angle - map->ray->angle);
		map->ray->distance *= cos(map->ray->cos_angle);

		// Draw 3D walls 
		

		num_rays++;
		map->ray->angle = normalize_angle(map->ray->angle + DR);
	}
	free(map->ray);
}
