/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:03:21 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/25 10:55:23 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stk_s(t_stk *stk)
{
	if (stk != stk->first)
		stk = stk->first;
	ft_stkadd_top(stk, ft_stkpop(&stk, stk->first->next));
}
