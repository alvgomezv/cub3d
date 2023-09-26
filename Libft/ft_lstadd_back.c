/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:25:16 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/07/19 19:51:52 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	if (new_node == NULL)
		return ;
	if ((*lst) == NULL)
		(*lst) = new_node;
	else
		ft_lstlast((*lst))->next = new_node;
}
