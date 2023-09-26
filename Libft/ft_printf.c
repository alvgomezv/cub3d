/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:42:58 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/26 13:36:11 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_int_digits(void *arg)
{
	int				digits;
	int				nint;

	nint = (int) arg;
	if (nint == 0)
		return (1);
	digits = 0;
	if (nint < 0)
		digits++;
	while (nint != 0)
	{
		nint /= 10;
		digits++;
	}
	return (digits);
}

int	count_uint_digits(char conv_esp, void *arg)
{
	int					digits;
	unsigned long int	nluint;
	int					divisor;

	nluint = (unsigned int) arg;
	if (conv_esp == 'p')
		nluint = (unsigned long int) arg;
	if (nluint == 0)
		return (1);
	digits = 0;
	divisor = 16;
	if (conv_esp == 'u')
		divisor = 10;
	while (nluint != 0)
	{
		nluint /= divisor;
		digits++;
	}
	return (digits);
}

int	get_rawstr_size(char conv_esp, void *arg)
{
	if (conv_esp == 'c')
		return (1);
	else if (conv_esp == 's')
	{
		if (arg == NULL)
			return (6);
		return (ft_strlen((char *) arg));
	}
	else if (conv_esp == 'd' || conv_esp == 'i')
		return (count_int_digits(arg));
	else
	{
		if (conv_esp == 'p')
			return (count_uint_digits(conv_esp, arg) + 2);
		return (count_uint_digits(conv_esp, arg));
	}
}

int	print_rawfstr(char conv_esp, void *arg)
{
	if (conv_esp == 'c')
		ft_putchar_fd((char) arg, 1);
	else if (conv_esp == 's')
	{
		if (arg == NULL)
			ft_putstr_fd("(null)", 1);
		else
			ft_putstr_fd((char *) arg, 1);
	}
	else if (conv_esp == 'd' || conv_esp == 'i')
		ft_putnbr_fd((int) arg, 1);
	else if (conv_esp == 'u')
		ft_putnbr_fd((unsigned int) arg, 1);
	else if (conv_esp == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_putunbr_base_fd((unsigned long int) arg, "0123456789abcdef", 1);
	}
	else if (conv_esp == 'x')
		ft_putunbr_base_fd((unsigned int) arg, "0123456789abcdef", 1);
	else if (conv_esp == 'X')
		ft_putunbr_base_fd((unsigned int) arg, "0123456789ABCDEF", 1);
	return (get_rawstr_size(conv_esp, arg));
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_list;
	int		count;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(arg_list, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%' && ft_strchr("cspdiuxX", str[1]) && str[1] != '\0')
				count += print_rawfstr(*(++str), va_arg(arg_list, void *));
		else
		{
			if (*str == '%')
				str++;
			if (*str == '\0')
				return (count);
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	return (count);
}
