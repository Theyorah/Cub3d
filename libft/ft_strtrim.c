/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:32:29 by kralison          #+#    #+#             */
/*   Updated: 2024/08/16 11:04:57 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	if (s1 == 0 || set == 0)
		return (0);
	while (ft_strchr(set, s1[i]) != 0)
		i++;
	while (ft_strchr(set, s1[j - 1]) != 0 && j > i)
		j--;
	return (ft_substr(s1, i, j - i));
}
