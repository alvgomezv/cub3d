/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:53:13 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/12/01 17:02:16 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			i;

	ptr_s1 = (unsigned char *) s1;
	ptr_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (ptr_s1[i] != ptr_s2[i])
			return ((int)(ptr_s1[i] - ptr_s2[i]));
		i++;
	}
	return (0);
}
