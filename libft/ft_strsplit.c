/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:09:25 by jpasty            #+#    #+#             */
/*   Updated: 2020/11/04 09:29:00 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char		*ft_memword(char const *s, char c)
{
	char		*word;
	size_t		l;
	size_t		i;

	l = 0;
	i = 0;
	while (s[l] != c && s[l])
		l++;
	if (!(word = ft_memalloc(sizeof(char) * l + 1)))
		return (NULL);
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void		ft_freeptr(char **tab, int i)
{
	while (--i >= 0)
		free(tab[i]);
	free(tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		words;
	int			i;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_count_words(s, c);
	if (!(tab = ft_memalloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(tab[i] = ft_memword(s, c)))
				ft_freeptr(tab, i);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
