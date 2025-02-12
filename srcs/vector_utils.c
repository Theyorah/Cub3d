/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:26:23 by kralison          #+#    #+#             */
/*   Updated: 2025/02/08 16:50:57 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_vec	operation_vec(t_vec v1, t_vec v2, bool substract)
{
	t_vec	vec;

	vec.x = v1.x + v2.x;
	vec.y = v1.y + v2.y;
	if (substract)
	{
		vec.x = v1.x - v2.x;
		vec.y = v1.y - v2.y;
	}
	return (vec);
}

t_vec	scale(t_vec vec, double s)
{
	return (vector(vec.x * s, vec.y * s));
}

t_vec	rotate(t_vec vec, double angle)
{
	t_vec	v;

	v.x = vec.x * cos(angle) - vec.y * sin(angle);
	v.y = vec.y * cos(angle) + vec.x * sin(angle);
	return (v);
}

double	distance(t_vec v1, t_vec v2)
{
	return (length(vector(v1.x - v2.x, v1.y - v2.y)));
}

double	length(t_vec vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y));
}
