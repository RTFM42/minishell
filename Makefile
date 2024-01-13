# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 16:07:14 by yushsato          #+#    #+#              #
#    Updated: 2024/01/13 16:46:09 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ./src/main.c \
		  ./src/ms_token.c \
		  ./src/ms_signal.c \
		  ./src/ms_env.c \
		  ./src/dms_token.c \
		  ./src/dms_env.c \
		  ./src/builtin/echo.c \
		  ./src/builtin/pwd.c \
		  ./src/builtin/env.c \
		  ./src/builtin/export_utils.c \
		  ./src/builtin/env_utils.c \
		  ./src/builtin/exit.c \
		  ./src/builtin/builtin.c \
		  ./src/builtin/built_utils.c \
		  ./src/builtin/cd.c \
		  ./src/builtin/unset.c \
		  ./src/builtin/export.c \
		  ./src/lexer/lxr_semicolon.c \
		  ./src/lexer/lxr_token.c \
		  ./src/lexer/lxr_redirect.c \
		  ./src/lexer/lxr_lexer.c \
		  ./src/lexer/lxr_pipe.c
	
OBJS	= $(SRCS:.c=.o)
RLDIR	= $(shell brew --prefix readline)
LIBFT	= libft.a
PRINTF	= ftprintf.a
RLFLAGS	= -lreadline -L$(RLDIR)/lib
INCLUDE	= -I./ -I./src -I$(RLDIR)/include

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(INCLUDE) $(CFLAGS) $(RLFLAGS) $^ -o $@

$(LIBFT):
		cd lib && cd libft && make all && cp $@ ../../ && make fclean;

$(PRINTF):
		cd lib && cd ft_printf && make all && cp $@ ../../ && make fclean;

readline:
	brew install readline

all: readline $(NAME)

clean:
	rm -rf $(OBJS) $(LIBFT) $(PRINTF)

fclean: clean
	rm -f $(NAME)

re: fclean all

build: all clean

__debug_configure__:
	$(eval CC := gcc)
	$(eval CFLAGS := -g -fsanitize=address -Wall -Wextra -Werror)

debug: __debug_configure__ all

norminette: $(SRCS)
	norminette $^ minishell.h

norm: norminette

.PHONY: all clean fclean re build debug norminette norm
