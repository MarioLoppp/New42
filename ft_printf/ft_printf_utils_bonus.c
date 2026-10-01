/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 20:51:18 by marlope3          #+#    #+#             */
/*   Updated: 2026/09/30 20:51:18 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	apply_priorities(t_flags *flags, int c)
{
	if (flags->left_align)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	if (flags->dot && (c == 'd' || c == 'i'
			|| c == 'u' || c == 'x' || c == 'X'))
		flags->zero = 0;
}

int	unsigned_int_print(unsigned int n, t_flags flags)
{
	flags.plus = 0;
	flags.space = 0;
	return (decimal_print(ft_unsigned_itoa(n), flags));
}

int	numlen(int n)
{
	int	c;

	c = 0;
	if (n <= 0)
		c++;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

int	pointer_nil(t_flags flags)
{
	flags.dot = 0;
	return (string_print("(nil)", flags));
}
