/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 00:51:52 by marlope3          #+#    #+#             */
/*   Updated: 2026/10/01 00:51:52 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	hexmaxmin_print(unsigned int n, char c)
{
	if (n == 0)
		return (write(1, "0", 1));
	put_hex(n, c);
	return (hex_len(n));
}

int	unsigned_numlen(unsigned int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

int	prc_print(void)
{
	write(1, "%", 1);
	return (1);
}