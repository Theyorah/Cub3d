/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:00:46 by kralison          #+#    #+#             */
/*   Updated: 2025/01/08 12:05:27 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t nbyte)
{
	unsigned char	*c;

	c = (unsigned char *)s;
	while (nbyte--)
		*c++ = 0;
}
