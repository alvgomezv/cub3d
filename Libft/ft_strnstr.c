/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:24:34 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/12/01 20:36:54 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*str, const char *to_find, size_t len)
{
	size_t	s_idx;
	size_t	tf_idx;

	s_idx = 0;
	tf_idx = 0;
	if (*to_find == '\0')
		return ((char *) str);
	while (str[s_idx] != '\0' && s_idx < len)
	{
		if (str[s_idx] == to_find[tf_idx])
		{
			tf_idx++;
			if (to_find[tf_idx] == '\0')
				return ((char *)(str + ((s_idx + 1) - tf_idx)));
		}
		else
		{
			if (tf_idx > 0)
				s_idx -= tf_idx;
			tf_idx = 0;
		}
		s_idx++;
	}
	return (NULL);
}
