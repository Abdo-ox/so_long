CC = gcc
NAME = so_long
C_FLAGS = -Wall -Wextra -Werror
SRC = movement.c image.c\
	count_functiones.c\
	utils.c\
	check_map.c\
	check_map_1.c\
	main.c
SRCB = movement_bonus.c\
	image_bonus.c\
	count_functiones_bonus.c\
	utils_bonus.c\
	check_map_bonus.c\
	check_map_1_bonus.c\
	main_bonus.c\
	game_over_bonus.c\
	animation_bonus.c
NAME_FT = ./libft/libft.a
NAME_GET = ./get_next_line/get_next_line.a
NAME_PRINTF = ./ft_printf/libftprintf.a
LINKS =-I /usr/local/include
LINKS_L = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

$(NAME): $(OBJ) $(NAME_FT) $(NAME_GET) $(NAME_PRINTF)
	$(CC) $(C_FLAGS) $(LINKS) $(OBJ) $(NAME_FT) $(NAME_PRINTF) $(NAME_GET) $(LINKS_L) -o $(NAME)

$(NAME_FT):
	make all bonus clean -C ./libft

$(NAME_GET):
	make all clean -C ./get_next_line

$(NAME_PRINTF):
	make all clean -C ./ft_printf

%.o:%.c
	$(CC) $(C_FLAGS) -c $< -o $@

all : $(NAME)

bonus: $(NAME_FT) $(NAME_GET) $(NAME_PRINTF) $(OBJB)
	$(CC) $(C_FLAGS) $(LINKS) $(OBJB) $(NAME_FT) $(NAME_PRINTF) $(NAME_GET) $(LINKS_L) -o $(NAME)


clean :
	rm -rf $(OBJ) $(OBJB)

fclean : clean fcleanft fcleanget fcleanpr
	rm -rf $(NAME)

fcleanft:
	make fclean -C ./libft

fcleanpr:
	make fclean -C ./ft_printf

fcleanget:
	make fclean -C ./get_next_line

re : fclean all clean
