/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frakotov <frakotov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:56:00 by kralison          #+#    #+#             */
/*   Updated: 2025/02/06 12:57:58 by frakotov         ###   ########.fr       */
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

# define WIDTH 400
# define HEIGHT 200
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
	int			map_width;
	int			map_height;
	char		*map;
	bool		w;
	bool		a;
	bool		s;
	bool		d;
	bool		left;
	bool		right;
	char		**texture;
	int			floor_color;
	int			ceiling_color;
}				t_program;

int		get_r(int color);
int		get_g(int color);
int		get_b(int color);
int		rgb(int r, int g, int b);
int		shade(double mult, int color);
int		gradient(double ratio, int pos, int color1, int color2);
int		invert(int color);
void	init_program(t_program *p, int ac, char **av);
int		program_finish(t_program *p);
void	put_pixel_win_img(t_win *win, int x, int y, int color);
void	clear_win_img(t_win *win, int color);
int		main_loop(t_program *p);
int		init_map(t_program *p, int ac, char **av);
void 	parse_line(t_program *p, char *line);
bool	is_texture(char *line);
void	parse_texture(t_program *p, char *line);
void	parse_color(t_program *p, char *line);
bool	is_color_line(char *line);

#endif
