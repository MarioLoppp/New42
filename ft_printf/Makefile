NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

SRCS		= ft_printf.c parse.c ft_printf_utils.c ft_printf_utils2.c \
			  ft_printf_utils3.c ft_printf_hexflags.c

BONUS_SRCS	= ft_prinft_bonus.c parse_bonus.c ft_printf_utils_bonus.c \
			  ft_printf_utils2_bonus.c ft_printf_utils3_bonus.c \
			  ft_printf_hexflags_bonus.c

LIBFT_SRCS	= $(wildcard libft/*.c)

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)
BONUS_FLAG	= .bonus_ok

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	$(RM) $(NAME) $(BONUS_FLAG)
	$(AR) $(NAME) $(OBJS) $(LIBFT_OBJS)

bonus: $(BONUS_FLAG)

$(BONUS_FLAG): $(BONUS_OBJS) $(LIBFT_OBJS)
	$(RM) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS) $(LIBFT_OBJS)
	touch $(BONUS_FLAG)

$(OBJS): ft_printf.h libft/libft.h
$(BONUS_OBJS): ft_printf_bonus.h libft/libft.h
$(LIBFT_OBJS): libft/libft.h

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(LIBFT_OBJS) $(BONUS_FLAG)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean fclean re
