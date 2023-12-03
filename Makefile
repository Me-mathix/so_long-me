NAME		=	so_long

CC			=	cc

FLAG		=	-Wall -Wextra -Werror -g3

LIBFT_PATH	=	./libft/

LIBFT_FILE	=	libft.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

PRINTF_PATH	=	./printf/

PRINTF_FILE	=	libftprintf.a

PRINTF_LIB	=	$(addprefix $(PRINTF_PATH), $(PRINTF_FILE))

MLX_FILE	=	libmlx.a

MLX_FLAG	=	-lX11 -lXext

MLX_PATH	=	./minilibx-linux/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

SRC			=	main.c \
				parse.c

INC_DIR		=	./

OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

pri:
	@echo "\033[0;33m\nCOMPILING $(PRINTF_PATH)\n"
	@make -C $(PRINTF_PATH)
	@echo "\033[1;32mPRINTF_lib created\n"

lib:
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT_lib created\n"

mlx:
	@echo "\033[0;33m\nCOMPILING $(MLX_PATH)...\n"
	@make -sC $(MLX_PATH)
	@echo "\033[1;32mMLX_lib created\n"

$(NAME): lib pri mlx $(OBJ)
	@echo "\033[0;33m\nCOMPILING SO_LONG...\n"
	$(CC) $(OBJ) $(LIBFT_LIB) $(PRINTF_LIB) $(MLX_EX) -o $(NAME)
	@echo "\033[1;32m./so_long created\n"

clean:
	@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
	@make clean -sC $(MLX_PATH)
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[0;31mDeleting Obj file in $(PRINTF_PATH)...\n"
	@make clean -sC $(PRINTF_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting So_long object...\n"
	@rm -f $(OBJ)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting so_long executable..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(PRINTF_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re