/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:24:25 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/12/01 16:33:25 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		destlen;

	i = 0;
	destlen = ft_strlen(dest);
	if (size > destlen)
	{
		while (*dest != '\0')
			dest++;
		while (src[i] != '\0' && i < size - destlen - 1)
			*(dest++) = src[i++];
		*dest = '\0';
	}
	if (size < destlen)
		return ((int) size + ft_strlen(src));
	return ((int) destlen + ft_strlen(src));
}
