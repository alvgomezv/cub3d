/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:46:07 by alvgomez          #+#    #+#             */
/*   Updated: 2023/10/25 17:50:07 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_in_border(t_map *map, int row, int col)
{
	if (row == 0 || col == 0
		|| row == map->max_rows - 1 || col == map->max_cols - 1)
		return (1);
	return (0);
}

int	is_map_closed(t_map *map)
{
	int	irow;
	int	icol;

	if (is_in_border(map, map->player->start_row, map->player->start_col))
		return (0);
	irow = -1;
	icol = -1;
	while (++irow < map->max_rows)
	{
		while (++icol < map->max_cols)
		{
			if (map->cells[irow][icol] == empty)
			{
				if (is_in_border(map, irow, icol) \
					|| map->cells[irow - 1][icol] == outside \
					|| map->cells[irow][icol - 1] == outside \
					|| map->cells[irow + 1][icol] == outside \
					|| map->cells[irow][icol + 1] == outside)
					return (0);
			}
		}
		icol = -1;
	}
	return (1);
}
