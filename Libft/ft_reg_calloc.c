/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reg_calloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:50:21 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/07/19 19:53:02 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_reg_calloc(size_t nmemb, size_t size, t_list **alloc)
{
	void	*ptr;
	t_list	*new_node;

	ptr = ft_calloc(nmemb, size);
	if (!ptr)
		return (NULL);
	new_node = ft_lstnew(ptr);
	if (!new_node)
		return (NULL);
	if (!*alloc)
		*alloc = new_node;
	else
		ft_lstadd_back(alloc, new_node);
	return (ptr);
}
