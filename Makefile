NAME = so_long

MLX_DIR = ./minilibx
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -lX11 -lXext -lm

CC = cc -Wall -Wextra -Werror

SRC = so_long.c put_images.c


#OBJ = $(SRC:.c=.o)

FT_PRINTF = ft_printf

all: $(NAME)

$(NAME):
	@make all -C $(FT_PRINTF)
	@make all -C $(MLX_DIR)
	@$(CC) $(SRC) ft_printf/libftprintf.a $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo "Compiled "$(NAME)" successfully!"

#%.o: %.c \
	@$(CC) -c $< -o $@

clean:
	@make clean -C $(FT_PRINTF)
	@echo "Cleaned objects successfully!"
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(FT_PRINTF)
	@make clean -C $(MLX_DIR)
	@echo "Cleaned "$(NAME)" successfully!"
	
re: fclean all
	make re -C $(FT_PRINTF)

replay:
	@rm -f $(NAME)
	@$(CC) $(SRC) ft_printf/libftprintf.a $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo "Let's  gooo!!"

.PHONY: all clean fclean bonus re replay