/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:39:20 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/07/19 19:52:39 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*plstnew(t_list	**nl, t_list **nn, void **nc, void (*d)(void *))
{
	ft_lstclear(nl, d);
	free(*nn);
	free(*nc);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	void	*newcont;

	newlst = NULL;
	while (lst != NULL)
	{
		newcont = f(lst->content);
		if (newcont == NULL)
		{
			ft_lstclear(&newlst, del);
			free(newcont);
			break ;
		}
		newnode = ft_lstnew(newcont);
		if (newnode == NULL)
			return (plstnew(&newlst, &newnode, &newcont, del));
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}
