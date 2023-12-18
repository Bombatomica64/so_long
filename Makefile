NAME = so_long

MLX_DIR = ./minilibx
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -lX11 -lXext -lm

CC = cc -Wall -Wextra -Werror

SRC = so_long.c


#OBJ = $(SRC:.c=.o)

FT_PRINTF = ft_printf

all: $(NAME)

$(NAME):
	@make all -C $(FT_PRINTF)
	@$(CC) $(SRC) ft_printf/libftprintf.a -o $@
	@echo "Compiled "$(NAME)" successfully!"

#%.o: %.c \
	@$(CC) -c $< -o $@

clean:
	@make clean -C $(FT_PRINTF)
	@echo "Cleaned objects successfully!"
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(FT_PRINTF)
	@echo "Cleaned "$(NAME)" successfully!"
	
re: fclean all
	make re -C $(FT_PRINTF)

replay:
	@rm -f $(NAME)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo "Let's play !!"

.PHONY: all clean fclean bonus re