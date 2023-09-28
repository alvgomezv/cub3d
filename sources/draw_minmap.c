#include "../cub3d.h"

void	draw_minmap(t_map *map, t_pxl *tl_corner)
{
	t_color	*empty_c;
	t_color	*wall_c;
	int		orig_x;
	int		x;
	int		y;

	x = -1;
	y = -1;
	orig_x = tl_corner->x;
	empty_c = int_to_color(MM_EMPTY_COLOR);
	wall_c = int_to_color(MM_WALL_COLOR);
	while (++y < map->max_y)
	{
		while (++x < map->max_x)
		{
			if (map->cells[y][x] == empty)
				draw_square(map->minmap, tl_corner, MM_C_SIZE, empty_c);
			else if (map->cells[y][x] == wall)
				draw_square(map->minmap, tl_corner, MM_C_SIZE, wall_c);
			tl_corner->x += MM_C_SIZE + MM_C_SEP;
		}
		x = -1;
		tl_corner->x = orig_x;
		tl_corner->y += MM_C_SIZE + MM_C_SEP;
	}
}
