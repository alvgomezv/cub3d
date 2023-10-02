
CC=gcc
NAME=cub3d

GLFW_PATH="/Users/$(USER)/.brew/opt/glfw/lib/"
CFLAGS=-Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX=MLX42

HEADERS=-I$(LIBMLX)/include
LIBS=-ldl -lglfw -L$(GLFW_PATH) -pthread -lm $(LIBMLX)/libmlx42.a

SRC_DIR = sources
MAIN = $(SRC_DIR)/main.c
SRC = 	$(SRC_DIR)/hooks.c $(SRC_DIR)/colors_utils.c $(SRC_DIR)/draw_utils.c \
		$(SRC_DIR)/init_structs.c $(SRC_DIR)/draw_minmap.c $(SRC_DIR)/map_check.c \
		$(SRC_DIR)/collisions.c

TEST_DIR = testing
TEST_MAIN = $(TEST_DIR)/test.c
TEST_SRC = 

OBJ=$(SRC:.c=.o)
OBJ_TEST=$(TEST_SRC:.c=.o)

LIBFT_DIR=Libft
LIBFT=$(LIBFT_DIR)/libft.a


all: libmlx $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(MAIN)
	@$(CC) $(CFLAGS) $(LIBS) $(HEADERS) $(OBJ) $(MAIN) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

test: build_test
	@./test

build_test: libmlx $(LIBFT) $(OBJ) $(TEST_MAIN)
	@$(CC) $(OBJ) $(LIBS) $(HEADERS) $(TEST_MAIN) $(LIBFT) -o test

$(LIBFT):
	@$(MAKE) -C Libft

libmlx:
	@$(MAKE) -C $(LIBMLX)

clean:	
		@rm -f ${OBJ}
		@${MAKE} -C Libft clean

fclean:	clean
		@rm -f ${NAME}
		@rm -rf $(OBJ_DIR)
		@${MAKE} -C Libft fclean

deepclean: clean
	$(MAKE) -C libft fclean
	rm -f $(OBJS)
	$(MAKE) -C MLX42 fclean

re: fclean all

.PHONY: all clean fclean re lib main