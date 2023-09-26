/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:16:18 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/04/14 11:44:59 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_sign(char **str)
{
	int	sign;

	sign = 1;
	while ((**str == '+' || **str == '-') && **str != '\0')
	{
		if (**str == '-')
			sign *= -1;
		*str = *str + 1;
	}
	return (sign);
}

int	is_base_correct(char *base)
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
			if (base[i] == base[j] || base[j] == '+')
				is_base_correct = 0;
			if (base[j] == '-' || base[j] == ' ')
				is_base_correct = 0;
			j++;
		}
		i++;
		j = i + 1;
	}
	return (is_base_correct);
}

int	get_index(char *str, char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (*str == base[index])
			break ;
		index++;
	}
	if (index == ft_strlen(base))
		index = -1;
	return (index);
}

int	ft_atoi_base(char *str, char *base)
{
	int	num;
	int	sign;
	int	read_numbers;

	num = 0;
	read_numbers = 0;
	while ((*str == ' ' || (9 <= *str && *str <= 13)) && *str != '\0')
		str++;
	sign = get_sign(&str);
	while (*str != '\0')
	{
		if (get_index(str, base) >= 0)
		{
			num = num * ft_strlen(base) + get_index(str, base);
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
