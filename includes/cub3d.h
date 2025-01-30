/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:56:00 by kralison          #+#    #+#             */
/*   Updated: 2025/01/29 20:05:43 by kralison         ###   ########.fr       */
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
	void	*mlx;
	t_win	win;
	int		x;
	int		y;
}				t_program;

void	init_program(t_program *p);
int		program_finish(t_program *p);
void	window_img_pixel(t_win *win, int x, int y, int color);
int		handle_key(int keycode, t_program *p);

#endif
