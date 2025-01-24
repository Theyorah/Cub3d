/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:04:14 by kralison          #+#    #+#             */
/*   Updated: 2025/01/24 13:41:31 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	mlx_loop(p.mlx);
	return (0);
}
