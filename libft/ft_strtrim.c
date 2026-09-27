/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:48:57 by marlope3          #+#    #+#             */
/*   Updated: 2026/09/23 16:48:57 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	getini(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	if (!s1)
		return (0);
	while (s1[i] != '\0')
	{
		flag = 1;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				flag = 0;
			j++;
		}
		if (flag == 1)
			break ;
		j = 0;
		i++;
	}
	return (i);
}

static	int	getend(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	flag;

	i = ft_strlen(s1) - 1;
	j = 0;
	flag = 0;
	if (!s1)
		return (0);
	while (i >= 0)
	{
		flag = 1;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				flag = 0;
			j++;
		}
		if (flag == 1)
			break ;
		j = 0;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = getini(s1, set);
	end = getend(s1, set);
	if (end < start)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	while (start + i <= end)
	{
		str[i] = s1[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
