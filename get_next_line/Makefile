CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line.a
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -r $(NAME) $?

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
