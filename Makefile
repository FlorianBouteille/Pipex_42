CC = cc
CFLAGS = -Wall -Wextra -Werror

# Dossiers
LIBFT_DIR = ./shared_libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = ./src
OBJ_DIR = ./obj

# Fichiers sources
SRC = main.c path.c path2.c redirect.c exec_commands.c check_and_free.c split_commands.c split_commands2.c utils.c
SRC_BONUS = main_bonus.c path.c path2.c redirect.c exec_commands.c check_and_free.c split_commands.c split_commands2.c utils.c
# Objets
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS:.c=.o))

# Nom des exécutables
NAME = pipex

# Règles de compilation
all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
