# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 14:49:07 by sjones            #+#    #+#              #
#    Updated: 2018/05/07 23:58:35 by sjones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_PATH = src
SRC_FILE = main.c \
		add_node.c \
		error.c \
		free.c \
		list.c \
		ls.c \
		parse.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILE))

OBJ = $(SRC_FILE:.c=.o)

LIBFT = libft/libftprintf.a

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft/
	$(CC) $(SRC) $(LIBFT) -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf obj
	@echo "cleaned up objects"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "binary removed"

re: fclean all
