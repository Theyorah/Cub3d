/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:56:00 by kralison          #+#    #+#             */
/*   Updated: 2025/02/02 18:00:33 by kralison         ###   ########.fr       */
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

# define WIDTH 800
# define HEIGHT 600
# define BLOCK_SIZE 20
# define KEY_PRESSED 2
# define KEY_RELEASED 3
# define DESTROY 17
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define ESC_KEY 65307

typedef struct s_entity
{
	int		x;
	int		y;
	int		size;
}				t_entity;

typedef struct s_player
{
	int		size;
	double	x;
	double	y;
	double	v_x;
	double	v_y;
	double	direction;
	double	speed;
	double	v_dir;
}				t_player;

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
	void		*mlx;
	t_win		win;
	int			error;
	t_player	player;
	char		*map;
	int			map_x;
	int			map_y;
	int			map_width;
	int			map_height;
	bool		w;
	bool		a;
	bool		s;
	bool		d;
	bool		left;
	bool		right;
}				t_program;

t_entity	entity(double x, double y, int size);
int			get_r(int color);
int			get_g(int color);
int			get_b(int color);
int			rgb(int r, int g, int b);
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
bool		collide(t_entity t1, t_entity t2);
void		collision_x(t_program *p);
void		collision_y(t_program *p);

/**********************/


#endif
