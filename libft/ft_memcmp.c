/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:06:46 by kralison          #+#    #+#             */
/*   Updated: 2025/01/05 17:00:50 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s;
	unsigned char	*c;

	s = (unsigned char *)str1;
	c = (unsigned char *)str2;
	while (n--)
	{
		if (*s > *c)
			return (1);
		if (*s++ < *c++)
			return (-1);
	}
	return (0);
}
