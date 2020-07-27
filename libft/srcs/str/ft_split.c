/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:37:27 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/28 14:47:52 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int			is_charset(char c, char const *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		++i;
	}
	return (0);
}

static unsigned int	number_of_words(char const *s, char const *charset)
{
	int i;
	int nb_of_words;
	int in_word;

	in_word = 0;
	nb_of_words = 0;
	i = 0;
	while (s[i])
	{
		if (is_charset(s[i], charset) == 0)
		{
			if (in_word == 0)
			{
				++nb_of_words;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		++i;
	}
	return (nb_of_words);
}

static char			**free_mem(char **tab, int j)
{
	int i;

	i = -1;
	while (++i < j)
		free(tab[i]);
	free(tab);
	tab = NULL;
	return (tab);
}

static char			*alloc_word(char const *s, char const *charset)
{
	char	*new_line;
	int		i;

	i = 0;
	while (*(s + i) && is_charset(*(s + i), charset) == 0)
		++i;
	if (!(new_line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (*(s + i) && is_charset(*(s + i), charset) == 0)
	{
		*(new_line + i) = *(s + i);
		++i;
	}
	*(new_line + i) = 0;
	return (new_line);
}

char				**ft_split(char const *s, char const *charset)
{
	int		i;
	int		j;
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (number_of_words(s, charset) + 1));
	i = 0;
	j = 0;
	while (*(s + i))
	{
		while (is_charset(*(s + i), charset) == 1)
			++i;
		if (*(s + i) && is_charset(*(s + i), charset) == 0)
		{
			if (!(tab[j] = alloc_word((s + i), charset)))
				return (free_mem(tab, j));
			++j;
			while (*(s + i) && is_charset(*(s + i), charset) == 0)
				++s;
		}
	}
	tab[j] = 0;
	return (tab);
}
