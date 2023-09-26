
CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=cub3d

SRC_DIR = sources
MAIN = $(SRC_DIR)/main.c
#SRC = 	$(SRC_DIR)/executor.c

TEST_DIR = testing
TEST_MAIN = $(TEST_DIR)/executor_test.c
TEST_SRC = 

OBJ=$(SRC:.c=.o)
OBJ_TEST=$(TEST_SRC:.c=.o)

LIBFT_DIR=Libft
LIBFT=$(LIBFT_DIR)/libft.a


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(MAIN)
	@$(CC) $(CFLAGS) $(OBJ) $(MAIN) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

test: build_test
	@./test

build_test: $(LIBFT) $(OBJ) $(TEST_MAIN)
	@$(CC) $(OBJ) $(TEST_MAIN) $(LIBFT) -o test

$(LIBFT):
	@$(MAKE) -C Libft

clean:	
		@rm -f ${OBJ}
		@${MAKE} -C Libft clean

fclean:	clean
		@rm -f ${NAME}
		@rm -rf $(OBJ_DIR)
		@${MAKE} -C Libft fclean

re: fclean all

.PHONY: all clean fclean re lib main