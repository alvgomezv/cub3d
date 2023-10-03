
#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# define PI 3.14159265359

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}		t_color;

typedef struct s_player
{
	int		start_x;
	int		start_y;
	float	x;
	float	y;
	float	angle;
}		t_player;

typedef struct s_map
{
	t_player	*player;
	int			**cells;
	int			max_x;
	int			max_y;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	t_color		*ceiling;
	t_color		*floor;
	int			check;
	int			empty_line;
	int			top_x;
}		t_map;

enum e_map_cell
{
	empty,
	wall,
	outside,
	position,
};

// Check errors
char	*initial_checks(int argc, char *argv, t_map *map);
void	check_cells_for_errors(char *line, t_map *map);
void	ft_error_and_free_map(t_map *map, char *error, char *line);

// Clean cells
void	clean_cells_from_empty_lines(t_map *map);

// Fill cells
void	fill_cells(char *line, t_map *map, int fd);
char	*change_tabs_for_4_spaces(char *line);

// Fill textures and colors
void	fill_color(t_color *color, char *number, t_map *map, char *line);
char	*fill_texture(char *word, t_map *map, char *line);

// Inicialize and free
t_map	*initialize_map_data(void);
void	initialize_player(t_map *map, char direction, int i, int y);
void	check_all_map_data(t_map *map);
void	ft_free_map(t_map *map);
void	ft_free_cells(t_map *map);

// Parse and fill cub data
void	cub_parsing(char *map_route, t_map *map);

// Main
void	print_map_cells(t_map *map);

#endif