# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 16:07:14 by yushsato          #+#    #+#              #
#    Updated: 2024/03/08 20:51:47 by yushsato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ./src/ms_token.c \
		  ./src/ms_signal.c \
		  ./src/main.c \
		  ./src/lexer/lxr_pipe.c \
		  ./src/lexer/lxr_token.c \
		  ./src/lexer/lxr_semicolon.c \
		  ./src/lexer/lxr_redirect.c \
		  ./src/lexer/lxr_lexer.c \
		  ./src/parser/psr_parser.c \
		  ./src/parser/psr_status.c \
		  ./src/dms_token.c \
		  ./src/dms_lxrtochar2.c \
		  ./src/dms_env.c \
		  ./src/builtin/pwd.c \
		  ./src/builtin/export.c \
		  ./src/builtin/export_utils.c \
		  ./src/builtin/export_utils2.c \
		  ./src/builtin/exit.c \
		  ./src/builtin/env_utils.c \
		  ./src/builtin/env_store.c \
		  ./src/builtin/env.c \
		  ./src/builtin/echo.c \
		  ./src/builtin/cd.c \
		  ./src/builtin/unset.c \
		  ./src/builtin/builtin.c \
		  ./src/builtin/built_utils.c

OBJS	= $(SRCS:.c=.o)
RLDIR	= $(shell brew --prefix readline)
LIBFT	= libft.a
PRINTF	= ftprintf.a
EPRINTF	= fteprintf.a
RLFLAGS	=  -L$(RLDIR)/lib -lreadline
INCLUDE	= -I./ -I./src -I$(RLDIR)/include

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(EPRINTF)
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDE) $(RLFLAGS)

$(LIBFT):
		cd lib          && \
		cd libft        && \
		make all        && \
		cp $@ ../../    && \
		make fclean

$(PRINTF):
		cd lib          && \
		cd ft_printf    && \
		make all        && \
		cp $@ ../../    && \
		make fclean

$(EPRINTF):
		cd lib          && \
		cd ft_eprintf    && \
		make all        && \
		cp $@ ../../    && \
		make fclean

readline:
	brew install readline

all: readline $(NAME)

clean:
	rm -rf $(OBJS) $(LIBFT) $(PRINTF) $(EPRINTF)

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
