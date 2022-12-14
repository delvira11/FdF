CC=gcc -g
NAME=fdf
MLX_LIB=MLX42/libmlx42.a
LIBFT=libft/libft.a
CFLAGS=-Wall -Wextra -Werror
LIBRARIES= -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib" -lm -framework OpenGL
SRC=main.c drawlines.c printdots.c utils.c
OBJ=$(SRC:.c=.o)

# $@ .o
# $< .c

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): mlx libft $(OBJ)
	$(CC) $(CFLAGS) $(LIBRARIES) $(OBJ) $(LIBFT) $(MLX_LIB) -o $(NAME)

.PHONY: mlx libft cd all clean fclean re

libft:
	make -C libft

mlx:
	make -C MLX42

all: $(NAME)

clean:
	rm -rf $(OBJ)
	make -C MLX42 clean
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C MLX42 fclean
	make -C libft fclean

re: clean fclean all

push:
	git add .
	git status
	git commit -m "antes de destruirlo1"
	git push -u origin main