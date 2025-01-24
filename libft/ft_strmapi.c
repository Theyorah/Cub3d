/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:53:08 by kralison          #+#    #+#             */
/*   Updated: 2024/08/16 11:04:41 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = -1;
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (str == 0)
		return (0);
	while (s[++i] != '\0')
		str[i] = f(i, s[i]);
	return (str);
}
