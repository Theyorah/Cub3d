/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:38:56 by kralison          #+#    #+#             */
/*   Updated: 2025/02/12 15:26:00 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <math.h>

double	shift = 0;
double	shift_pace = 1;

static void	st_handle_key(t_program *p)
{
	double	velocity_len;

	p->player.r_speed = p->left * 0.008 + p->right * -0.008;
	if (p->up)
	{
		p->player.direction = scale(p->player.direction, 1.01);
		p->player.plane = scale(p->player.plane, 0.99);
	}
	if (p->down)
	{
		p->player.direction = scale(p->player.direction, 0.99);
		p->player.plane = scale(p->player.plane, 1.01);
	}
	p->player.vel.x = p->player.direction.x * p->w
		+ rotate(p->player.direction, -M_PI / 2).x * p->d * !p->a
		+ p->player.direction.x * -1 * p->s
		+ rotate(p->player.direction, M_PI / 2).x * p->a * !p->d;
	p->player.vel.y = p->player.direction.y * p->w
		+ rotate(p->player.direction, -M_PI / 2).y * p->d * !p->a
		+ p->player.direction.y * -1 * p->s
		+ rotate(p->player.direction, M_PI / 2).y * p->a * !p->d;
	velocity_len = length(p->player.vel);
	if (velocity_len != 0)
	{
		p->player.vel.x = (p->player.vel.x / velocity_len) * p->player.speed;
		p->player.vel.y = (p->player.vel.y / velocity_len) * p->player.speed;
		shift += 0.4 * shift_pace;
	}
	else
	{
		shift = 0;
	}
}

static void	st_update_logic(t_program *p)
{
	p->player.pos.x += p->player.vel.x;
	collision_x(p);
	p->player.pos.y += p->player.vel.y;
	collision_y(p);
	p->player.direction = rotate(p->player.direction, p->player.r_speed);
	p->player.plane = rotate(p->player.plane, p->player.r_speed);
	raying(p);
}

static void	st_update_rendering(t_program *p)
{
	int	i;
	int	j;

	if (shift >= 10 || shift <= -10)
	{
		shift_pace = -shift_pace;
	}
	i = -1;
	while (++i < WIDTH)
	{
		j = (double)HEIGHT / 2 - HEIGHT * 80 / length(p->rays[i]) - 1;
		while (++j < (double)HEIGHT / 2 + HEIGHT * 80 / length(p->rays[i]))
		{
			put_pixel_win_img(&p->win, i, j + (int)shift, gradient(length(p->rays[i]) / 3000, 0, rgb(10, 10, 10), rgb(150, 90, 100)));
		}
	}
}

int	main_loop(t_program *p)
{
	clear_win_img(&p->win, rgb(150, 90, 100));
	st_handle_key(p);
	st_update_logic(p);
	st_update_rendering(p);
	mlx_put_image_to_window(p->mlx, p->win.win, p->win.img, 0, 0);
	return (0);
}
