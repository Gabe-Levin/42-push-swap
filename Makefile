# Project Name
NAME = push_swap

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L$(MASTERLIB_DIR) -lmasterLib

# Directories
MASTERLIB_DIR = masterLib

# Library files
MASTERLIB = $(MASTERLIB_DIR)/masterLib.a

# Source files and object files
SRC = main.c pushswap_utils.c stack_utils.c read_input.c init_nodes.c pushswap_descending.c
OBJ = $(SRC:.c=.o)

# Build the project
all: $(NAME)

# Rule to create the final executable
$(NAME): $(OBJ) $(MASTERLIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MASTERLIB)

# Rule to ensure the masterLib is compiled
$(MASTERLIB):
	@make -C $(MASTERLIB_DIR)

# Compile object files from source
%.o: %.c $(MASTERLIB)
	$(CC) $(CFLAGS) -I$(MASTERLIB_DIR) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)
	@make -C $(MASTERLIB_DIR) clean

# Full clean: remove object files and executable
fclean: clean
	rm -f $(NAME)
	@make -C $(MASTERLIB_DIR) fclean

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re
