/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frakotov <frakotov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:15:58 by frakotov          #+#    #+#             */
/*   Updated: 2025/02/05 12:25:06 by frakotov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	init_map(t_program *p, int ac, char **av)
{
	int fd;
	char *line;

	if (ac != 2)
	{	
		return (0);
	}
	fd = open(*av, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		parse_line(p, line);
	}
	return 1;
}


