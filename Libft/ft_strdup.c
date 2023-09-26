/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:38:00 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/12/01 21:56:45 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*newstr;

	newstr = (char *) ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, str, ft_strlen(str) + 1);
	return (newstr);
}
