/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:47:24 by alvgomez          #+#    #+#             */
/*   Updated: 2023/10/26 18:15:41 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# define DR 0.0174533

# define SQ_SIZE 50.0

# define MM_EMPTY_COLOR 0x000000FF
# define MM_WALL_COLOR 0xFFFFFFFF
# define MM_TL_X 0.0
# define MM_TL_Y 0.0
# define MM_SCALE 0.2
# define MM_RADIUS 100.0

# define VP_W 1500.0
# define VP_H 1000.0
# define VP_TL_X 0.0
# define VP_TL_Y 0.0
# define FOV 60.0
# define RAY_DEG 0.04

# define P_W 10.0
# define P_H 10.0
# define P_COLOR 0x00FF00FF
# define R_COLOR 0xFF00FFFF
# define P_RADIUS 3.0
# define P_LINE 5.0
# define P_MOV 5.0
# define P_ROT 0.05
# define P_COL 10.0

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
	int		start_col;
	int		start_row;
	int		x;
	int		y;
	float	angle;
}		t_player;

typedef struct s_ray
{
	float		x;
	float		y;
	float		x_offset;
	float		y_offset;
	int			map_x;
	int			map_y;
	int			map_pos;
	float		h_x;
	float		h_y;
	float		h_dist;
	float		v_x;
	float		v_y;
	float		v_dist;
	float		angle;
	float		iangle;
	float		dist;
	int			iray;
	int			wall_type;
	mlx_image_t	*tex;
	float		rect_w;
	float		rect_h;
	int			rect_w_int;
	int			rect_h_int;
	float		rect_h_prop;
	int			rect_x_off;
	int			rect_tex_x_off;
	float		rect_tex_y_off;
}		t_ray;

typedef struct s_map
{
	t_player		*player;
	t_ray			*ray;
	int				**cells;
	int				max_cols;
	int				max_rows;
	int				new_max_cols;
	int				new_max_rows;
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	t_color			*ceiling;
	t_color			*floor;
	mlx_t			*mlx;
	mlx_image_t		*cam;
	mlx_image_t		*minmap;
	mlx_image_t		*player_img;
	mlx_image_t		*n_tex;
	mlx_image_t		*s_tex;
	mlx_image_t		*e_tex;
	mlx_image_t		*w_tex;
	mlx_texture_t	*texture;
	int				check;
	int				empty_line;
	int				top_x;
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
	W_wall,
};

// UTILS
float	deg_rad(float angle, int to_rad);
float	normalize_angle(float angle);

// Check errors
char	*initial_checks(int argc, char *argv, t_map *map);
void	check_cells_for_errors(char *line, t_map *map);
void	ft_error_and_free_all(t_map *map, char *error);
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
void	ft_free_cells(t_map *map, int rows);

// Parse and fill cub data
void	cub_parsing(char *map_route, t_map *map);

// Raycasting
void	raycaster(t_map *map);
float	distance_between_points(float x1, float y1, float x2, float y2);

void	horizontal_lines_depth_check(t_map *map, int depth);
void	horizontal_lines_ray_angle_check(t_map *map, int *depth, float a_tan);
void	keep_variables_inside_map(t_map *map);

void	vertical_lines_depth_check(t_map *map, int depth);
void	vertical_lines_ray_angle_check(t_map *map, int *depth, float ntan);

// Main
void	print_map_cells(t_map *map);

// CHECK MAP
int		is_map_closed(t_map *map);

// DRAW
void	draw_minmap(t_map *map);
void	draw_player(t_map *m);
void	draw_camera(t_map *map);

// DRAW UTILS
void	draw_pixel(mlx_image_t *img, t_pxl *pxl);
void	draw_line(mlx_image_t *img, t_pxl *pxl1, t_pxl *pxl2, t_color *c);
void	draw_square(mlx_image_t *img, t_pxl *tl_corner, int size, t_color *c);
void	draw_wall_rect(t_map *map, t_ray *ray);
void	clean_img(mlx_image_t *img);
void	draw_rect(mlx_image_t *img, t_pxl *tl_crn, t_pxl *br_crn, t_color *c);
void	draw_circle(mlx_image_t *img, t_pxl *center, int size, t_color *c);

// STRUCT UTILS
t_color	*init_color(int r, int g, int b, int a);
t_pxl	*init_pxl(int x, int y, t_color *color);
int		color_to_int(t_color *color);
t_color	*int_to_color(int rgba);

// HOOKS
void	cont_hook(void *param);
void	disc_hook(mlx_key_data_t key, void *param);
void	move_if_no_collision(t_map *map, int key);

#endif