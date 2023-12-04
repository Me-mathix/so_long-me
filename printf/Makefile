NAME = libftprintf.a

SRC = ft_printf.c \
		ft_printf_utils.c \
		./format/print_char.c \
		./format/print_lhex.c \
		./format/print_uhex.c \
		./format/print_nbr.c \
		./format/print_unbr.c \
		./format/print_pointer.c \
		./format/print_str.c \

SRCB = 

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

FLAGS = -Wall -Wextra -Werror  

ARC = ar rcs

CC = cc

INCLUDE = ./

.c.o:
		$(CC) $(FLAGS) -c $< -o ${<:.c=.o} -I $(INCLUDE)

$(NAME): ${OBJ}
		$(ARC) $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: ${OBJB} ${OBJ}
	$(ARC) $(NAME) $(OBJB) $(OBJ)

.PHONY : all clean fclean re so bonus
