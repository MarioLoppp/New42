/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:50:31 by marlope3          #+#    #+#             */
/*   Updated: 2026/09/18 12:50:31 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*append;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	append = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!append)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		append[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		append[i + j] = s2[j];
		j++;
	}
	append[i + j] = '\0';
	return (append);
}
