/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 00:50:58 by marlope3          #+#    #+#             */
/*   Updated: 2026/10/01 00:50:58 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ch_print(char a)
{
	write(1, &a, 1);
	return (1);
}

int	str_print(char *str)
{
	int	l;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	l = ft_strlen(str);
	write (1, str, l);
	return (l);
}

void	put_hex(unsigned long n, char c)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (c == 'l')
		hex = "0123456789abcdef";
	if (n >= 16)
		put_hex(n / 16, c);
	write(1, &hex[n % 16], 1);
}

int	hex_print(void *ptr)
{
	unsigned long	n;

	if (!ptr)
		return (write(1, "(nil)", 5));
	n = (unsigned long)ptr;
	write(1, "0x", 2);
	put_hex(n, 'l');
	return (2 + hex_len(n));
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*str;
	int		len;

	len = unsigned_numlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	int_print(int n)
{
	char	*str;
	int		i;

	str = ft_itoa(n);
	if (!str)
		return (0);
	i = ft_strlen(str);
	write (1, str, i);
	free (str);
	return (i);
}

int	unsint_print(unsigned int n)
{
	char	*str;
	int		i;

	str = ft_unsigned_itoa(n);
	if (!str)
		return (0);
	i = ft_strlen(str);
	write (1, str, i);
	free (str);
	return (i);
}