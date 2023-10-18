/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:42:53 by alvgomez          #+#    #+#             */
/*   Updated: 2023/10/18 11:42:57 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	color_to_int(t_color *color)
{
	return (color->r << 24 | color->g << 16 | color->b << 8 | color->a);
}

t_color	*int_to_color(int rgba)
{
	t_color	*color;

	color = (t_color *) ft_calloc(1, sizeof(t_color));
	color->r = (rgba >> 24) & 0xFF;
	color->g = (rgba >> 16) & 0xFF;
	color->b = (rgba >> 8) & 0xFF;
	color->a = rgba & 0xFF;
	return (color);
}
