/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstknode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:34:04 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/04/12 18:51:49 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stk	*ft_getstknode(t_stk *stk, int idx)
{
	int	i;
	int	size;

	size = ft_stksize(stk);
	if (idx < 0 || stk == NULL || idx >= size)
		return (NULL);
	if (stk != stk->first)
		stk = stk->first;
	if (idx == 0)
		return (stk);
	i = 1;
	stk = stk->next;
	while (i < size)
	{
		if (i == idx)
			return (stk);
		stk = stk->next;
		i++;
	}
	return (NULL);
}
