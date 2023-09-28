# include "../cub3d.h"

t_color	*init_color(int r, int g, int b, int a)
{
	t_color	*color;
	
	color = (t_color *) ft_calloc(1, sizeof(t_color));
	color->r = r;
	color->g = g;
	color->b = b;
	color->a = a;
	return (color);
}

t_pxl	*init_pxl(int x, int y, t_color *color)
{
	t_pxl	*pxl;
	
	pxl = (t_pxl *) ft_calloc(1, sizeof(t_pxl));
	pxl->x = x;
	pxl->y = y;
	pxl->color = color;
	return (pxl);
}

void	free_pxl(void *pxl_ptr)
{
	t_pxl	*pxl;

	pxl = (t_pxl *) pxl_ptr;
	free(pxl->color);
	free(pxl);

}
