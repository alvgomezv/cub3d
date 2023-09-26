/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stknew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:30:33 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/21 20:49:43 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stk	*ft_stknew(void *content)
{
	t_stk	*node;

	node = (t_stk *) malloc(sizeof(t_stk));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->first = node;
	node->next = node;
	return (node);
}
