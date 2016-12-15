# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 14:52:14 by myoung            #+#    #+#              #
#    Updated: 2016/12/14 20:12:53 by myoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
INC = -I ./include

MAIN = src/main.c

FILES = ft_printf.c printf_format.c \
		printf_d.c printf_xsp.c printf_cou.c \
		printf_utils.c printf_len_base.c \
		printf_toa_base_1.c printf_toa_base_2.c \
		printf_strlen_str_char.c \
		printf_wchar.c printf_wchar_utils.c \
		printf_lld.c printf_ulld.c \
		printf_d_hhd.c printf_ud_uhhd.c

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
