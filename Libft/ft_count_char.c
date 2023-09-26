/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:21:58 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/26 18:21:40 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// char	*ft_strchr(const char *s, int c)
// {
// 	if (s == NULL)
// 		return (NULL);
// 	while (*s != '\0')
// 	{
// 		if (*s == (char) c)
// 			return ((char *) s);
// 		s++;
// 	}
// 	if ((char) c == '\0')
// 		return ((char *) s);
// 	return (NULL);
// }

int	ft_count_char(char *str, char c)
{
	int		count;
	char	*aux;

	if (c == '\0')
		return (-1);
	count = 0;
	aux = ft_strchr(str, c);
	if (!aux)
		return (0);
	str = aux + 1;
	while (str != NULL)
	{
		count++;
		aux = ft_strchr(str, c);
		if (!aux)
			return (count);
		str = aux + 1;
	}
	return (count);
}

// int	main(void)
// {
// 	printf("%d\n", ft_count_char(" holah perroh", 'h'));
// }