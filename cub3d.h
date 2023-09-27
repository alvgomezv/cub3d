
#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define PI 3.14159265359

# define WIN_WIDTH 1000
# define WIN_HEIGTH 1000

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
	mlx_t		*mlx;
	mlx_image_t	*canvas;
}		t_map;



enum e_map_cell
{
	empty,
	wall,
	outside,
};


// HOOKS
void	cont_hook(void *param);
void	disc_hook(mlx_key_data_t key, void *param);

#endif