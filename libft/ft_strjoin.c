/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:25:19 by kralison          #+#    #+#             */
/*   Updated: 2025/01/23 10:56:08 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (str);
}

char	*ft_merge_join(char *s1, char *s2)
{
	char	*str;
	char	*s1ptr;
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	ptr = str;
	s1ptr = s1;
	while (*s1ptr)
		*ptr++ = *s1ptr++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	free(s1);
	return (str);
}
