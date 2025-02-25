NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = minilibx-linux/libmlx.a
MLX_DIR = minilibx-linux

SRCS = so_long.c map.c game.c player.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) -L$(MLX_DIR) -lXext -lX11

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
