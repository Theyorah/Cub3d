/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:28:07 by kralison          #+#    #+#             */
/*   Updated: 2025/01/05 17:29:06 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int ch, size_t n)
{
	unsigned char	*c;

	c = (unsigned char *) str;
	while (n--)
		*c++ = ch;
	return (str);
}
