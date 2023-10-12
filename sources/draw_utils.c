# include "../cub3d.h"

void	draw_pixel(mlx_image_t *img, t_pxl *pxl)
{
	int	pxl_idx;

	if (0 <= pxl->x && pxl->x < (int)img->width
		&& 0 <= pxl->y && pxl->y < (int)img->height)
	{
		pxl_idx = (pxl->y * img->width + pxl->x) * 4;
		img->pixels[pxl_idx] = pxl->color->r;
		img->pixels[pxl_idx + 1] = pxl->color->g;
		img->pixels[pxl_idx + 2] = pxl->color->b;
		img->pixels[pxl_idx + 3] = pxl->color->a;
	}
}

void	draw_line(mlx_image_t *img, t_pxl *pxl1, t_pxl *pxl2, t_color *c)
{
	t_pxl		pxl;
	double		mx;
	double		my;
	int			n_pts;
	int			i;

	n_pts = ft_minmax(ft_abs(pxl2->x - pxl1->x), \
					ft_abs(pxl2->y - pxl1->y), 0);
	mx = (double)(pxl2->x - pxl1->x) / (double)(n_pts);
	my = (double)(pxl2->y - pxl1->y) / (double)(n_pts);
	i = 0;
	while (i <= n_pts)
	{
		pxl.x = (int)(mx * i) + pxl1->x;
		pxl.y = (int)(my * i) + pxl1->y;
		pxl.color = c;
		draw_pixel(img, &pxl);
		i++;
	}
}

void	draw_square(mlx_image_t *img, t_pxl *tl_corner, int size, t_color *c)
{
	t_pxl	pxl;
	int		irow;
	int		icol;

	irow = -1;
	icol = -1;
	pxl.color = c;
	while (++irow < size)
	{
		while (++icol < size)
		{
			pxl.x = tl_corner->x + icol;
			pxl.y = tl_corner->y + irow;
			draw_pixel(img, &pxl);
		}
		icol = -1;
	}
}

void	draw_rect(mlx_image_t *img, t_pxl *tl_crn, t_pxl *br_crn, t_color *c)
{
	t_pxl	pxl;

	pxl.color = c;
	pxl.x = tl_crn->x;
	pxl.y = tl_crn->y;
	while (pxl.y < br_crn->y)
	{
		while (pxl.x < br_crn->x)
		{
			draw_pixel(img, &pxl);
			pxl.x += 1;
		}
		pxl.x = tl_crn->x;
		pxl.y += 1;
	}
}




