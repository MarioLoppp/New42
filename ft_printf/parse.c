/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 15:57:07 by marlope3          #+#    #+#             */
/*   Updated: 2026/09/29 15:57:07 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width_precision(const char *letter, t_flags *flags, int *count)
{
	int	i;

	i = 0;
	if (letter[i] >= '1' && letter[i] <= '9')
	{
		while (ft_isdigit(letter[i]))
		{
			flags->width = flags->width * 10
				+ (letter[i] - '0');
			i++;
		}
	}
	if (letter[i] == '.')
	{
		flags->dot = 1;
		i++;
		while (ft_isdigit(letter[i]))
		{
			flags->precision = flags->precision * 10
				+ (letter[i] - '0');
			i++;
		}
	}
	if (ft_strchr("cspdiuxX%", letter[i]))
		*count += i;
}

void	fill_flags(int c, t_flags *flags)
{
	if (c == '-')
		flags->left_align = 1;
	else if (c == '#')
		flags->hash = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '0')
		flags->zero = 1;
}

void	init_flags(t_flags *flags)
{
	flags->left_align = 0;
	flags->zero = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->dot = 0;
	flags->ignore = 0;
	flags->width = 0;
	flags->precision = 0;
}

void	check_flags(const char *letter, t_flags *flags, int *i)
{
	char	*basic_flags;
	char	*end_flags;
	int		count;

	basic_flags = "-0# +";
	end_flags = "cspdiuxX%";
	count = 0;
	while (ft_strchr(basic_flags, letter[*i + count]))
	{
		fill_flags(letter[*i + count], flags);
		count++;
	}
	check_width_precision(&letter[*i + count], flags, &count);
	if (ft_strchr(end_flags, letter[*i + count]))
		*i += count;
	else
		flags->ignore = 1;
}

int	parse(const char *letter, va_list argument_list, int *i)
{
	t_flags	flags;

	init_flags(&flags);
	check_flags(letter, &flags, i);
	if (letter[*i] == 'c')
		return (char_print(va_arg(argument_list, int), flags));
	else if (letter[*i] == 's')
		return (string_print(va_arg(argument_list, char *), flags));
	else if (letter[*i] == 'p')
		return (x(va_arg(argument_list, void *), flags));
	else if (letter[*i] == 'd' || letter[*i] == 'i')
		return (number_print(va_arg(argument_list, int), flags));
	else if (letter[*i] == 'u')
		return (unsigned_number_print(va_arg(argument_list, unsigned int), flags));
	else if (letter[*i] == 'x' || letter[*i] == 'X')
		return (y(va_arg(argument_list, unsigned int), letter[*i], flags));
	else if (letter[*i] == '%')
		return (z(div_print(flags)));
	return (0);
}
