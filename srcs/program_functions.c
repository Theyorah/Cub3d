/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:00:48 by kralison          #+#    #+#             */
/*   Updated: 2025/01/31 09:19:54 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	st_error_occured(t_program *p, const char *str)
{
	p->error = 1;
	printf("%s\n", str);
	program_finish(p);
}

static void	st_init_your_thing(t_program *p, int ac, char **av)
{
	(void)p;
}

static void	st_free_your_thing(t_program *p)
{
	(void)p;
}

void	init_program(t_program *p, int ac, char **av)
{
	p->error = 0;
	p->win.win = NULL;
	p->win.img = NULL;
	p->mlx = NULL;
	st_init_your_thing(p, ac, av);
	p->mlx = mlx_init();
	if (p->mlx == NULL)
		st_error_occured(p, "the function mlx_init crashed (T^T)");
	p->win.win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "CUB3D");
	if (p->win.win == NULL)
		st_error_occured(p, "the function mlx_new_window crashed (T^T)");
	p->win.img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	if (p->win.img == NULL)
		st_error_occured(p, "the function mlx_new_image crashed (T^T)");
	p->win.addr = mlx_get_data_addr(p->win.img, &p->win.bpp,
			&p->win.ln, &p->win.ed);
}

int	program_finish(t_program *p)
{
	st_free_your_thing(p);
	if (p->mlx != NULL && p->win.img != NULL)
		mlx_destroy_image(p->mlx, p->win.img);
	if (p->mlx != NULL && p->win.win != NULL)
		mlx_destroy_window(p->mlx, p->win.win);
	if (p->mlx != NULL)
		mlx_destroy_display(p->mlx);
	if (p->mlx != NULL)
		free(p->mlx);
	exit(p->error);
	return (0);
}
