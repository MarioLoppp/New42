/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 00:01:09 by marlope3          #+#    #+#             */
/*   Updated: 2026/09/23 16:42:28 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1a;
	unsigned char	*s2a;
	size_t			i;

	i = 0;
	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	while (i < n)
	{
		if (s1a[i] != s2a[i])
			return (s1a[i] - s2a[i]);
		i++;
	}
	return (0);
}
