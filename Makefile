NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCDIR))
CFLAGS += -lmlx -framework OpenGL -framework AppKit

INCDIR = ./include
INC = $(shell find $(INCDIR) -name "*.h" -type f | xargs)

SRCDIR = ./srcs
SRCS = $(shell find $(SRCDIR) -name "*.c" -type f | xargs)
OBJS = $(SRCS:%.c=%.o)

UTILDIR = ./utils
UTILS = $(shell find $(UTILDIR) -name "*.c" -type f | xargs)
UTILS_OBJ = $(UTILS:%.c=%.o)

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

$(NAME): $(OBJS) $(UTILS_OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(SRCS) $(UTILS) $(LIB) -o $(NAME)

$(LIBFT):
		$(MAKE) -C ./libft

all: $(NAME)

clean:
		$(MAKE) fclean -C ./libft
		$(RM) $(OBJS) $(B_OBJS) $(UTILS_OBJ)

fclean: clean
		$(RM) $(NAME) $(LIBFT)

re: fclean all

debug: CFLAGS += -g -fsanitize=address,leak
debug: re

.PHONY: all clean fclean re bonus norm debug
