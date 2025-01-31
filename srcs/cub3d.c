/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:04:14 by kralison          #+#    #+#             */
/*   Updated: 2025/01/31 09:00:52 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

int	main(int ac, char **av)
{
	t_program	p;

	init_program(&p, ac, av);
	mlx_hook(p.win.win, DESTROY, 0, program_finish, &p);
	mlx_hook(p.win.win, KEY_PRESSED, 1L<<0, handle_key, &p);
	mlx_loop_hook(p.mlx, main_loop, &p);
	mlx_loop(p.mlx);
	return (0);
}
