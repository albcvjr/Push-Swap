NAME	= push_swap

INCLUDE_DIR	= includes/

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC_DIR	= ./src
SRC_FILES	= benchmark_manager.c data_utils.c front_last_utils.c \
			ft_printfe.c last_front_utils.c list_utils.c main.c \
			push_utils.c sort_algorithms.c str_utils.c swap_utils.c
SRCS		= $(addprefix $(SRC_DIR)/,$(SRC_FILES))


TEST_DIR	= ./tests
TEST_FILES	= main.c
TEST_SRCS	= $(addprefix $(TEST_DIR)/,$(TEST_FILES)) $(addprefix $(SRC_DIR)/,$(filter-out main.c, $(SRC_FILES)))

CC=cc
CFLAGS=-Wall -Wextra -Werror -I$(INCLUDE_DIR)

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

test: $(LIBFT)
	$(CC) $(CFLAGS) $(TEST_SRCS) $(LIBFT) -o $(NAME)
	./$(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.SUFFIXES:
.PHONY: all clean fclean re
