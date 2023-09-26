/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:42:58 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/31 15:52:42 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_rawfstr_fd(char conv_esp, void *arg, int fd)
{
	if (conv_esp == 'c')
		ft_putchar_fd((char) arg, fd);
	else if (conv_esp == 's')
	{
		if (arg == NULL)
			ft_putstr_fd("(null)", fd);
		else
			ft_putstr_fd((char *) arg, fd);
	}
	else if (conv_esp == 'd' || conv_esp == 'i')
		ft_putnbr_fd((int) arg, fd);
	else if (conv_esp == 'u')
		ft_putnbr_fd((unsigned int) arg, fd);
	else if (conv_esp == 'p')
	{
		ft_putstr_fd("0x", fd);
		ft_putunbr_base_fd((unsigned long int) arg, "0123456789abcdef", fd);
	}
	else if (conv_esp == 'x')
		ft_putunbr_base_fd((unsigned int) arg, "0123456789abcdef", fd);
	else if (conv_esp == 'X')
		ft_putunbr_base_fd((unsigned int) arg, "0123456789ABCDEF", fd);
	return (get_rawstr_size(conv_esp, arg));
}

int	ft_printf_fd(const char *str, int fd, ...)
{
	va_list	args;
	int		count;

	if (write(fd, "", 0) == -1)
		return (-1);
	va_start(args, fd);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%' && ft_strchr("cspdiuxX", str[1]) && str[1] != '\0')
				count += print_rawfstr_fd(*(++str), va_arg(args, void *), fd);
		else
		{
			if (*str == '%')
				str++;
			if (*str == '\0')
				return (count);
			ft_putchar_fd(*str, fd);
			count++;
		}
		str++;
	}
	return (count);
}
