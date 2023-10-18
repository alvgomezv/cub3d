/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:45:58 by alvgomez          #+#    #+#             */
/*   Updated: 2023/10/18 11:46:37 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
