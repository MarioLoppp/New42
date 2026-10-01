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

int	char_print(char a, t_flags flags)//Aposta para warning no se si hay que printear null aqui en caso malo
{
	int	count;

	count = 1;
	if (flags.left_align)
		write(1, &a, 1);
	while (flags.width > 1)
	{
		write(1, " ", 1);
		flags.width--;
		count++;
	}
	if (!flags.left_align)
		write(1, &a, 1);
	return (count);
}

int	string_print(char *str, t_flags flags)
{
	int	length;
	int	count;

	count = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	if (flags.precision)
		length = flags.precision;
	else
		length = ft_strlen(str);
	if (flags.left_align)
		write (1, str, length);
	while (flags.width > 1)
	{
		write(1, " ", 1);
		flags.width--;
		count++;
	}
	if (!flags.left_align)
		write (1, str, length);
	return (length + count);
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
