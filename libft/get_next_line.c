/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frakotov <frakotov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:37:49 by frakotov          #+#    #+#             */
/*   Updated: 2025/01/23 10:55:36 by frakotov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_end(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (i + 1);
		}
		i++;
	}
	return (i);
}

static char	*stock_rest(char *stash)
{
	int		i;
	int		j;
	char	*stock;

	i = ft_strlen_end(stash);
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	stock = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!stock)
		return (NULL);
	j = 0;
	while (stash[i])
		stock[j++] = stash[i++];
	stock[j] = '\0';
	free(stash);
	return (stock);
}

static char	*extract_line(char *stash)
{
	int		i;
	char	*line;
	int		j;

	i = ft_strlen_end(stash);
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (i > j)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*read_all(int fd, char *stash)
{
	char	*buff;
	int		nb_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (ft_strchr(stash) == 0)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(buff);
			return (NULL);
		}
		else if (nb_read == 0)
			break ;
		buff[nb_read] = '\0';
		stash = ft_merge_join(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (ft_strchr(stash[fd]) == 0)
		stash[fd] = read_all(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = stock_rest(stash[fd]);
	return (line);
}
