NAME = FragTrap
SRC_FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))
INC = $(shell find $(INC_DIR) -type f -name "*.hpp")
FLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	$(CXX) $(FLAGS) $(OBJS) -I $(INC_DIR) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(FLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re