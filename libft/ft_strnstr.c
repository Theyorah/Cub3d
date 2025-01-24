/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:38:01 by kralison          #+#    #+#             */
/*   Updated: 2024/08/16 11:04:49 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;

	str = (char *)big;
	if (*little == '\0')
		return (str);
	while (ft_strchr(str, *little) != 0 && len >= ft_strlen(little))
	{
		if (ft_strncmp(str, little, ft_strlen(little)) == 0)
			return (str);
		str++;
		len--;
	}
	return (0);
}
