/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:11:47 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/08 15:21:34 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stkiter(t_stk *stk, void (*f)(void *))
{
	if (stk == NULL || f == NULL)
		return ;
	if (stk != stk->first)
		stk = stk->first;
	while (stk->next != stk->first)
	{
		f(stk->content);
		stk = stk->next;
	}
	f(stk->content);
}
