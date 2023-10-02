#include "../cub3d.h"

void	choose_square_to_draw(t_map *map, t_pxl *tl_corner, int x, int y)
{
	if (map->cells[y][x] == empty)
		tl_corner->color = int_to_color(MM_EMPTY_COLOR);
	else if (map->cells[y][x] == wall)
		tl_corner->color = int_to_color(MM_WALL_COLOR);
	if (map->cells[y][x] != outside)
	{
		draw_square(map->minmap, tl_corner, MM_C_SIZE, tl_corner->color);
		free(tl_corner->color);
	}
}

void	clean_minmap_background(t_map *map)
{
	unsigned int	i;

	i = -1;
	while (++i < map->minmap->height * map->minmap->width * 4)
		map->minmap->pixels[i] = 0;
}

void	draw_minmap(t_map *map, t_pxl *tl_corner)
{
	int		orig_x;
	int		x;
	int		y;

	x = -1;
	y = -1;
	orig_x = tl_corner->x;
	clean_minmap_background(map);
	while (++y < map->max_rows)
	{
		while (++x < map->max_cols)
		{
			choose_square_to_draw(map, tl_corner, x, y);
			tl_corner->x += MM_C_SIZE + MM_C_SEP;
		}
		x = -1;
		tl_corner->x = orig_x;
		tl_corner->y += MM_C_SIZE + MM_C_SEP;
	}
	draw_player(map);
}

void	draw_player(t_map *m)
{
	t_pxl	tl_player_sq;
	t_pxl	line_pxl1;
	t_pxl	line_pxl2;

	tl_player_sq.x = m->player->x - P_SQ / 2;
	tl_player_sq.y = m->player->y - P_SQ / 2;
	tl_player_sq.color = int_to_color(P_COLOR);
	draw_square(m->minmap, &tl_player_sq, P_SQ, tl_player_sq.color);
	line_pxl1.x = m->player->x;
	line_pxl1.y = m->player->y;
	line_pxl2.x = m->player->x + P_LINE * cos(m->player->angle);
	line_pxl2.y = m->player->y + P_LINE * sin(m->player->angle);
	draw_line(m->minmap, &line_pxl1, &line_pxl2, tl_player_sq.color);
	free(tl_player_sq.color);
}
