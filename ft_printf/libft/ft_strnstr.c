/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 00:01:09 by marlope3          #+#    #+#             */
/*   Updated: 2026/09/23 16:43:53 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	goal;
	size_t	little_len;

	i = 0;
	goal = 0;
	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		goal = 0;
		while (little[goal] && (i + goal) < len
			&& big[i + goal] == little[goal])
			goal++;
		if (goal == little_len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
