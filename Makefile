CC = gcc
CFLAGS = -Wall -Wextra -Werror  -Ofast -flto -fsanitize=address
MLX_PATH = minilibx_mms_20200219/ 
MLX = -lmlx -framework OpenGL -framework Appkit
SRC := src/fractol.c src/color.c src/mandel_set.c src/julia_set.c src/hooks.c src/init_sets.c src/newset.c 
OBJ := $(SRC:.c=.o)

all: fractol

fractol: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o fractol 

clean:
	@rm -f fractol 
fclean: clean
	@rm -f $(OBJ) 

re: fclean all

.PHONY: clean fclean re 
