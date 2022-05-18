CC = gcc
CFLAGS = -Wall -Wextra -Werror  -Ofast -fsanitize=address
MLX = -lmlx -framework OpenGL -framework Appkit

SRC := fractol.c color.c mandel_set.c julia_set.c  hooks.c init_sets.c 
OBJ := $(SRC:.c=.o)

%.o%.c : $(SRC)
	@echo "estamos..."
	$(CC) $(CFLAGS) $(MLX)

all: fractol

fractol: $(OBJ)
	@echo "compiling..."
	$(CC) $(CFLAGS) $(OBJ) $(MLX)
clean:
	@echo "cleaning..."
	@rm -f a.out
fclean: clean
	@rm -f fractol.o color.o mandel_set.o julia_set.o hooks.o init_sets.o

re: fclean all

.PHONY: clean fclean re default
