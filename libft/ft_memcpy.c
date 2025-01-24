/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:42:34 by kralison          #+#    #+#             */
/*   Updated: 2024/08/16 11:03:22 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*c;
	unsigned char	*s;

	c = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (c == 0 && s == 0)
		return (0);
	while (n--)
		*c++ = *s++;
	return (dest);
}
