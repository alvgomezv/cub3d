/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:55:31 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/04/12 18:01:30 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_minmax(int a, int b, int find_min)
{
	if (find_min)
	{
		if (a <= b)
			return (a);
		return (b);
	}
	else
	{
		if (a >= b)
			return (a);
		return (b);
	}
}
