NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCDIR))
CFLAGS += -lmlx -framework OpenGL -framework AppKit

INCDIR = ./includes
INC = $(shell find $(INCDIR) -name "*.h" -type f | xargs)

SRCDIR = ./srcs
SRCS = $(shell find $(SRCDIR) -name "*.c" -type f | xargs)
OBJS = $(SRCS:%.c=%.o)

# UTILDIR = ./utils
# UTILS = $(shell find $(UTILDIR) -name "*.c" -type f | xargs)
# UTILS_OBJ = $(UTILS:%.c=%.o)

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

MLXDIR = ./minilibx-linux
MLX = $(MLXDIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
		$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBDIR)

$(MLX):
		$(MAKE) -C $(MLXDIR)

clean:
		$(MAKE) fclean -C $(LIBDIR)
		$(MAKE) clean -C $(MLXDIR)
		$(RM) $(OBJS) $(B_OBJS)

fclean: clean
		$(RM) $(NAME) $(LIBFT)

re: fclean all

debug: CFLAGS += -g -fsanitize=address,leak
debug: re

.PHONY: all clean fclean re bonus norm debug
