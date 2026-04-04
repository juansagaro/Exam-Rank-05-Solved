NAME        = polyset
CXX         = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR     = src
OBJ_DIR     = obj

SRC_FILES   =	main.cpp \
				BitcoinExchange.cpp

SRC         = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ         = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $@
	@echo "Done!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

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