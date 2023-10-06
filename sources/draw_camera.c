#include "../cub3d.h"



void	get_ray_calcs(t_map *map, t_ray *ray)
{
	float	pos;

	ray->rect_h = (int)(VP_H * MM_C_SIZE / (ray->dist));
	ray->rect_w = ceil((float) VP_W / (float)(FOV / RAY_DEG));
	ray->rect_x_off = (int)((float) (VP_W * ray->iray) / (float)(FOV / RAY_DEG));
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
	{
		pos = ray->y;
	}
	ray->rect_tex_x_off = ceil((pos / (float)MM_C_SIZE) * (float)ray->tex->width);
}

void	get_tex_pxl_color(t_pxl *rect, t_ray *ray)
{
	t_pxl	tex;

	tex.x = ray->rect_tex_x_off + (ray->rect_tex_x_off - ray->prev_rect_tex_x_off) \
		* floor((float)(rect->x - ray->rect_x_off) / (float)ray->rect_w);
	// tex.x = tex.x % ray->tex->width;
	tex.y = floor(((float)(rect->y - ((VP_H - ray->rect_h) / 2)) / (float)ray->rect_h) \
		* (float)ray->tex->height);
	rect->color->r = ray->tex->pixels[(tex.y * ray->tex->width + tex.x) * 4];
	rect->color->g = ray->tex->pixels[(tex.y * ray->tex->width + tex.x) * 4 + 1];
	rect->color->b = ray->tex->pixels[(tex.y * ray->tex->width + tex.x) * 4 + 2];
	rect->color->a = ray->tex->pixels[(tex.y * ray->tex->width + tex.x) * 4 + 3];
}

void	draw_wall_rect(t_map *map, t_ray *ray)
{
	t_pxl	rect;

	get_ray_calcs(map, ray);
	rect.x = ray->rect_x_off;
	rect.y = (VP_H - ray->rect_h) / 2;
	rect.color = init_color(0, 0, 0, 0);
	while (rect.y < (VP_H + ray->rect_h) / 2)
	{
		while (rect.x - ray->rect_x_off < ray->rect_w)
		{
			get_tex_pxl_color(&rect, ray);
			draw_pixel(map->cam, &rect);
			rect.x += 1;
		}
		rect.x = ray->rect_x_off;
		rect.y += 1;
	}
	ray->prev_rect_tex_x_off = ray->rect_tex_x_off;
}

