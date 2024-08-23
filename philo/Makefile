#COLORS
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#PROGRAM NAME | COMPILER | FLAGS 
NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread -fsanitize=thread #-fsanitize=address
RM = rm -fr

#PATHS
INC =  -I inc
SRCD = src/
OBJD = obj/

#FILES
SRCS =	$(SRCD)error_handling.c \
		$(SRCD)main.c \
		$(SRCD)utils.c \



OBJS = $(patsubst $(SRCD)%.c, $(OBJD)%.o, $(SRCS))
$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

#RULES
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)
	echo "$(GREEN)All files compiled!$(RESET)"

fclean: clean
	$(RM) $(NAME)
	echo "$(RED)Deleted: $(RESET) $(GREEN)$(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
