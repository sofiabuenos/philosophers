#COLORS
RESET	= \033[0m
RED 	= \033[1;31m
GREEN 	= \033[1;32m

#PROGRAM NAME | COMPILER | FLAGS 
NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g -fsanitize=thread #-fsanitize=address
RM = rm -fr

#PATHS
INC =  -I inc
SRCD = src/
OBJD = obj/

#FILES
SRCS =	$(SRCD)error_handling.c \
		$(SRCD)main.c \
		$(SRCD)utils.c \
		$(SRCD)utils2.c \
		$(SRCD)init.c \
		$(SRCD)threads.c \
		$(SRCD)routine.c \
		$(SRCD)checks.c \
		$(SRCD)print_structs.c \

OBJS = $(patsubst $(SRCD)%.c, $(OBJD)%.o, $(SRCS))

$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

#RULES
all: $(NAME)

$(NAME): $(OBJS) $(OBJD)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)
	echo "$(GREEN)All files compiled!$(RESET)"

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJD)
	echo "$(RED)Deleted: $(RESET) $(GREEN)$ .o files$(RESET)"

fclean: clean
	$(RM) $(NAME)
	echo "$(RED)Deleted: $(RESET) $(GREEN)$(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
