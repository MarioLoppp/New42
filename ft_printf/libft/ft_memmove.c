/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 00:01:09 by marlope3          #+#    #+#             */
/*   Updated: 2026/09/23 16:42:50 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*temp;

	if (!dst && !src)
		return (NULL);
	i = 0;
	temp = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	if (dst2 < temp)
	{
		while (i < len)
		{
			dst2[i] = temp[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
		{
			dst2[len] = temp[len];
		}
	}
	return (dst);
}
