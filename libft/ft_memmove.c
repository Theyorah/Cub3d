/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:55:47 by kralison          #+#    #+#             */
/*   Updated: 2024/08/16 11:03:26 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *to, const void *from, size_t count)
{
	unsigned char	*c;
	unsigned char	*s;

	c = (unsigned char *)to;
	s = (unsigned char *)from;
	if (c == 0 && s == 0)
		return (0);
	while (count--)
	{
		if (c <= s)
			*c++ = *s++;
		else
			c[count] = s[count];
	}
	return (to);
}
