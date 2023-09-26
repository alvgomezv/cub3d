/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:21:29 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/03/21 17:24:28 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pointer_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	quick_sort(int arr[], int start, int end)
{
	int	i;
	int	j;

	if (end - start < 1)
		return ;
	if (end - start == 1)
	{
		if (arr[start] > arr[end])
			pointer_swap(&arr[start], &arr[end]);
		return ;
	}
	i = start;
	j = end - 1;
	while (i < j)
	{
		while (arr[i] <= arr[end] && i <= end - 1)
			i++;
		while (arr[j] > arr[end])
			j--;
		if (i < j)
			pointer_swap(&arr[i], &arr[j]);
	}
	pointer_swap(&arr[i], &arr[end]);
	quick_sort(arr, start, j);
	quick_sort(arr, i + 1, end);
}
