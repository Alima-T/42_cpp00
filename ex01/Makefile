# Directories
SRC_DIR = src
INC_DIR = Include
OBJ_DIR = obj

# Files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
NAME = phonebook

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -I$(INC_DIR)

# Colors
GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)
	@printf "\n"
	@printf "$(GREEN)"
	@printf "   ____ ____  ____    __  __           _       _         ___   ___  \n"
	@printf "  / ___|  _ \\|  _ \\  |  \\/  | ___   __| |_   _| | ___   / _ \\ / _ \\ \n"
	@printf " | |   | |_) | |_) | | |\\/| |/ _ \\ / _\` | | | | |/ _ \\ | | | | | | |\n"
	@printf " | |___|  __/|  __/  | |  | | (_) | (_| | |_| | |  __/ | |_| | |_| |\n"
	@printf "  \\____|_|   |_|     |_|  |_|\\___/ \\__,_|\\__,_|_|\\___|  \\___/ \\___/ \n"
	@printf "$(RESET)\n"


# Linking the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Create the object directory and compile object files into obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)   # Make sure the obj/ directory exists
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -rf $(OBJ_DIR)

# Remove executable and object files
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Special targets
.PHONY: all clean fclean re
