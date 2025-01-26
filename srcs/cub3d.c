/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:04:14 by kralison          #+#    #+#             */
/*   Updated: 2025/01/25 17:58:59 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	display_square(t_win *win, int x, int y, int i, int j, int o, int p, int color)
{
	
}

void	display_circle(t_win *win, int x, int y, int r, int color)
{
	int	i;
	int	j;

	j = y - r;
	while (j < y + r)
	{
		i = x - r;
		while (i < x + r)
		{
			if (r >= sqrt(pow(y - j, 2) + pow(x - i, 2)))
				window_img_pixel(win, i, j, color);
			i++;
		}
		j++;
	}
}

void	window_img_pixel(t_win *win, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		dst = win->addr + (win->ln * y + (win->bpp / 8) * x);
		*(unsigned int *)dst = color;
	}
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
	init_program(&p);
	display_circle(&p.win, WIDTH / 2, HEIGHT / 2, 100, 0x00FFFFFF);
	mlx_put_image_to_window(p.mlx, p.win.win, p.win.img, 0, 0);
	mlx_loop(p.mlx);
	return (0);
}
