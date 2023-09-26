/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:04:35 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/12/02 13:32:11 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;

	if (s == NULL)
		return (NULL);
	if (start >= (unsigned int) ft_strlen(s))
		start = (unsigned int) ft_strlen(s);
	if (len > (unsigned int) ft_strlen(s) - start)
		len = (unsigned int) ft_strlen(s) - start;
	newstr = (char *) ft_calloc(len + 1, sizeof(char));
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, s + start, len + 1);
	return (newstr);
}
