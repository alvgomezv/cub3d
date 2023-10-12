#include "../cub3d.h"



void	get_ray_calcs(t_map *map, t_ray *ray)
{
	float	pos;

	ray->rect_h = ((VP_H * MM_C_SIZE) / ray->dist);
	ray->rect_w = (VP_W / (FOV / RAY_DEG));
	ray->rect_x_off = ((VP_W * (float)ray->iray) / (FOV / RAY_DEG));
	if (ray->wall_type == N_wall)
		ray->tex = map->N_tex;
	else if (ray->wall_type == S_wall)
		ray->tex = map->S_tex;
	else if (ray->wall_type == E_wall)
		ray->tex = map->E_tex;
	else
		ray->tex = map->W_tex;
	if (ray->wall_type == N_wall || ray->wall_type == S_wall)
		pos = ray->x;
	else
		pos = ray->y;
	ray->rect_tex_x_off = ((pos - (floor(pos / (float)MM_C_SIZE) * MM_C_SIZE)) / (float)MM_C_SIZE) * (float)ray->tex->width;
}

void	get_tex_pxl_color(t_pxl *rect, t_ray *ray)
{
	t_pxl	tex;

	tex.x = floor(ray->rect_tex_x_off) + fabs(ray->rect_tex_x_off - ray->prev_rect_tex_x_off) \
		* (rect->x / ray->rect_w);
	if (tex.x > (int)ray->tex->width)
		tex.x = ray->tex->width;
	tex.y = ((rect->y / ray->rect_h) * (float)ray->tex->height);
	rect->color->r = ray->tex->pixels[(tex.y * ray->tex->width + tex.x) * 4];
	rect->color->g = ray->tex->pixels[(tex.y * ray->tex->width + tex.x) * 4 + 1];
	rect->color->b = ray->tex->pixels[(tex.y * ray->tex->width + tex.x) * 4 + 2];
	rect->color->a = ray->tex->pixels[(tex.y * ray->tex->width + tex.x) * 4 + 3];
}

void	set_rect_offset(t_pxl *rect, t_pxl *rect_offset, t_ray *ray)
{
	rect_offset->x = rect->x + ray->rect_x_off;
	rect_offset->y = rect->y + floor(((float)VP_H - ray->rect_h) / 2.0);
	rect_offset->color = rect->color;
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
		while (rect.x < ceil(ray->rect_w))
		{
			get_tex_pxl_color(&rect, ray);
			set_rect_offset(&rect, &rect_offset, ray);
			draw_pixel(map->cam, &rect_offset);
			rect.x += 1;
		}
		rect.x = 0;
		rect.y += 1;
	}
	ray->prev_rect_tex_x_off = ray->rect_tex_x_off;
}

