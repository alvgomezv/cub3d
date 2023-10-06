
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

# define MM_EMPTY_COLOR 0x000000FF
# define MM_WALL_COLOR 0xFFFFFFFF
# define MM_TL_X 0
# define MM_TL_Y 0
# define MM_C_SIZE 40
# define MM_C_SEP 0

# define VP_W 512
# define VP_H 384
# define FOV 60
# define RAY_DEG 0.5

# define P_COLOR 0x00FF00FF
# define P_SQ 5
# define P_LINE 10
# define P_MOV 4
# define P_ROT 0.1

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

typedef struct s_ray
{
	float		iangle;
	float		dist;
	t_pxl		*hit_pos;
	int			wall_type;
	mlx_image_t	*tex;
	int			rect_w;
	int			rect_h;
	int			rect_x_off;
	int			rect_tex_x_off;
}			t_ray;

typedef struct s_player
{
	int		start_col;
	int		start_row;
	int		x;
	int		y;
	float	angle;
}		t_player;

typedef struct s_map
{
	t_player	*player;
	int			**cells;
	int			max_cols;
	int			max_rows;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	t_color		*ceiling;
	t_color		*floor;
	mlx_t		*mlx;
	mlx_image_t	*cam;
	mlx_image_t	*minmap;
	mlx_image_t	*N_tex;
	mlx_image_t	*S_tex;
	mlx_image_t	*E_tex;
	mlx_image_t	*W_tex;
}		t_map;

enum e_map_cell
{
	empty,
	wall,
	outside,
	checked,
};

enum e_wall_type
{
	N_wall,
	S_wall,
	E_wall,
	O_wall,
};

// UTILS
float	deg_to_rad(float deg);

// CHECK MAP
int		is_map_closed(t_map *map);

// DRAW MINIMAP
void	draw_minmap(t_map *map, t_pxl *tl_corner);
void	draw_player(t_map *m);

// DRAW UTILS
void	draw_pixel(mlx_image_t *img, t_pxl *pxl);
void	draw_line(mlx_image_t *img, t_pxl *pxl1, t_pxl *pxl2, t_color *c);
void	draw_square(mlx_image_t *img, t_pxl *tl_corner, int size, t_color *c);

// STRUCT UTILS
t_color	*init_color(int r, int g, int b, int a);
t_pxl	*init_pxl(int x, int y, t_color *color);
int		color_to_int(t_color *color);
t_color	*int_to_color(int rgba);

// HOOKS
void	cont_hook(void *param);
void	disc_hook(mlx_key_data_t key, void *param);
void	move_if_no_collision(t_map *map, int pxls_to_move, int move_x_axis);

#endif