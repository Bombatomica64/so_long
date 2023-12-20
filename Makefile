NAME = so_long

MLX_DIR = ./minilibx
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -lX11 -lXext -lm

CC = cc

SRC = flood_fill.c  ft_error_free_map.c  ft_errors.c  \
	map_check.c  prova.c  put_images.c  read_map.c  so_long.c \
	bad_next_line.c get_entity.c


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