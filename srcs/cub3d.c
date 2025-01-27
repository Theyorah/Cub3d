/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:04:14 by kralison          #+#    #+#             */
/*   Updated: 2025/01/27 15:19:57 by kralison         ###   ########.fr       */
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

int	gradient(int x, int color1, int color2)
{
	int	r;
	int	g;
	int	b;

	r = (get_r(color1) + get_r(color2)) * x / WIDTH;
	g = (get_g(color1) + get_g(color2)) * x / WIDTH;
	b = (get_b(color1) + get_b(color2)) * x / WIDTH;
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
	p->mlx = mlx_init();
	p->win.win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "CUB3D");
	p->win.img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->win.addr = mlx_get_data_addr(p->win.img, &p->win.bpp,
			&p->win.ln, &p->win.ed);
}

int	main(void)
{
	t_program	p;
	int			x;
	int			y;
	int			color;

	init_program(&p);
	y = 0;
	color = rgb(255, 255, 255);
	while(y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			window_img_pixel(&p.win, x, y, gradient(x, color, invert(color)));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(p.mlx, p.win.win, p.win.img, 0, 0);
	mlx_loop(p.mlx);
	return (0);
}
