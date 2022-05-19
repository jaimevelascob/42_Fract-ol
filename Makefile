CC = gcc
CFLAGS = -Wall -Wextra -Werror  -Ofast -fsanitize=address
MLX = -lmlx -framework OpenGL -framework Appkit

SRC := src/fractol.c src/color.c src/mandel_set.c src/julia_set.c  src/hooks.c src/init_sets.c 
OBJ := $(SRC:.c=.o)

%.o%.c : $(SRC)
	@echo "estamos..."
	@$(CC) $(CFLAGS) $(MLX)

all: fractol

fractol: $(OBJ)
	@echo "compiling..."
	@$(CC) $(CFLAGS) $(OBJ) $(MLX)
clean:
	@echo "cleaning..."
	@rm -f a.out
fclean: clean
	@rm -f src/fractol.o src/color.o src/mandel_set.o src/julia_set.o src/hooks.o src/init_sets.o

re: fclean all

.PHONY: clean fclean re default
