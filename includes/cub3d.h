/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:56:00 by kralison          #+#    #+#             */
/*   Updated: 2025/01/31 08:29:27 by kralison         ###   ########.fr       */
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

# define WIDTH 400
# define HEIGHT 200
# define KEY_PRESSED 2
# define DESTROY 17
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define ESC_KEY 65307


typedef struct	s_win
{
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		ln;
	int		ed;
}				t_win;

typedef struct	s_program
{
	void		*mlx;
	t_win		win;
}				t_program;

int		get_r(int color);
int		get_g(int color);
int		get_b(int color);
int		rgb(int r, int g, int b);
int		shade(double mult, int color);
int		gradient(double ratio, int pos, int color1, int color2);
int		invert(int color);
void	init_program(t_program *p);
int		program_finish(t_program *p);
int		handle_key(int keycode, t_program *p);
void	put_pixel_win_img(t_win *win, int x, int y, int color);
void	clear_win_img(t_win *win, int color);
int		main_loop(t_program *p);

#endif
