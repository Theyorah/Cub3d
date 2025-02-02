/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:38:56 by kralison          #+#    #+#             */
/*   Updated: 2025/02/02 18:07:06 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <math.h>

static void	st_handle_key(t_program *p)
{
	double	velocity_len;

	p->player.v_dir = -0.005 * p->left + 0.005 * p->right;
	p->player.v_x =
		cos(p->player.direction) * p->w +
		cos(p->player.direction - M_PI / 2) * p->a +
		cos(p->player.direction) * -1 * p->s +
		cos(p->player.direction + M_PI / 2) * p->d;
	p->player.v_y =
		sin(p->player.direction) * p->w +
		sin(p->player.direction - M_PI / 2) * p->a +
		sin(p->player.direction) * -1 * p->s +
		sin(p->player.direction + M_PI / 2) * p->d;
	velocity_len = sqrt(pow(p->player.v_x, 2) + pow(p->player.v_y, 2));
	if (velocity_len != 0)
	{
		p->player.v_x = (p->player.v_x / velocity_len) * p->player.speed;
		p->player.v_y = (p->player.v_y / velocity_len) * p->player.speed;
	}
}

static void	st_update_logic(t_program *p)
{
	p->player.x += p->player.v_x;
	collision_x(p);
	p->player.y += p->player.v_y;
	collision_y(p);
	p->player.direction += p->player.v_dir;
}

static void	st_update_rendering(t_program *p)
{
	draw_map(p);
	draw_square(p, entity(p->player.x, p->player.y, p->player.size), 0xffffff);
	draw_square(p, entity(p->player.x + (int)(p->player.size / 2) +
		cos(p->player.direction) * 20, p->player.y +
			(int)(p->player.size / 2) + sin(p->player.direction) * 20, 2), 0xffffff);
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
