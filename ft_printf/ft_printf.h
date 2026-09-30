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
# include <unistd.h>
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

int		ft_printf(const char *format, ...);
int		parse(const char *letter, va_list arguments_list, int *i);
void	apply_priorities(t_flags *flags, int c);
void	check_width_precision(const char *letter, t_flags *flags, int *count);
void	fill_flags(int c, t_flags *flags);
void	init_flags(t_flags *flags);
void	check_flags(const char *letter, t_flags *flags, int *i);
int		char_print(int c, t_flags flags);
int		string_print(char *string, t_flags flags);
int		x(void *pointer, t_flags flags);
int		number_print(int number, t_flags flags);
int		unsigned_number_print(unsigned int number, t_flags flags);
int		y(unsigned int number, char type, t_flags flags);
int		div_print(t_flags flags);
int		z(int count);

#endif
