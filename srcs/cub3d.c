/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:04:14 by kralison          #+#    #+#             */
/*   Updated: 2025/01/30 07:52:49 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	window_img_pixel(t_win *win, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		dst = win->addr + (win->ln * y + (win->bpp / 8) * x);
		*(unsigned int *)dst = color;
	}
}

int	rgb(int r, int g, int b)
{
	int	color;

	color = r % 256;
	color <<= 8;
	color |= g % 256;
	color <<= 8;
	color |= b % 256;
	return (color);
}

int	get_r(int color)
{
	return (color >> 16);
}

int get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_b(int color)
{
	return (color & 0xFF);
}

int	shade(double mult, int color)
{
	int r;
	int	g;
	int	b;

	r = get_r(color) * (1 - mult);
	g = get_g(color) * (1 - mult);
	b = get_b(color) * (1 - mult);
	return (rgb(r, g, b));
}

int	gradient(int min, int max, int pos, int color1, int color2)
{
	int	r;
	int	g;
	int	b;

	r = get_r(color1) * (max - pos) / max + get_r(color2) * pos / max + min;
	g = get_g(color1) * (max - pos) / max + get_g(color2) * pos / max + min;
	b = get_b(color1) * (max - pos) / max + get_b(color2) * pos / max + min;
	return (rgb(r, g, b));
}

int	invert(int rgb)
{
	int	color;

	color = 255 - (rgb >> 16);
	color <<= 8;
	color |= 255 - ((rgb << 8) >> 16);
	color <<= 8;
	color |= 255 - (rgb & 255);
	return (color);
}

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

int	handle_key(int keycode, t_program *p)
{
	if (keycode == ESC_KEY)
		program_finish(p);
	return (0);
}

int	main(void)
{
	t_program	p;

	init_program(&p);
	mlx_put_image_to_window(p.mlx, p.win.win, p.win.img, 0, 0);
	mlx_hook(p.win.win, DESTROY, 0, program_finish, &p);
	mlx_hook(p.win.win, KEY_PRESSED, 1L<<0, handle_key, &p);
	mlx_loop(p.mlx);
	return (0);
}
