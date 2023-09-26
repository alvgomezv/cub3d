/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:14:12 by fgomez-d          #+#    #+#             */
/*   Updated: 2022/12/05 21:36:14 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Counts the number of words in the string str separated by delim
*/
static int	count_words(const char *str, char delim)
{
	int		i;
	int		nwords;

	i = 0;
	nwords = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == delim)
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] != '\0' && str[i] != delim)
			i++;
		nwords++;
	}
	return (nwords);
}

/*
	Takes the string pstr passed by reference and moves the pointer to the start
	of the first word it finds, ignoring all delim chars it finds.
*/
static int	find_next_word(const char **pstr, char delim, int prev_wlen)
{
	int	wlen;

	wlen = 0;
	*pstr += prev_wlen;
	while (**pstr != '\0' && **pstr == delim)
		*pstr += 1;
	if (**pstr == '\0')
		return (0);
	while ((*pstr)[wlen] != '\0' && (*pstr)[wlen] != delim)
		wlen += 1;
	return (wlen);
}

/*
	Frees all allocated strings in the string array and the array itself.
	Returns NULL.
*/
static void	*protect_alloc(char	***strtab)
{
	int	i;

	i = 0;
	while ((*strtab)[i] != NULL)
	{
		free((*strtab)[i]);
		i++;
	}
	free(*strtab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strtab;
	int		nwords;
	int		wi;
	int		wlen;

	nwords = count_words(s, c);
	strtab = (char **) ft_calloc(nwords + 1, sizeof(char *));
	if (strtab == NULL)
		return (NULL);
	strtab[nwords] = NULL;
	if (nwords == 0)
		return (strtab);
	wi = 0;
	wlen = 0;
	while (wi < nwords)
	{
		wlen = find_next_word(&s, c, wlen);
		strtab[wi] = (char *) ft_calloc(wlen + 1, sizeof(char));
		if (strtab[wi] == NULL)
			return (protect_alloc(&strtab));
		ft_strlcpy(strtab[wi], s, wlen + 1);
		wi++;
	}	
	return (strtab);
}
