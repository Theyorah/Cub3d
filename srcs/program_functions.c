/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:00:48 by kralison          #+#    #+#             */
/*   Updated: 2025/01/31 08:43:38 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	st_init_your_thing(t_program *p)
{
	(void)p;
}

static int	st_free_your_thing(t_program *p)
{
	(void)p;
	return (1);
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
	st_init_your_thing(p);
}

int	program_finish(t_program *p)
{
	int	error;

	error = p->mlx == NULL || p->win.win == NULL
		|| p->win.img == NULL || st_free_your_thing(p) == 0;
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
