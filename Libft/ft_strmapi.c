/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:32:37 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/12/06 09:59:15 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	newstr = ft_strdup(s);
	i = 0;
	if (newstr == NULL)
		return (NULL);
	while (newstr[i] != '\0')
	{
		newstr[i] = f(i, newstr[i]);
		i++;
	}
	return (newstr);
}
