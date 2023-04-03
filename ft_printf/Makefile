CC = CC
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_hexa_x.c ft_hexa_xx.c ft_putnbr_fd_u.c ft_putstr_fd_p.c ft_putnbr_fd_p.c ft_putchar_fd_p.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -rc $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
re: fclean all
