/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:41:46 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/13 16:05:34 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(const char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static int	word_c(const char *str, char charset)
{
	int	i;
	int	wordcount;

	if (!*str)
		return (0);
	i = 1;
	wordcount = 0;
	while (str[i])
	{
		if (!is_in_set(str[i], charset) && is_in_set(str[i - 1], charset))
			wordcount++;
		i++;
	}
	i = 0;
	if (!is_in_set(str[0], charset) && str[i])
		wordcount++;
	return (wordcount);
}

static int	get_length(const char *str, char charset, int i)
{
	int	l;

	l = 0;
	while (str[i] != '\0' && !is_in_set(str[i], charset))
	{
		l++;
		i++;
	}
	return (l);
}

static void	insert(const char *str, char *cut, int len, int i)
{
	int	l;

	l = 0;
	while (len > 0)
	{
		cut[l] = str[i];
		len--;
		i++;
		l++;
	}
	cut[l] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		pos;
	int		len;

	i = 0;
	pos = 0;
	if (!s)
		return (NULL);
	arr = malloc(sizeof (char *) * (word_c(s, c) + 1));
	if (!arr)
		return (NULL);
	while (s[i] && pos < word_c(s, c))
	{
		if (!is_in_set(s[i], c))
		{
			len = get_length(s, c, i);
			arr[pos] = (char *)malloc(sizeof (char) * (len + 1));
			insert(s, arr[pos++], len, i);
			i = i + len - 1;
		}
		i++;
	}
	arr[word_c(s, c)] = NULL;
	return (arr);
}
