NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR     = src
OBJ_DIR     = obj

SRCS_FILES =	main.c \
				parse.c \
				solve.c \
				print.c

SRC = $(addprefix $(SRC_DIR)/, $(SRCS_FILES))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)"
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "Done!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning objects"
	@rm -rf $(OBJ_DIR)
	@echo "Done"

fclean: clean
	@echo "Cleaning executable"
	@rm -f $(NAME)
	@echo "Done"

re: fclean all

.PHONY: all clean fclean re
