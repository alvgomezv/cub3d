/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:46:04 by alvgomez          #+#    #+#             */
/*   Updated: 2023/10/26 19:06:59 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_map_cells(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->max_rows)
	{
		j = 0;
		while (j < map->max_cols)
		{
			printf("%d", map->cells[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	load_textures(t_map *map)
{
	map->texture = mlx_load_png(map->no_texture);
	if (!map->texture)
		return (1);
	map->n_tex = mlx_texture_to_image(map->mlx, map->texture);
	if (!map->n_tex)
		return (1);
	free(map->texture);
	map->texture = mlx_load_png(map->so_texture);
	if (!map->texture)
		return (1);
	map->s_tex = mlx_texture_to_image(map->mlx, map->texture);
	if (!map->s_tex)
		return (1);
	free(map->texture);
	map->texture = mlx_load_png(map->ea_texture);
	if (!map->texture)
		return (1);
	map->e_tex = mlx_texture_to_image(map->mlx, map->texture);
	if (!map->e_tex)
		return (1);
	free(map->texture);
	map->texture = mlx_load_png(map->we_texture);
	if (!map->texture)
		return (1);
	map->w_tex = mlx_texture_to_image(map->mlx, map->texture);
	if (!map->w_tex)
		return (1);
	free(map->texture);
	return (0);
}

void	load_mlxs(t_map	*map)
{
	map->mlx = mlx_init(VP_W, VP_H, "Cub3d", 1);
	if (!map->mlx)
		ft_error_and_free_all(map, "Error\nMlx failed to initialize");
	map->cam = mlx_new_image(map->mlx, VP_W, VP_H);
	if (!map->cam)
		ft_error_and_free_all(map, "Error\nMlx failed to initialize");
	if (load_textures(map))
		ft_error_and_free_all(map, "Error\nMlx failed to initialize");
	map->minmap = mlx_new_image(map->mlx, map->max_cols
			* SQ_SIZE * MM_SCALE, map->max_rows * SQ_SIZE * MM_SCALE);
	if (!map->minmap)
		ft_error_and_free_all(map, "Error\nMlx failed to initialize");
	map->player_img = mlx_new_image(map->mlx, P_W, P_H);
	if (!map->player_img)
		ft_error_and_free_all(map, "Error\nMlx failed to initialize");
	mlx_image_to_window(map->mlx, map->minmap, MM_RADIUS
		- (map->player->x * MM_SCALE), MM_RADIUS - (map->player->y * MM_SCALE));
	mlx_image_to_window(map->mlx, map->player_img,
		MM_RADIUS - P_W / 2, MM_RADIUS - P_H / 2);
	mlx_image_to_window(map->mlx, map->cam, VP_TL_X, VP_TL_Y);
}

void leaks(void)
{
	system("leaks -q cub3d");
}

int	main(int argc, char **argv)
{
	t_map	*map;

	atexit(leaks);
	map = initialize_map_data();
	cub_parsing(initial_checks(argc, argv[1], map), map);
	load_mlxs(map);
	draw_minmap(map);
	draw_player(map);
	draw_camera(map);
	mlx_key_hook(map->mlx, &disc_hook, map);
	mlx_loop_hook(map->mlx, cont_hook, map);
	mlx_loop(map->mlx);
	ft_free_cells(map, map->max_rows);
	ft_free_map(map);
	mlx_terminate(map->mlx);
	return (0);
}
