/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:08:29 by kralison          #+#    #+#             */
/*   Updated: 2025/02/12 15:25:58 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	st_init_steps(t_program *p)
{
	double	v_x;
	double	h_y;

	p->rc.ray_index[0] = (int)((p->rc.p_center.x - p->map_pos.x) / BLOCK_SIZE);
	p->rc.ray_index[1] = (int)((p->rc.p_center.y - p->map_pos.y) / BLOCK_SIZE);
	p->rc.steps[0] = 2 * (p->rc.raydir.x > 0) - 1;
	p->rc.steps[1] = 2 * (p->rc.raydir.y > 0) - 1;
	p->rc.step_length[0].x = fabs(BLOCK_SIZE / p->rc.raydir.x);
	p->rc.step_length[0].y = fabs(BLOCK_SIZE / p->rc.raydir.y);
	v_x = (int)(p->rc.p_center.x - p->map_pos.x) % BLOCK_SIZE;
	h_y = (int)(p->rc.p_center.y - p->map_pos.y) % BLOCK_SIZE;
	p->rc.step_length[1].x = length(vector(v_x,
				v_x * p->rc.raydir.y / p->rc.raydir.x));
	p->rc.step_length[1].y = length(vector((h_y * p->rc.raydir.x)
				/ p->rc.raydir.y, h_y));
	if (p->rc.raydir.x > 0)
		p->rc.step_length[1].x = length(vector(BLOCK_SIZE - v_x,
					((BLOCK_SIZE - v_x) * p->rc.raydir.y) / p->rc.raydir.x));
	if (p->rc.raydir.y > 0)
		p->rc.step_length[1].y = length(vector(BLOCK_SIZE - h_y,
					((BLOCK_SIZE - h_y) * p->rc.raydir.x) / p->rc.raydir.y));
}

static t_vec	st_get_ray(t_program *p, t_vec plane)
{
	t_vec	ray;

	while (1)
	{
		if (p->rc.step_length[1].x < p->rc.step_length[1].y)
		{
			ray = scale(p->rc.raydir, (p->rc.step_length[1].x));
			p->rc.step_length[1].x += p->rc.step_length[0].x;
			p->rc.ray_index[0] += p->rc.steps[0];
		}
		else
		{
			ray = scale(p->rc.raydir, (p->rc.step_length[1].y));
			p->rc.step_length[1].y += p->rc.step_length[0].y;
			p->rc.ray_index[1] += p->rc.steps[1];
		}
		if (p->map[p->rc.ray_index[1] * p->map_width + p->rc.ray_index[0]]
			== '1')
			break ;
	}
	(void)plane;
	return (ray);
}

void	raying(t_program *p)
{
	t_vec	tmp_plane;
	t_vec	ray;
	int		i;

	p->rc.p_center = operation_vec(p->player.pos,
			vector((int)(p->player.size / 2), (int)(p->player.size / 2)), 0);
	i = -1;
	while (++i < WIDTH)
	{
		tmp_plane = scale(p->player.plane, 2 * (double)i / WIDTH - 1);
		p->rc.raydir = operation_vec(p->player.direction, tmp_plane, 0);
		p->rc.raydir = scale(p->rc.raydir, 1 / length(p->rc.raydir));
		st_init_steps(p);
		ray = st_get_ray(p, tmp_plane);
		p->rays[i] = ray;
	}
}
