/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 05:59:33 by marlope3          #+#    #+#             */
/*   Updated: 2026/09/19 13:29:24 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*x;
	unsigned char	*y;

	if (nmemb && nmemb * size > MAX_INTEGER)
		return (NULL);
	x = malloc(nmemb * size);
	if (!x)
		return (NULL);
	y = (unsigned char *)x;
	while (*y)
	{
		*y = '\0';
		y++;
	}
	return (x);
}
