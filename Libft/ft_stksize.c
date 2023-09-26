/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stksize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:01:56 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/23 14:10:23 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stksize(t_stk *stk)
{
	int	len;

	if (stk == NULL)
		return (0);
	if (stk != stk->first)
		stk = stk->first;
	if (stk->next == stk->first)
		return (1);
	len = 1;
	stk = stk->next;
	while (stk->next != stk->first)
	{
		stk = stk->next;
		len++;
	}
	len++;
	return (len);
}
