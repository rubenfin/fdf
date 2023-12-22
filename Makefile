SRCS_MANDATORY = draw.c fdf_utils.c main.c map.c move.c print.c safety.c window.c

OBJS = $(SRCS_MANDATORY:%.c=$(OBJS_DIR)/%.o)
OBJS_DIR = objs

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -pthread -g 
RM = rm -rf

VPATH = .

INCLUDE = -I./.

NAME = fdf

all: $(NAME)


$(OBJS_DIR)/%.o:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)
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

.PHONY: all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m