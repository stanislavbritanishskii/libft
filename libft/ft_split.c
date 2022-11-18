/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbritani <sbritani@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 03:38:52 by sbritani          #+#    #+#             */
/*   Updated: 2022/10/24 02:51:04 by sbritani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		counter;
	int		i;
	int		prev;

	prev = 0;
	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			counter += prev;
			prev = 0;
		}
		else
			prev = 1;
		i++;
	}
	if (i == 0)
		return (0);
	return (counter + (s[i - 1] != c));
}

static void	*clear(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return (NULL);
}

static char	**ft_split_word(char **res, int i, char c, char const *s)
{
	int	word;
	int	j;
	int	counter;

	j = 0;
	word = -1;
	while (++word < count_words(s, c))
	{
		while (s[i] == c && s[i])
			i = i + 1;
		j = i;
		while (s[i] && s[i] != c)
			i += 1;
		res[word] = malloc(sizeof(char) * (i - j + 1));
		if (!res[word])
			return (clear(res));
		counter = 0;
		while (j < i)
			res[word][counter++] = s[j++];
		res[word][counter] = '\0';
	}
	res[word] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	res = ft_split_word(res, i, c, s);
	return (res);
}
