/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:17:01 by kralison          #+#    #+#             */
/*   Updated: 2025/01/30 12:41:10 by kralison         ###   ########.fr       */
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
	int color;

	color = r % 256;
	color <<= 8;
	color |= g % 256;
	color <<= 8;
	color |= b % 256;
	return (color);
}
