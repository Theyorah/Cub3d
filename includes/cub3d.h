/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:56:00 by kralison          #+#    #+#             */
/*   Updated: 2025/02/13 08:11:11 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <X11/X.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>

# define WIDTH 1080
# define HEIGHT 720
# define BLOCK_SIZE 300
# define KEY_PRESSED 2
# define KEY_RELEASED 3
# define DESTROY 17
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define UP_KEY 65362
# define DOWN_KEY 65364
# define ESC_KEY 65307

typedef struct s_vec
{
	double	x;
	double	y;
}				t_vec;

typedef struct s_entity
{
	int		x;
	int		y;
	int		size;
}				t_entity;

typedef struct s_player
{
	int		size;
	t_vec	pos;
	t_vec	vel;
	t_vec	direction;
	t_vec	plane;
	double	speed;
	double	r_speed;
}				t_player;

typedef struct s_raycast_tmp_vars
{
	t_vec	raydir;
	int		ray_i[2];
	int		steps[2];
	t_vec	step_length[2];
	t_vec	p_center;
}				t_raycast_tmp_vars;

typedef struct	s_ray
{
	char	side;
	double	ratio;
	double	length;
}				t_ray;

typedef struct s_win
{
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		ln;
	int		ed;
}				t_win;

typedef struct s_program
{
	void				*mlx;
	t_win				win;
	int					error;
	t_player			player;
	t_raycast_tmp_vars	rc;
	t_ray				rays[WIDTH];
	char				*map;
	t_vec				map_pos;
	int					map_width;
	int					map_height;
	bool				w;
	bool				a;
	bool				s;
	bool				d;
	bool				left;
	bool				right;
	bool				up;
	bool				down;
}				t_program;

t_vec		scale(t_vec vec, double angle);
t_vec		rotate(t_vec vec, double angle);
t_vec		operation_vec(t_vec v1, t_vec v2, bool substract);
double		distance(t_vec v1, t_vec v2);
double		length(t_vec vec);
t_entity	vec_entity(t_vec vec, int size);
t_entity	entity(double x, double y, int size);
t_vec		vector(double x, double y);
int			get_r(int color);
int			get_g(int color);
int			get_b(int color);
int			rgb(int r, int g, int b);
int			get_color(t_win *win, int x, int y);
int			shade(double mult, int color);
int			gradient(double ratio, int pos, int color1, int color2);
int			invert(int color);
void		init_program(t_program *p, int ac, char **av);
int			program_finish(t_program *p);
void		put_pixel_win_img(t_win *win, int x, int y, int color);
void		clear_win_img(t_win *win, int color);
int			main_loop(t_program *p);

/* EXTERNAL FUNCTIONS */

void		init_player(t_program *p);
int			init_map(t_program *p);
void		free_map(t_program *p);
void		draw_square(t_program *p, t_entity square, int color);
void		draw_circle(t_program *p, t_entity square, int color);
void		draw_map(t_program *p);
t_entity	map_collision(t_program *p, t_entity en);
bool		collide(t_entity t1, t_entity t2);
void		collision_x(t_program *p);
void		collision_y(t_program *p);
void		raying(t_program *p);

/**********************/


#endif
