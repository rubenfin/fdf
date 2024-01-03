SRCS_MANDATORY = draw.c ft_split.c main.c read_map.c fill_map.c \
hooks.c move.c safety.c safety2.c window.c math.c color.c math_utils.c fdf_utils.c fdf_utils2.c

OBJS = $(SRCS_MANDATORY:%.c=$(OBJS_DIR)/%.o)
OBJS_DIR = objs

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
RM = rm -rf 
MLXPATH = libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
VPATH = .

INCLUDE = -I./.

NAME = fdf

all: $(NAME)

$(OBJS_DIR)/%.o:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLXPATH) $(INCLUDE)
	@echo "$(GREEN)Compiled mandatory!$(DEFAULT)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(YELLOW)Removed all objects!$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Removed executables!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re


#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m