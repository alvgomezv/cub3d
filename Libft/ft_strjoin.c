/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:37:46 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/12/06 14:17:23 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*catstr;
	int		s1len;

	s1len = ft_strlen(s1);
	catstr = (char *) ft_calloc(s1len + ft_strlen(s2) + 1, sizeof(char));
	if (catstr == NULL)
		return (NULL);
	ft_strlcpy(catstr, s1, s1len + 1);
	ft_strlcat(catstr, s2, s1len + ft_strlen(s2) + 1);
	return (catstr);
}
