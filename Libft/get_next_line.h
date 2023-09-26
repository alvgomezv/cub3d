/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:47 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/26 14:09:07 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define MAX_FD 10000

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

char	*get_next_line(int fd);
void	ft_strlcpy2(char *dest, const char *src, size_t size);
char	*recursive_get_ln(char *buf, char *ln, int fd, int subbuf_len);
int		count_until_endl(char *buf, int *ln_len);
char	*ft_strjoin2(char const *s1, char *s2);
void	update_buf(char *buf, int subbuf_len, int endln_found);

#endif
