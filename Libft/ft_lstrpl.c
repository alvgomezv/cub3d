/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrpl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:45:42 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/31 15:36:53 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrpl(t_list *bg, t_list *old, t_list *new, void (*del)(void *))
{
	t_list	*prev_node;
	t_list	*foll_node;

	if (new == NULL)
		return (bg);
	foll_node = old->next;
	prev_node = bg;
	while (prev_node->next != old)
		prev_node = prev_node->next;
	prev_node->next = new;
	ft_lstlast(prev_node)->next = foll_node;
	ft_lstdelone(old, del);
	return (bg);
}
