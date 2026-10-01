/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:19:36 by marlope3          #+#    #+#             */
/*   Updated: 2026/10/01 14:19:36 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	hex_print_content(unsigned int number, char letter, t_flags flags)
{
	int	digits;

	digits = hex_len(number, 0);
	if (flags.dot && flags.precision == 0 && number == 0)
		digits = 0;
	if (flags.zero && flags.width - (flags.hash * 2) > flags.precision)
		flags.precision = flags.width - (flags.hash * 2);
	if (flags.hash)
	{
		if (letter == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
	while (flags.precision > digits)
	{
		write(1, "0", 1);
		flags.precision--;
	}
	if (digits)
		put_hex(number, letter, 0);
}

int	int_to_hexadecimal(unsigned int number, char letter, t_flags flags)
{
	int	length;
	int	count;

	flags.hash = (flags.hash && number != 0);
	length = hex_len(number, 0);
	if (flags.dot && flags.precision == 0 && number == 0)
		length = 0;
	if (flags.dot && flags.precision > length)
		length = flags.precision;
	length += flags.hash * 2;
	if (flags.width > length)
		count = flags.width - length;
	else
		count = 0;
	if (flags.left_align)
		hex_print_content(number, letter, flags);
	while (!flags.zero && flags.width > length)
	{
		write(1, " ", 1);
		flags.width--;
	}
	if (!flags.left_align)
		hex_print_content(number, letter, flags);
	return (length + count);
}

void	put_hex(unsigned long number, char letter, char prefix)
{
	char	*hex;

	if (prefix)
	{
		write(1, "0x", 2);
		prefix = 0;
	}
	hex = "0123456789ABCDEF";
	if (letter == 'x')
		hex = "0123456789abcdef";
	if (number >= 16)
		put_hex(number / 16, letter, prefix);
	write(1, &hex[number % 16], 1);
}

int	hex_len(unsigned long n, char prefix)
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
	if (prefix)
		i += 2;
	return (i);
}
