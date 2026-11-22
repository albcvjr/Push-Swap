/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:01:52 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/12 17:34:09 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	_ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	word_count;
	size_t	letter_count;

	word_count = 0;
	letter_count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			letter_count = 0;
		else if (letter_count == 1)
			word_count++;
		letter_count++;
		i++;
	}
	return (word_count);
}

static char const	*_ft_word_next(char const *s, char c)
{
	while (*s == c)
		s += 1;
	return (s);
}

static void	_free_mem(char **list_str, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free(list_str[i]);
		list_str[i] = 0;
		i++;
	}
	free(list_str);
	list_str = 0;
}

static int	_add_words(char **list_str, char const *s, char c, size_t wc)
{
	char	*substr_end;
	size_t	i;

	i = 0;
	while (i < wc)
	{
		s = _ft_word_next(s, c);
		substr_end = ft_strchr(s, c);
		if (substr_end)
			list_str[i] = ft_substr(s, 0, substr_end - s);
		else
			list_str[i] = ft_strdup(s);
		s = substr_end + 1;
		if (!list_str[i])
		{
			_free_mem(list_str, i);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = _ft_word_count(s, c);
	ret = ft_calloc(word_count + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	ret[word_count] = NULL;
	if (!_add_words(ret, s, c, word_count))
		return (NULL);
	return (ret);
}
