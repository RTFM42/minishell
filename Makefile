# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 16:07:14 by yushsato          #+#    #+#              #
#    Updated: 2023/12/11 17:50:15 by yushsato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= cc
CFLAGS	= -lreadline -Wall -Wextra -Werror
SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
INCLUDE	= -I./
LIBFT	= libft.a
PRINTF	= ftprintf.a


%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $^ $(INCLUDE) -o $@

$(LIBFT):
		cd lib && cd libft && make all && cp $@ ../../ && make fclean;

$(PRINTF):
		cd lib && cd ft_printf && make all && cp $@ ../../ && make fclean;

all: $(NAME)

clean:
	rm -rf $(OBJS) $(LIBFT) $(PRINTF)

fclean: clean
	rm -f $(NAME)

re: fclean all

build: all clean

__debug_configure__:
	$(eval CC := gcc)
	$(eval CFLAGS := -g -fsanitize=address -Wall -Wextra -Werror -lreadline)

debug: __debug_configure__ all

norminette: $(SRCS)
	norminette $^

norm: norminette

.PHONY: all clean fclean re build debug norminette norm
