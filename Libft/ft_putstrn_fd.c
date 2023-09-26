/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:05:13 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/12/21 15:59:07 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrn_fd(char *s, int len, int fd)
{
	int	i;

	i = 0;
	if (len < 0)
		len = 0;
	while (s[i] != '\0' && i < len)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
