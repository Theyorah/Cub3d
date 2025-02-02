/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:04:14 by kralison          #+#    #+#             */
/*   Updated: 2025/02/02 12:18:44 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	st_key_pressed(int keycode, t_program *p)
{
	if (keycode == W_KEY)
		p->w = 1;
	if (keycode == A_KEY)
		p->a = 1;
	if (keycode == S_KEY)
		p->s = 1;
	if (keycode == D_KEY)
		p->d = 1;
	if (keycode == LEFT_KEY)
		p->left = 1;
	if (keycode == RIGHT_KEY)
		p->right = 1;
	return (0);
}

static int	st_key_released(int keycode, t_program *p)
{
	if (keycode == ESC_KEY)
		program_finish(p);
	if (keycode == W_KEY)
		p->w = 0;
	if (keycode == A_KEY)
		p->a = 0;
	if (keycode == S_KEY)
		p->s = 0;
	if (keycode == D_KEY)
		p->d = 0;
	if (keycode == LEFT_KEY)
		p->left = 0;
	if (keycode == RIGHT_KEY)
		p->right = 0;
	return (0);
}

t_entity	entity(double x, double y, int size)
{
	t_entity	t;

	t.x = x;
	t.y = y;
	t.size = size;
	return (t);
}

void	clear_win_img(t_win *win, int color)
{
	char	*dst;
	int		i;

	i = WIDTH * HEIGHT;
	dst = win->addr;
	while (--i)
	{
		*(unsigned int *)dst = color;
		dst += win->bpp / 8;
	}
}

int	main(int ac, char **av)
{
	t_program	p;

	init_program(&p, ac, av);
	mlx_hook(p.win.win, DESTROY, 0, program_finish, &p);
	mlx_hook(p.win.win, KEY_PRESSED, 1L << 0, st_key_pressed, &p);
	mlx_hook(p.win.win, KEY_RELEASED, 1L << 1, st_key_released, &p);
	mlx_loop_hook(p.mlx, main_loop, &p);
	mlx_loop(p.mlx);
	return (0);
}
