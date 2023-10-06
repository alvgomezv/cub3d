#include "../cub3d.h"

void	get_ray_calcs(t_map *map, t_ray *ray)
{
	int	pos;

	ray->rect_h = (int)(VP_H * MM_C_SIZE / (ray->dist * cos(ray->iangle)));
	ray->rect_w = (int)(VP_W / (FOV / RAY_DEG));
	ray->rect_x_off = (int)(VP_W * ray->iangle / FOV);
	if (ray->wall_type == N_wall)
		ray->tex = map->N_tex;
	else if (ray->wall_type == S_wall)
		ray->tex = map->S_tex;
	else if (ray->wall_type == E_wall)
		ray->tex = map->E_tex;
	else
		ray->tex = map->W_tex;
	if (ray->wall_type == N_wall || ray->wall_type == S_wall)
		pos = ray->hit_pos->x;
	else
		pos = ray->hit_pos->y;
	ray->rect_tex_x_off = (ray->hit_pos->x % MM_C_SIZE) \
		* ray->tex->width / MM_C_SIZE;
}

void	get_tex_pxl_color(t_map *map, t_pxl *rect, t_ray *ray)
{
	t_pxl	tex;

	tex.x = ray->rect_tex_x_off \
			+ ((rect->x - ray->rect_x_off) / ray->rect_w) * ray->tex->width;
	if (tex.x > map->cam->width)
		tex.x = map->cam->width;
	tex.y = ((rect->y - ((VP_H - ray->rect_h) / 2)) / ray->rect_h) \
		* ray->tex->height;
	rect->color->r = ray->tex->pixels[tex.y * ray->tex->width + tex.x];
	rect->color->g = ray->tex->pixels[tex.y * ray->tex->width + tex.x + 1];
	rect->color->b = ray->tex->pixels[tex.y * ray->tex->width + tex.x + 2];
	rect->color->a = ray->tex->pixels[tex.y * ray->tex->width + tex.x + 3];
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
			get_tex_pxl_color(map, &rect, ray);
			draw_pixel(map->cam, &rect);
			rect.x += 1;
		}
		rect.x = ray->rect_x_off;
		rect.y += 1;
	}

}

