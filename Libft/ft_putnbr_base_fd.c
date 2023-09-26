/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:41:44 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/12/22 18:59:07 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_base_correct(char *base)
{
	int	is_base_correct;
	int	i;
	int	j;

	i = 0;
	j = 1;
	is_base_correct = ft_strlen(base) > 1;
	while (base[i] != '\0' && is_base_correct)
	{
		while (base[j] != '\0' && is_base_correct)
		{
			if (base[i] == base[j] || base[j] == '-' || base[j] == '+')
				is_base_correct = 0;
			j++;
		}
		i++;
		j = i + 1;
	}
	return (is_base_correct);
}

void	ft_putnbr_base_fd(long nbr, char *base, int fd)
{
	if (is_base_correct(base))
	{
		if (nbr < 0)
		{
			ft_putchar_fd('-', fd);
			nbr *= -1;
		}
		if (nbr < ft_strlen(base))
			ft_putchar_fd(base[nbr], fd);
		else
		{
			ft_putnbr_base_fd(nbr / ft_strlen(base), base, fd);
			ft_putnbr_base_fd(nbr % ft_strlen(base), base, fd);
		}
	}
}
