# · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#
#                                                                                           #
#                                        COLORS                                             #
#                                                                                           #
# · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#

RESET   = \033[0m
BLACK   = \033[1;30m
RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
PURPLE  = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m

# · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#
#                                                                                           #
#                                       COMMANDS                                            #
#                                                                                           #
# · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#

CC      = cc
RM      = rm -rf
AR      = ar -rcs

# · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#
#                                                                                           #
#                                         FLAGS                                             #
#                                                                                           #
# · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#

CFLAGS  = -g -Wall -Werror -Wextra
INCLUDE = -I./includes

# · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#
#                                                                                           #
#                                        FOLDERS                                            #
#                                                                                           #
# · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#

SRC_DIR = srcs
OBJ_DIR = obj

# · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#
#                                                                                           #
#                                        FILES                                              #
#                                                                                           #
# · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#

NAME    = philo
SRC_FILES = main.c checks.c mutex.c init.c actions.c threads.c utils.c free.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#
#                                                                                           #
#                                         RULES                                             #
#                                                                                           #
# · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · · ·#

all: $(NAME)
#	@printf "\n"
#	@echo $(G)"       _     _     _       _ _ "$(X)
#	@echo $(G)" _____|_|___|_|___| |_ ___| | |"$(X)
#	@echo $(G)"|     | |   | |_ -|   | -_| | |"$(X)
#	@echo $(G)"|_|_|_|_|_|_|_|___|_|_|___|_|_|"$(X)
#	@printf "\n\n"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT_LIB) $(LIBS_USED)	-fsanitize=address -o $@
	@echo "$(GREEN)$(NAME)$(RESET) Created"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(YELLOW)$(NAME)$(RESET) Objects Deleted"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME)$(RESET) Deleted"

re: fclean all

BUILDID=$(shell date +%Y%m%d-%H:%M:%S)

commit: fclean
	git add -A .
	git commit -m 'Automatic commit of successful build $(BUILDID)'
	git push origin main

run: all
	@./$(NAME)

valgrind: all
	@clear
	@echo "[$(RED)looking for valgrind leaks$(RESET)] $(GREEN)$(RESET)"
	@sleep 1
	@valgrind -s --suppressions=readline.supp --leak-check=full --show-leak-kinds=all ./minishell

.PHONY: all clean fclean re
.SILENT: