/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:34:12 by marlope3          #+#    #+#             */
/*   Updated: 2026/09/29 12:34:12 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list	argument_list;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(argument_list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
			{
				i++;
				count += parse(format, argument_list, &i);
			}
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(argument_list);
	return (count);
}
