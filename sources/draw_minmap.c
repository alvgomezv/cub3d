/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:44:37 by alvgomez          #+#    #+#             */
/*   Updated: 2023/10/18 11:44:38 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	choose_square_to_draw(t_map *map, t_pxl *tl_corner, int irow, int icol)
{
	t_color	*color;

	if (map->cells[irow][icol] == empty)
		color = int_to_color(MM_EMPTY_COLOR);
	else if (map->cells[irow][icol] == wall)
		color = int_to_color(MM_WALL_COLOR);
	if (map->cells[irow][icol] != outside)
	{
		draw_square(map->minmap, tl_corner, SQ_SIZE, color);
		// free(tl_corner->color);
	}
}

void	clean_img(mlx_image_t *img)
{
	unsigned int	i;

	i = -1;
	while (++i < img->height * img->width * 4)
		img->pixels[i] = 0;
}

void	draw_minmap(t_map *map)
{
	t_pxl	pxl;
	int		irow;
	int		icol;

	irow = -1;
	icol = -1;
	ft_bzero(&pxl, sizeof(t_pxl));
	clean_img(map->minmap);
	while (++irow < map->max_rows)
	{
		while (++icol < map->max_cols)
		{
			choose_square_to_draw(map, &pxl, irow, icol);
			pxl.x += SQ_SIZE * MM_SCALE;
		}
		icol = -1;
		pxl.x = 0;
		pxl.y += SQ_SIZE * MM_SCALE;
	}
}

void	draw_player(t_map *m)
{
	t_pxl	player_center;
	t_pxl	line_pxl2;

	clean_img(m->player_img);
	player_center.x = P_W / 2;
	player_center.y = P_H / 2;
	player_center.color = int_to_color(P_COLOR);
	draw_circle(m->player_img, &player_center, P_RADIUS, player_center.color);
	line_pxl2.x = player_center.x + P_LINE * cos(m->player->angle);
	line_pxl2.y = player_center.y + P_LINE * sin(m->player->angle);
	draw_line(m->player_img, &player_center, &line_pxl2, player_center.color);
	free(player_center.color);
}
