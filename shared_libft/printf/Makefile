NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c print_char.c print_nbr.c print_str.c print_hexa.c print_adress.c print_unsigned.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(AR) $(NAME) $(OBJS) $(LIBFT_DIR)/*.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
