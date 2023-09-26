/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:29:22 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/12/01 16:42:04 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;

	ptr_s = (unsigned char *) s;
	while (n > 0)
	{
		if (*ptr_s == (unsigned char) c)
			return ((void *) ptr_s);
		ptr_s++;
		n--;
	}
	return (NULL);
}
