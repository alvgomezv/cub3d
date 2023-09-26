/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:06:11 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/28 11:38:34 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	redirect_links(t_stk **stk, t_stk *to_pop, t_stk *prev)
{
	prev->next = (*stk)->next;
	*stk = (*stk)->next;
	to_pop->next = to_pop;
	to_pop->first = to_pop;
	if ((*stk)->first == to_pop)
		ft_stknewfirst(*stk, *stk);
}

t_stk	*ft_stkpop(t_stk **stk, t_stk *to_pop)
{	
	t_stk	*prev;
	t_stk	*orig;

	*stk = (*stk)->first;
	prev = ft_stklast(*stk);
	orig = *stk;
	if (*stk == to_pop)
	{
		redirect_links(stk, to_pop, prev);
		return (to_pop);
	}
	*stk = (*stk)->next;
	prev = prev->next;
	while (*stk != orig)
	{
		if (*stk == to_pop)
		{
			redirect_links(stk, to_pop, prev);
			return (to_pop);
		}
		*stk = (*stk)->next;
		prev = prev->next;
	}
	return (NULL);
}
