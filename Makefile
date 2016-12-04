# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 14:52:14 by myoung            #+#    #+#              #
#    Updated: 2016/12/03 13:53:44 by myoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
INC = -I ./include

MAIN = src/main.c

FILES = guts.c ft_printf.c

OBJ = $(addprefix build/, $(FILES:.c=.o))
SRC = $(addprefix src/, $(FILES))


.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) crs $@ $^
	$(CC) $@ $(MAIN) $(INC)
	echo "Creating $(NAME)"

build/%.o: src/%.c | build
	@echo "Doing things to $@"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

build:
	mkdir build

clean:
	@rm -rf build
	@echo "clean successful"

fclean: clean
	@echo "Removing $(NAME)"
	rm -f $(NAME)

test:
	make re
	./a.out

re: fclean all
