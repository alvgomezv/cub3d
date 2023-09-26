/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stknewfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:12:20 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/08 15:21:44 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stknewfirst(t_stk *stk, t_stk *new_first)
{
	t_stk	*start;

	if (ft_getstkidx(stk, new_first) == -1)
		return ;
	start = stk;
	while (stk->next != start)
	{
		stk->first = new_first;
		stk = stk->next;
	}
	stk->first = new_first;
}
