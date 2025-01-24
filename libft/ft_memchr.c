/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:32:12 by kralison          #+#    #+#             */
/*   Updated: 2024/08/16 11:03:12 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*x;

	x = (unsigned char *)str;
	while (n--)
	{
		if (*x++ == (unsigned char)c)
			return ((void *)x - 1);
	}
	return (NULL);
}
