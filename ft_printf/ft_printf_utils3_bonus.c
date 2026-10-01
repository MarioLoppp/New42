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

#include "ft_printf_bonus.h"

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

int	decimal_content_len(char *str, t_flags flags)
{
	int	length;

	length = ft_strlen(str);
	if (*str == '-')
		length--;
	if (flags.dot && flags.precision == 0 && str[0] == '0')
		length = 0;
	if (flags.dot && flags.precision > length)
		length = flags.precision;
	if (*str == '-' || flags.plus || flags.space)
		length++;
	return (length);
}

void	int_print_content(char *str, t_flags flags)
{
	char	sign;
	int		digits;

	sign = flags.space * ' ';
	if (flags.plus)
		sign = '+';
	if (*str == '-')
		sign = *str++;
	digits = ft_strlen(str);
	if (flags.dot && flags.precision == 0 && *str == '0')
		digits = 0;
	if (sign)
		write(1, &sign, 1);
	if (flags.zero && flags.width - (sign != 0) > flags.precision)
		flags.precision = flags.width - (sign != 0);
	while (flags.precision > digits)
	{
		write(1, "0", 1);
		flags.precision--;
	}
	write(1, str, digits);
}

int	int_print(int n, t_flags flags)
{
	return (decimal_print(ft_itoa(n), flags));
}
