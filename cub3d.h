
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

# define MM_WALL_COLOR 0xFFFFFFFF
# define MM_FLOOR_COLOR 0x00000000
# define MM_CELL_SIZE 20
# define MM_CELL_SEP 2

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}		t_color;

typedef struct s_pxl
{
	int		x;
	int		y;
	t_color	*color;
}			t_pxl;

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
	floor,
	wall,
	outside,
};

// DRAW MINIMAP

// DRAW UTILS
void	draw_pixel(mlx_image_t *canvas, t_pxl *pxl);
void	draw_line(mlx_image_t *canvas, t_pxl *pxl1, t_pxl *pxl2, t_color *color);
void	draw_square(mlx_image_t *canvas, t_pxl *tl_corner, int size, t_color *c);

// STRUCT UTILS
t_color	*init_color(int r, int g, int b, int a);
t_pxl	*init_pxl(int x, int y, t_color *color);
int		color_to_int(t_color *color);
t_color	*int_to_color(int rgba);

// HOOKS
void	cont_hook(void *param);
void	disc_hook(mlx_key_data_t key, void *param);

#endif