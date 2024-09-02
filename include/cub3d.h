/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonati <fdonati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:54:18 by fdonati           #+#    #+#             */
/*   Updated: 2024/08/06 16:13:49 by fdonati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/keysymdef.h>

# define TILESIZE 32
# define BLACK 0x00000000
# define GRAY 0x00A9A9A9
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define YELLOW 0x00FFFF00
# define ORANGE 0x00FFA500
# define PURPLE 0x00800080
# define DARK_GREEN 0x00008000
# define LIGHT_GREEN 0x0000FF80
# define GREENER 0x0000FF40
# define BLUE 0x000000FF

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

# define FOV 60.0
# define WIDTH 1280
# define HEIGHT 720

# define SPEED 0.9

# define MLX_ERROR "MLX error\n"
# define MAP_ERROR "Map error\n"
# define WIN_ERROR "Window error\n"
# define FILE_ERROR "File error\n"
# define BAD_ARG "Bad argument\n"
# define EXT_ERROR "Extention error\n"
# define BAD_OPTION "Bad option\n"
# define BAD_COLOR "Bad color\n"

# define M_PI 3.14159265358979323846
# 

typedef enum e_side
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
}	t_side;

typedef struct s_point
{
	double	y;
	double	x;
}	t_point;

typedef struct s_ray
{
	int		hit_tile;
	double	dist;
	t_side	side;
}	t_ray;

typedef struct s_pimg
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_pimg;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_plyr
{
	double	dir;
	t_point	point;
}	t_plyr;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_texture;


typedef struct s_pars
{
	t_rgb	floor;
	t_rgb	ceiling;
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
}	t_pars;

typedef struct s_draw_text
{
	t_pimg		*img;
	t_texture	*texture;
	t_point		start;
	t_point		end;
	int			tex_x;
	int			tex_y;
	int			x;
	int			y;
}	t_draw_text;

typedef struct s_tex_params
{
	double	wall_x;
	int		tex_x;
	t_point	start;
	t_point	end;
}	t_tex_params;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	char	*path;
	t_pimg	img;
	t_map	map;
	t_pars	pars;
	t_plyr	player;
}	t_var;

typedef struct	s_ray_params
{
	t_var	*var;
	double	delta_angle;
	double	ray_angle;
	t_point	point;
	t_ray	ray;
}	t_ray_params;

int		ft_load_game(t_var *var);
int		ft_read_map(char *path, t_var *var);
int 	ft_parse_map(t_var *var);
void 	ft_trim_leadblank(char *str);
void	ft_error(int error, t_var *var);
int		ft_check_file(int ac, char *file);
int		ft_match_ext(char *map, char *ext);
int		ft_key_press(int keycode, t_var *var);

t_ray	ft_ray(t_var *var, double angle);
void	ft_move(t_var *var, int keycode);

void	ft_draw_pixel(t_pimg *img, int x, int y, int color);
void	ft_draw_tile(t_pimg *img, int x, int y, int color);
void	ft_draw_line(t_pimg *img, t_point p1, t_point p2, int color);
void	ft_draw_tex(t_pimg *img, t_point start, t_point end, t_texture *texture, int tex_x);

int		ft_err(char *msg, int err_code);
int		create_trgb(int	t, int r, int g, int b);

void	ft_ray_casting(t_var *var);

void	ft_raycaster(t_var *var);
void 	ft_compute_tex_params(t_ray_params *context, t_tex_params *tex_params);
void 	ft_compute_tex_coord(t_ray_params *context, t_tex_params *tex_params, double wall_dist);
void 	ft_compute_wall_intersec(t_ray_params *context, t_tex_params *tex_params, double wall_dist);
double 	ft_compute_wall_dist(t_ray_params *context);



#endif