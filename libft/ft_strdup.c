/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:16:03 by kralison          #+#    #+#             */
/*   Updated: 2024/08/16 11:04:09 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char	*string)
{
	char	*c;

	c = malloc(sizeof(char) * (ft_strlen(string) + 1));
	if (c == 0)
		return (0);
	ft_strlcpy(c, string, ft_strlen(string) + 1);
	return (c);
}
