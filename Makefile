NAME = so_long

RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
CLEAR	=	\033[0m

CC = cc
RM = rm -f

CFLAGS = -Wall -Werror -Wextra -g3

LIBFT_DIR = libft
GNL_DIR = $(LIBFT_DIR)/gnl
MLX_DIR = minilibx-linux

LIBFTA = $(LIBFT_DIR)/libft.a
MLX_LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCS = \
	src/so_long.c \
	src/map/map.c \
	src/game.c \
	src/player.c \
	src/utils.c \
	src/draw/drawing_utils.c \
	src/events.c \
	src/map/map_helpers.c \
	src/map/map_validation.c \
	src/map/path_validation.c \
	src/game_constants.c \
	$(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I. -Iincludes -I$(LIBFT_DIR)/includes -I$(MLX_DIR)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(LIBFTA) $(OBJS)
	@echo "$(YELLOW)=== Compilando y Enlazando $(NAME)... ===$(CLEAR)"
	@make -sC $(LIBFT_DIR)
	@make -sC $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTA) $(MLX_LIBS) -o $(NAME)
	@echo "$(GREEN)=== $(NAME) Compilado Exitosamente! ===$(CLEAR)"

$(LIBFTA) :
	@echo "$(YELLOW)=== Construyendo Libft... ===$(CLEAR)"
	$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJS)
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(MLX_DIR)
	@echo "$(RED)--- Todos los archivos objeto (.o) eliminados. ---$(CLEAR)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFTA)
	@make clean -sC $(MLX_DIR) # ¡CAMBIO AQUÍ! Corregido de $(MLMLX_DIR) a $(MLX_DIR)
	@echo "$(RED)--- Todo el proyecto (ejecutables y librerías) eliminado. ---$(CLEAR)"

re: fclean all

.PHONY: all clean fclean re $(LIBFTA)
