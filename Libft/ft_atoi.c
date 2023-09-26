/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:43:58 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/12/23 18:48:19 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_sign(const char **str)
{
	if (**str == '-')
	{
		*str += 1;
		return (-1);
	}
	else if (**str == '+')
		*str += 1;
	return (1);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	read_numbers;

	if (str == NULL)
		return (0);
	num = 0;
	read_numbers = 0;
	while ((*str == ' ' || (9 <= *str && *str <= 13)) && *str != '\0')
		str++;
	sign = set_sign(&str);
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
		{
			num = num * 10 + (*str - 48);
			read_numbers = 1;
		}
		else if (read_numbers)
			break ;
		else
			return (0);
		str++;
	}
	return (num * sign);
}
