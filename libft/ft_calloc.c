/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:01:06 by kralison          #+#    #+#             */
/*   Updated: 2024/08/16 11:02:50 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	n;
	void	*m;

	n = nitems * size;
	m = malloc(n);
	if (m == 0)
		return (0);
	ft_memset(m, 0, n);
	return (m);
}
