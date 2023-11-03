
CC=gcc
NAME=cub3D
PARAMS=map/good/subject_map.cub

GLFW_PATH="/Users/$(USER)/.brew/opt/glfw/lib/"
CFLAGS=-Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX=MLX42

HEADERS=-I$(LIBMLX)/include
LIBS=-ldl -lglfw -L$(GLFW_PATH) -pthread -lm $(LIBMLX)/libmlx42.a

SRC_DIR = sources
MAIN = 
SRC = 	$(SRC_DIR)/hooks.c $(SRC_DIR)/colors_utils.c $(SRC_DIR)/draw_utils.c \
 		$(SRC_DIR)/init_structs.c $(SRC_DIR)/draw_minmap.c $(SRC_DIR)/map_check.c \
 		$(SRC_DIR)/collisions.c $(SRC_DIR)/draw_camera.c \
		$(SRC_DIR)/check_for_errors.c $(SRC_DIR)/clean_cells.c \
		$(SRC_DIR)/fill_cells_from_cub.c $(SRC_DIR)/fill_textures_and_colors.c  \
		$(SRC_DIR)/inicialize_and_free_map.c $(SRC_DIR)/parse_and_fill_cub.c \
		$(SRC_DIR)/raycaster.c $(SRC_DIR)/raycaster_horizontal_lines.c \
		$(SRC_DIR)/raycaster_vertical_lines.c $(SRC_DIR)/main.c\

TEST_DIR = testing
TEST_MAIN = $(TEST_DIR)/test.c
TEST_SRC = 

OBJ=$(SRC:.c=.o)
OBJ_TEST=$(TEST_SRC:.c=.o)

LIBFT_DIR=libft
LIBFT=$(LIBFT_DIR)/libft.a


all: submodule libmlx $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(LIBS) $(HEADERS) $(OBJ) $(LIBFT) -o $(NAME)


test: build_test
	@./test

build_test: libmlx $(LIBFT) $(OBJ) $(TEST_MAIN)
	@$(CC) $(OBJ) $(LIBS) $(HEADERS) $(TEST_MAIN) $(LIBFT) -o test

$(LIBFT):
	@$(MAKE) -C libft

submodule:
	@git submodule update --init --recursive

libmlx:
	@$(MAKE) -C $(LIBMLX)

clean:	
		@rm -f ${OBJ}
		@${MAKE} -C libft clean

fclean:	clean
		@rm -f ${NAME}
		@rm -rf $(OBJ_DIR)
		@${MAKE} -C libft fclean

deepclean: clean
	$(MAKE) -C libft fclean
	rm -f $(OBJS)
	$(MAKE) -C MLX42 fclean

re: fclean all

softclean:
	@rm -f ${OBJ}

build: softclean all

valgrind:
	valgrind --leak-check=full -s ./$(NAME) $(PARAMS)

.PHONY: all clean fclean re lib main