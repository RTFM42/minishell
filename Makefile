NAME	= minishell
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
LIBFT	= libft.a
PRINTF	= ftprintf.a

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $^ $(INCLUDE) -o $@

all: $(NAME)

clean:
	rm -rf  $(OBJS) $(LIBFT) $(PRINTF)

fclean:
	rm -f $(NAME)

re: fclean all

build: all clean

__debug_configure__:
	$(eval CC := gcc)
	$(eval CFLAGS := -g -fsanitize=address -Wall -Wextra -Werror)

debug: __debug_configure__ all

norminette: $(SRCS)
	norminette $^

norm: norminette

.PHONY: all clean fclean re build debug norminette norm