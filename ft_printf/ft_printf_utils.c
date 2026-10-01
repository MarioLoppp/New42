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

#include "ft_printf.h"

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
