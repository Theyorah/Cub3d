/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:04:14 by kralison          #+#    #+#             */
/*   Updated: 2025/01/30 13:58:32 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_program(t_program *p)
{
	p->win.win = NULL;
	p->win.img = NULL;
	p->mlx = mlx_init();
	if (p->mlx == NULL)
		program_finish(p);
	p->win.win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "CUB3D");
	if (p->win.win == NULL)
		program_finish(p);
	p->win.img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	if (p->win.img == NULL)
		program_finish(p);
	p->win.addr = mlx_get_data_addr(p->win.img, &p->win.bpp,
			&p->win.ln, &p->win.ed);
}

int	program_finish(t_program *p)
{
	int	error;

	error = p->mlx == NULL || p->win.win == NULL || p->win.img == NULL;
	if (p->mlx != NULL && p->win.img != NULL)
		mlx_destroy_image(p->mlx, p->win.img);
	if (p->mlx != NULL && p->win.win != NULL)
		mlx_destroy_window(p->mlx, p->win.win);
	if (p->mlx != NULL)
		mlx_destroy_display(p->mlx);
	if (p->mlx != NULL)
		free(p->mlx);
	exit(error);
	return (0);
}

void	put_pixel_win_img(t_win *win, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		dst = win->addr + (win->ln * y + (win->bpp / 8) * x);
		*(unsigned int *)dst = color;
	}
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

int	main(void)
{
	t_program	p;

	init_program(&p);
	mlx_hook(p.win.win, DESTROY, 0, program_finish, &p);
	mlx_hook(p.win.win, KEY_PRESSED, 1L<<0, handle_key, &p);
	mlx_loop_hook(p.mlx, main_loop, &p);
	mlx_loop(p.mlx);
	return (0);
}
