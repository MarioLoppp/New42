NAME = libftprintf.a

SRCS = ft_printf.c parse.c ft_printf_utils.c ft_printf_utils2.c \
	ft_printf_utils3.c
LIBFT_SRCS = $(wildcard libft/*.c)

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

%.o: %.c ft_printf.h libft/libft.h
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

libft/%.o: libft/%.c libft/libft.h
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:
	rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
