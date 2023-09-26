/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpop_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:06:11 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/25 10:55:44 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stk	*ft_stkpop_idx(t_stk *stk, int idx)
{
	int		size;
	t_stk	*popped;

	if (stk == NULL)
		return (NULL);
	size = ft_stksize(stk);
	if (idx >= size || idx < 0)
		return (NULL);
	if (stk != stk->first)
		stk = stk->first;
	popped = stk;
	while (idx > 0)
	{
		popped = popped->next;
		idx--;
	}
	return (ft_stkpop(&stk, popped));
}
