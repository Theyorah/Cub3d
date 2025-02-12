/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:17:01 by kralison          #+#    #+#             */
/*   Updated: 2025/02/05 07:57:13 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	get_r(int color)
{
	return (color >> 16);
}

int	get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_b(int color)
{
	return (color & 0xFF);
}

int	rgb(int r, int g, int b)
{
	int	color;

	color = r % 256;
	color <<= 8;
	color |= g % 256;
	color <<= 8;
	color |= b % 256;
	return (color);
}

int	get_color(t_win *win, int x, int y)
{
	char	*dst;

	x = x * (x >= 0) * (x < WIDTH) + (WIDTH - 1) * (x > WIDTH);
	y = y * (y >= 0) * (y < HEIGHT) + (HEIGHT - 1) * (y > HEIGHT);
	dst = win->addr + (win->ln * y + (win->bpp / 8) * x);
	return (*(unsigned int *)dst);
}
