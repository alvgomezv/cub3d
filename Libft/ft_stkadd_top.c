/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkadd_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:25:16 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/21 20:00:22 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stkadd_top(t_stk *stk, t_stk *new_node)
{
	if (new_node == NULL)
		return ;
	if (stk == NULL)
	{
		stk = new_node;
		stk->first = stk;
		stk->next = stk;
	}
	if (stk != stk->first)
		stk = stk->first;
	new_node->next = stk;
	new_node->first = new_node;
	ft_stklast(stk)->next = new_node;
	ft_stknewfirst(stk, new_node);
}
