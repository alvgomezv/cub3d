/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:35:03 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/12/01 15:12:56 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n && n != 0)
	{
		if (src >= dest)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
		else
		{
			ptr_dest[n - 1] = ptr_src[n - 1];
			n--;
		}
	}
	return (ptr_dest);
}
