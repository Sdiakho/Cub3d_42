CC = cc
NAME        = cub3D

CFLAGS      = -Wall -Wextra -Werror
CPPFLAGS    = -Iincludes
RM          = rm -f

SRC_DIR     = src
OBJ_DIR     = obj

# List every source file explicitly (no wildcard)
SRCS        = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/parse_map.c \
	$(SRC_DIR)/validate_map.c \
	$(SRC_DIR)/render.c \
	$(SRC_DIR)/raycast.c \
	$(SRC_DIR)/events.c \
	$(SRC_DIR)/utils.c

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Example MLX setup (adjust to your machine/project)
MLX_DIR     = minilibx-linux
MLX_A       = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	@rmdir $(OBJ_DIR) 2>/dev/null || true
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re