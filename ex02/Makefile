# Directories
SRC_DIR = src
INC_DIR = Include
OBJ_DIR = obj
LOG_DIR = logs

# Compiler & Flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

# Files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
NAME = account
OUTFILE = $(LOG_DIR)/current_run.log


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

# Link object files
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o into obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create obj dir if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Builds the project, executes accountand saves output to logs/current_run.log
run: all
	./$(NAME) > $(OUTFILE)

# Compares the latest run with the provided original log
diff:
	diff $(LOG_DIR)/19920104_091532.log $(OUTFILE) || true

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Clean everything
fclean: clean
	rm -f $(NAME) $(OUTFILE)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re run diff