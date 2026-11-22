NAME				= libftprintf.a

INCLUDE_DIR = ../../includes/

SRCS	= ft_flag_bad.c ft_flag_c.c ft_flag_d.c ft_flag_i.c \
		ft_flag_p.c ft_flag_s.c ft_flag_u.c ft_flag_x.c \
		ft_flag_xc.c ft_printf.c ft_putuint_map_fd.c ft_putsizet_map_fd.c
OBJS	= $(SRCS:.c=.o)

CC=cc
CFLAGS=-Wall -Wextra -Werror -I$(INCLUDE_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
