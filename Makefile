#Makefile by Mason

NAME = printf_test

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = main.c \
		ft_printf.c

OBJ = $(addprefix build/, $(FILES:.c=.o))
SRC = $(addprefix src/, $(FILES))

FRAMEWORKS = -framework OpenGL -framework AppKit
INC = -I ./include

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "Creating $(NAME)"

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

test: $(NAME)
	./$(NAME)

re: fclean all
