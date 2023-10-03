#include "../cub3d.h"

#include <math.h>

float	normalize_angle(float angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void	raycaster(t_map *map)
{
	int		i;
	float	a_tan;
	int		num_rays;
	int		depth;
	t_pxl	*pxl_player;
	t_pxl	*pxl_ray;

	i = 0;
	num_rays = 0;
	map->ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
	map->ray->angle = normalize_angle(map->player->angle);
	while (num_rays < 1)
	{
		// check horizontal lines
		depth = 0;
		a_tan = -1 / tan(map->ray->angle);
		if (map->ray->angle > M_PI) // looking up
		{
			map->ray->y = ((int)map->player->y / MM_C_SIZE) * MM_C_SIZE - 0.0001;
			map->ray->x = (map->player->y - map->ray->y) * a_tan + map->player->x;
			map->ray->y_offset = -MM_C_SIZE;
			map->ray->x_offset = -map->ray->y_offset * a_tan;
			printf("up ray: angle %f, x %f, y %f\n", map->ray->angle, map->ray->x, map->ray->y);
		}
		else if (map->ray->angle < M_PI) // looking down
		{
			map->ray->y = ((int)map->player->y / MM_C_SIZE) * MM_C_SIZE + MM_C_SIZE;
			map->ray->x = (map->player->y - map->ray->y) * a_tan + map->player->x;
			map->ray->y_offset = MM_C_SIZE;
			map->ray->x_offset = -map->ray->y_offset * a_tan;
			printf("down ray: angle %f, x %f, y %f\n", map->ray->angle, map->ray->x, map->ray->y);
		}
		else if (map->ray->angle == 0 || map->ray->angle == M_PI) // looking straight left or right
		{
			map->ray->y = map->player->y;
			map->ray->x = map->player->x;
			depth = 8;
		}
		while (depth < 8)
		{
			map->ray->map_x = (int)map->ray->x / MM_C_SIZE;
			map->ray->map_y = (int)map->ray->y / MM_C_SIZE;
			map->ray->map_pos = map->cells[map->ray->map_y][map->ray->map_x];
			printf("map_pos: %d\n", map->ray->map_pos);
			if (map->ray->map_pos > 0 && map->ray->map_pos < map->ray->map_x * map->ray->map_y && map->cells[map->ray->map_y][map->ray->map_x] == 1)
				depth = 8; // hit a wall
			else
			{
				map->ray->x += map->ray->x_offset;
				map->ray->y += map->ray->y_offset;
				depth++;
			}
		}
		pxl_player = (t_pxl *)ft_calloc(1, sizeof(t_pxl));
		pxl_player->x = map->player->x;
		pxl_player->y = map->player->y;
		pxl_player->color = int_to_color(R_COLOR);
		pxl_ray = (t_pxl *)ft_calloc(1, sizeof(t_pxl));
		pxl_ray->x = map->ray->x;
		pxl_ray->y = map->ray->y;
		pxl_ray->color = int_to_color(R_COLOR);
		//printf ("raycaster: ray %d: angle %f, x %f, y %f\n", num_rays, map->ray->angle, map->ray->x, map->ray->y);
		draw_line(map->minmap, pxl_player, pxl_ray, int_to_color(R_COLOR));
		num_rays++;
	}
}
