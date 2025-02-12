/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:25:11 by kralison          #+#    #+#             */
/*   Updated: 2025/02/11 18:48:43 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

bool	collide(t_entity t1, t_entity t2)
{
	if (t1.x <= t2.x + t2.size)
		if (t1.x + t1.size >= t2.x)
			if (t1.y <= t2.y + t2.size)
				if (t1.y + t1.size >= t2.y)
					return (1);
	return (0);
}

t_entity	map_collision(t_program *p, t_entity en)
{
	t_entity	t;
	int			i;
	int			j;
	int			max_i;
	int			max_j;

	j = (int)(en.y + en.size - p->map_pos.y) / BLOCK_SIZE - 2;
	max_i = (int)(en.x + en.size - p->map_pos.x) / BLOCK_SIZE + 1;
	max_j = j + 3;
	while (++j <= max_j)
	{
		i = (int)(en.x + en.size - p->map_pos.x) / BLOCK_SIZE - 2;
		while (++i <= max_i)
		{
			if (j * p->map_width + i < p->map_height * p->map_width
				&& i >= 0 && j >= 0 && p->map[j * p->map_width + i] == '1')
			{
				t = entity(i * BLOCK_SIZE + p->map_pos.x,
						j * BLOCK_SIZE + p->map_pos.y, BLOCK_SIZE);
				if (collide(en, t))
					return (t);
			}
		}
	}
	return (entity(0, 0, -1));
}

void	collision_x(t_program *p)
{
	t_entity	wall;

	wall = map_collision(p, entity(p->player.pos.x,
				p->player.pos.y, p->player.size));
	if (wall.size == -1)
		return ;
	if (p->player.vel.x > 0)
		p->player.pos.x = wall.x - p->player.size - 1;
	if (p->player.vel.x < 0)
		p->player.pos.x = wall.x + wall.size + 1;
}

void	collision_y(t_program *p)
{
	t_entity	wall;

	wall = map_collision(p, entity(p->player.pos.x,
				p->player.pos.y, p->player.size));
	if (wall.size == -1)
		return ;
	if (p->player.vel.y > 0)
		p->player.pos.y = wall.y - p->player.size - 1;
	if (p->player.vel.y < 0)
		p->player.pos.y = wall.y + wall.size + 1;
}
