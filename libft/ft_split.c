/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:03:41 by kralison          #+#    #+#             */
/*   Updated: 2024/09/03 17:49:27 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_item(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	i = 0;
	j = i + 1;
	while (s[i])
	{
		if (s[i] != c && (s[j] == c || s[j] == '\0'))
			count++;
		i++;
		j++;
	}
	return (count);
}

static	size_t	get_len(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str != '\0' && *str++ != c)
		count++;
	return (count);
}

static	void	ultra_free(char **first)
{
	size_t	i;

	i = 0;
	while (first[i] != 0)
		free(first[i++]);
	free(first);
}

char	**ft_split(char const *s, char c)
{
	char	**ar;
	char	**ptr;

	ar = (char **)ft_calloc(count_item(s, c) + 1, sizeof(char *));
	if (ar == 0)
		return (0);
	ptr = ar;
	while (*s != 0)
	{
		if (*s != c)
		{
			*ptr++ = ft_substr(s, 0, get_len(s, c));
			if (*(ptr - 1) == 0)
			{
				ultra_free(ar);
				return (0);
			}
			s += get_len(s, c);
		}
		else
			s++;
	}
	return (ar);
}
