NAME    =   fdf

CC      =   gcc
FLAGS   =   -Wall -Wextra -Werror
MLX     =   -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
LFT     =   -L libft -lft

SRC     =   *.c
OBJ     =   $(SRC:%.c=%.o)
INCL    =  fdf.h

all: $(NAME)

$(NAME):
	@echo "\033[1;33mFDF: Sources compiling... \033[0m"
	@make -C libft/
	@$(CC) $(FLAGS) -I $(INCL) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(LFT) $(MLX)
	@echo "\033[1;34mFDF: Compiled with success..!\033[0m"

clean:
	@make -C libft/ clean
	@/bin/rm -rf $(OBJ)
	@echo "\033[0;36mObjects removed...\033[0m"

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[0;36mFDF binary removed...\033[0m"

re: fclean all