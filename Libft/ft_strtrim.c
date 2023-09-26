/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:00:30 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/12/06 14:47:33 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tstr;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1);
	if (ft_strncmp(set, "", 1))
	{
		while (ft_strchr(set, s1[start]) != NULL && s1[start] != '\0')
			start++;
		while (ft_strchr(set, s1[end]) != NULL && end > 0 && end > start)
			end--;
	}
	tstr = ft_substr(s1, start, end - start + 1);
	return (tstr);
}
