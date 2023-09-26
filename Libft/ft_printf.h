/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:13:12 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/31 10:58:50 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define POSSIBLE_CHARS "0123456789-# +.cspdiuxX%"
# define FLAGS "-0#+ "
# define NON0 "123456789"
# define CONV_SP "cspdiuxX%"

# include <stdarg.h>
# include "libft.h"

enum e_fldtype
{
	Flags,
	MinWidth,
	Precision,
	ConvSp
};

int		count_int_digits(void *arg);

int		count_uint_digits(char conv_esp, void *arg);

int		get_rawstr_size(char conv_esp, void *arg);

int		print_rawfstr(char conv_esp, void *arg);

int		ft_printf(const char *str, ...);

int		print_rawfstr_fd(char conv_esp, void *arg, int fd);

int		ft_printf_fd(const char *str, int fd, ...);

#endif