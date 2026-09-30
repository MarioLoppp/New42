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
	if (flags->dot && (type == 'd' || type == 'i'
			|| type == 'u' || type == 'x' || type == 'X'))
		flags->zero = 0;
}