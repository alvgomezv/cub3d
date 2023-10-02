#include "../cub3d.h"

int	get_cell_type_for_pxl(t_map *map, int x, int y)
{
	int	row;
	int	col;

	col = x / (MM_C_SIZE + MM_C_SEP);
	row = y / (MM_C_SIZE + MM_C_SEP);
	return (map->cells[row][col]);
}

int	circle_overlaps(t_map *map, int x_c, int y_c)
{
	float	angle;

	angle = 0;
	while (angle < 360)
	{
		if (get_cell_type_for_pxl(map, x_c + P_LINE * cos(DEG_TO_RAD(angle)),
				y_c + P_LINE * sin(DEG_TO_RAD(angle))) == wall)
			return (1);
		angle += 10;
	}
	return (0);
}

void	move_if_no_collision(t_map *map, int pxls_to_move, int move_x_axis)
{
	int	new_pos;

	if (move_x_axis)
	{
		new_pos = map->player->x + pxls_to_move;
		if (!circle_overlaps(map, new_pos, map->player->y))
			map->player->x += pxls_to_move;
	}
	else
	{
		new_pos = map->player->y + pxls_to_move;
		if (!circle_overlaps(map, map->player->x, new_pos))
			map->player->y += pxls_to_move;
	}
}
