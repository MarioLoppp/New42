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

#include "ft_printf_bonus.h"

int	char_print(char a, t_flags flags)
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
		if (flags.dot && flags.precision < 6)
			str = "";
		else
			str = "(null)";
	}
	length = ft_strlen(str);
	if (flags.dot && flags.precision < length)
		length = flags.precision;
	if (flags.left_align)
		write (1, str, length);
	while (flags.width > length)
	{
		write(1, " ", 1);
		flags.width--;
		count++;
	}
	if (!flags.left_align)
		write (1, str, length);
	return (length + count);
}

int	pointer_to_hexadecimal(void *ptr, t_flags flags)
{
	unsigned long	n;
	int				length;
	int				count;

	if (!ptr)
		return (pointer_nil(flags));
	n = (unsigned long)ptr;
	length = hex_len(n, 1);
	count = 0;
	if (flags.left_align)
		put_hex(n, 'x', 1);
	while (flags.width > length)
	{
		write(1, " ", 1);
		flags.width--;
		count++;
	}
	if (!flags.left_align)
		put_hex(n, 'x', 1);
	return (length + count);
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

int	decimal_print(char *str, t_flags flags)
{
	int	length;
	int	count;

	if (!str)
		return (0);
	length = decimal_content_len(str, flags);
	count = 0;
	if (flags.left_align)
		int_print_content(str, flags);
	while (count < flags.width - length)
	{
		if (!flags.zero)
			write(1, " ", 1);
		count++;
	}
	if (!flags.left_align)
		int_print_content(str, flags);
	free(str);
	return (length + count);
}
