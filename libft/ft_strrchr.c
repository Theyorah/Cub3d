/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:58:35 by kralison          #+#    #+#             */
/*   Updated: 2024/08/16 11:04:53 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int a)
{
	char	*c;

	c = (char *)s + ft_strlen(s);
	if ((char)a == '\0')
		return (c);
	while (--c >= s)
	{
		if (*c == (char)a)
			return (c);
	}
	return (0);
}
