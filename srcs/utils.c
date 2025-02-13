/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:49:56 by kralison          #+#    #+#             */
/*   Updated: 2025/02/12 18:58:00 by kralison         ###   ########.fr       */
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
	int		i;
	int		j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			put_pixel_win_img(win, i, j, color);
	}
}

t_entity	vec_entity(t_vec vec, int size)
{
	return (entity(vec.x, vec.y, size));
}

t_entity	entity(double x, double y, int size)
{
	t_entity	t;

	t.x = x;
	t.y = y;
	t.size = size;
	return (t);
}

t_vec	vector(double x, double y)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	return (v);
}
