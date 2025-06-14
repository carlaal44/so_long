NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. # Ya hemos arreglado esto para minilibx

# --- NUEVAS LÍNEAS PARA LA LIBFT ---
# Ruta a tu carpeta de libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
# Incluimos los headers de libft
CFLAGS += -I$(LIBFT_DIR) # Añade el directorio de headers de libft a la búsqueda

MLX = minilibx-linux/libmlx.a
MLX_DIR = minilibx-linux

SRCS = so_long.c map.c game.c player.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

# Regla para compilar libft si no existe (importante!)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) # Depende de libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) -L$(MLX_DIR) -lXext -lX11

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean # También limpia los objetos de libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean # También limpia libft.a

re: fclean all