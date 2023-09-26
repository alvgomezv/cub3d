/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:40:44 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/26 14:08:26 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strlcpy2(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
}

char	*ft_strjoin2(char const *s1, char *s2)
{
	char	*catstr;
	size_t	size;
	size_t	i;
	size_t	j;
	size_t	destlen;

	if (s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	catstr = (char *) malloc(size);
	if (catstr == NULL)
		return (free(s2), NULL);
	ft_strlcpy2(catstr, s1, ft_strlen(s1) + 1);
	i = 0;
	destlen = ft_strlen(catstr);
	j = destlen;
	while (s2[i] != '\0' && i < size - destlen - 1)
	{
		catstr[j] = s2[i];
		j++;
		i++;
	}
	catstr[j] = '\0';
	free(s2);
	return (catstr);
}
