/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:14:44 by kralison          #+#    #+#             */
/*   Updated: 2025/02/12 13:24:10 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	shade(double mult, int color)
{
	int	r;
	int	g;
	int	b;

	r = get_r(color) * (1 - mult);
	g = get_g(color) * (1 - mult);
	b = get_b(color) * (1 - mult);
	return (rgb(r, g, b));
}

int	gradient(double ratio, int pos, int color1, int color2)
{
	int	r;
	int	g;
	int	b;

	if (ratio > 1)
		ratio = 1;
	r = get_r(color1) * (1 - ratio) + get_r(color2) * ratio + pos;
	g = get_g(color1) * (1 - ratio) + get_g(color2) * ratio + pos;
	b = get_b(color1) * (1 - ratio) + get_b(color2) * ratio + pos;
	return (rgb(r, g, b));
}

int	invert(int color)
{
	return (rgb(255 - get_r(color), 255 - get_g(color), 255 - get_b(color)));
}
