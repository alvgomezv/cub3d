
#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define PI 3.14159265359

typedef struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}		t_color;

typedef struct s_map
{
	s_player	*player;
	int			**cells;
	int			max_x;
	int			max_y;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	s_color		*ceiling;
	s_color		*floor;
}		t_map;

typedef struct s_player
{
	int		start_x;
	int		start_y;
	float	x;
	float	y;
	float	angle;
}		t_player;

enum e_map_cell
{
	empty,
	wall,
	outside,
};

#endif