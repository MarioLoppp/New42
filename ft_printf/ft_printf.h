/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlope3 <marlope3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:26:40 by marlope3          #+#    #+#             */
/*   Updated: 2026/09/29 12:26:40 by marlope3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef	struct	s_flags
{
	char	left_align;
	char	zero;
	char	hash;
	char	plus;
	char	space;
	char	dot;
	char	ignore;
	int		width;
	int		precision;
}	t_flags;

int	ft_printf(const char *format, ...);
int	parse(char letter, va_list arguments_list);

#endif