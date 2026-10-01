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

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
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
int		char_print(char c, t_flags flags);
int		string_print(char *string, t_flags flags);
void	put_hex(unsigned long number, char letter, char prefix);
int		pointer_to_hexadecimal(void *pointer, t_flags flags);
char	*ft_unsigned_itoa(unsigned int number);
int		hex_len(unsigned long number, char prefix);
int		int_to_hexadecimal(unsigned int number, char type, t_flags flags);
int		unsigned_numlen(unsigned int number);
int		int_print(int number, t_flags flags);
int		unsigned_int_print(unsigned int number, t_flags flags);
int		numlen(int n);
int		pointer_nil(t_flags flags);
void	hex_print_content(unsigned int number, char letter, t_flags flags);
int		decimal_content_len(char *str, t_flags flags);
void	int_print_content(char *str, t_flags flags);
int		decimal_print(char *str, t_flags flags);

#endif
