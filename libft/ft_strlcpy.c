/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:19:38 by kralison          #+#    #+#             */
/*   Updated: 2024/08/16 11:04:36 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;

	n = size - 1;
	if (size > ft_strlen(src))
		n = ft_strlen(src);
	if (size)
	{
		ft_memcpy(dst, src, n);
		dst[n] = '\0';
	}
	return (ft_strlen(src));
}
