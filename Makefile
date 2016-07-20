NAME = minishell

SRC = src/main.c libft/libft.a

FLAGS = clang -Werror -Wextra -Wall -I includes -o

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/ all
	$(FLAGS) $(NAME) $(SRC)

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
