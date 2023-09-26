/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstkidx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:20:52 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/08 15:28:57 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getstkidx(t_stk *stk, t_stk *search)
{
	int	idx;

	idx = 0;
	if (stk == NULL || search == NULL)
		return (-1);
	if (stk != stk->first)
		stk = stk->first;
	if (stk == search)
		return (idx);
	while (stk->next != stk->first)
	{
		if (stk == search)
			return (idx);
		stk = stk->next;
		idx++;
	}
	if (stk == search)
		return (idx);
	return (-1);
}
