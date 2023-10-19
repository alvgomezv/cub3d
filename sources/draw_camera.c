/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:43:02 by alvgomez          #+#    #+#             */
/*   Updated: 2023/10/19 17:43:51 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_ray_calcs(t_map *map, t_ray *ray)
{
	float	pos;

	ray->rect_h = ((VP_H * SQ_SIZE) / ray->dist);
	if (ray->rect_h > VP_H)
	{
		ray->rect_h_prop = ray->rect_h / (float)VP_H;
		ray->rect_tex_y_off = (ray->rect_h - VP_H) / 2.0;
		ray->rect_h = VP_H;
	}
	else
	{
		ray->rect_h_prop = 1;
		ray->rect_tex_y_off = 0;
	}
	ray->rect_w = (VP_W / (FOV / RAY_DEG));
	ray->rect_x_off = floor(ray->rect_w * ray->iray);
	if (ray->wall_type == N_wall)
		ray->tex = map->n_tex;
	else if (ray->wall_type == S_wall)
		ray->tex = map->s_tex;
	else if (ray->wall_type == E_wall)
		ray->tex = map->e_tex;
	else
		ray->tex = map->w_tex;
	if (ray->wall_type == N_wall || ray->wall_type == S_wall)
		pos = ray->x;
	else
		pos = ray->y;
	ray->rect_tex_x_off = floor((fmod(pos, SQ_SIZE) / SQ_SIZE) * ray->tex->width);
}

void	get_tex_pxl_color(t_pxl *rect, t_ray *ray)
{
	int	y;
	int	tex_idx;

	y = (((ray->rect_tex_y_off + rect->y)
				/ (ray->rect_h * ray->rect_h_prop))
			* (ray->tex->height - 1));
	tex_idx = (y * ray->tex->width + ray->rect_tex_x_off) * 4;
	// if (ray->wall_type == W_wall || ray->wall_type == S_wall)
	// 	tex.x = (ray->tex->width - tex.x); 
	rect->color->r = ray->tex->pixels[tex_idx];
	rect->color->g = ray->tex->pixels[tex_idx + 1];
	rect->color->b = ray->tex->pixels[tex_idx + 2];
	rect->color->a = ray->tex->pixels[tex_idx + 3];
}

void	draw_wall_rect(t_map *map, t_ray *ray)
{
	t_pxl	rect;
	t_pxl	rect_offset;

	get_ray_calcs(map, ray);
	rect.x = 0;
	rect.y = 0;
	rect.color = init_color(0, 0, 0, 0);
	while (rect.y < ceil(ray->rect_h))
	{
		get_tex_pxl_color(&rect, ray);
		rect_offset.y = rect.y + ceil(((float)VP_H - ray->rect_h) / 2.0);
		rect_offset.color = rect.color;
		while (rect.x < ceil(ray->rect_w))
		{
			rect_offset.x = rect.x + ray->rect_x_off;
			draw_pixel(map->cam, &rect_offset);
			rect.x += 1;
		}
		rect.x = 0;
		rect.y += 1;
	}
}

void	draw_camera(t_map *map)
{
	t_pxl	tl_crn;
	t_pxl	br_crn;
	t_pxl	mm_center;

	tl_crn.x = 0;
	tl_crn.y = 0;
	br_crn.x = VP_W;
	br_crn.y = VP_H / 2;
	draw_rect(map->cam, &tl_crn, &br_crn, map->ceiling);
	tl_crn.y = VP_H / 2;
	br_crn.y = VP_H;
	draw_rect(map->cam, &tl_crn, &br_crn, map->floor);
	raycaster(map);
	mm_center.x = MM_RADIUS;
	mm_center.y = MM_RADIUS;
	mm_center.color = init_color(0, 0, 0, 0);
	draw_circle(map->cam, &mm_center, MM_RADIUS, mm_center.color);
	free(mm_center.color);
}
