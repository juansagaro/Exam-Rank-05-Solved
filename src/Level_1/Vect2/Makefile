NAME        = vect2
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

GIVEN_DIR   = given
MAIN_DIR    = main
SRC_DIR     = src
OBJ_DIR     = obj

INCLUDES    = -I$(GIVEN_DIR)

SRC         = \
	$(MAIN_DIR)/main.cpp \
	$(SRC_DIR)/vect2.cpp

OBJ         = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ) -o $@
	@echo "Done!"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

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
