/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:08:46 by marlope3          #+#    #+#             */
/*   Updated: 2026/09/18 12:08:46 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_all(char **res, int i)
{
	while (--i >= 0)
		free(res[i]);
	free(res);
}

char	*word_dup(char const *str, int start, int end)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * (end - start + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (start < end)
		dup[i++] = str[start++];
	dup[i] = '\0';
	return (dup);
}

int	fill_words(char **res, char const *str, char c)
{
	int	i;
	int	start;
	int	j;

	i = 0;
	start = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && str[i] != c)
			i++;
		res[j] = word_dup(str, start, i);
		if (!res[j])
			return (free_all(res, j), 0);
		j++;
	}
	res[j] = NULL;
	return (1);
}

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	if (!fill_words(res, s, c))
		return (NULL);
	return (res);
}
