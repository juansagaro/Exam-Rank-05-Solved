NAME        = life
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

INC_DIR     = inc
SRC_DIR     = src
OBJ_DIR     = obj

INCLUDES    = -I$(INC_DIR)

# Aquí añades todos tus archivos .c que estén dentro de src/
SRC         = \
	$(SRC_DIR)/life.c

# Generación automática de rutas para los objetos en obj/
OBJ         = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $@
	@echo "Done! Executable '$(NAME)' is ready."

# Regla para compilar los .c en .o creando los subdirectorios si es necesario
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Cleaning objects..."
	@rm -rf $(OBJ_DIR)
	@echo "Done."

fclean: clean
	@echo "Cleaning executable..."
	@rm -f $(NAME)
	@echo "Done."

re: fclean all

.PHONY: all clean fclean re
