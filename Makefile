NAME = fillit
NAME_SRC = main.c get_tetriminos.c fillit.c create_point.c map.c place_tetrimino.c tetrimino.c tetrimino_lst.c valid_tetrimino.c
PATH_SRC = ./srcs/
SRC = $(addprefix $(PATH_SRC),$(NAME_SRC))
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
INCLUDE = ./includes

all: $(NAME)

$(NAME): $(SRC)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(SRC) -I$(INCLUDE) -L. libft/libft.a

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean:
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: clean fclean all re