/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_parse_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frakotov <frakotov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:30:10 by frakotov          #+#    #+#             */
/*   Updated: 2025/02/06 13:11:19 by frakotov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

bool	is_map_line(char *line)
{
	while (*line)
	{
		if (*line != "1" || *line != "0" || *line != "E" 
			|| *line != "S" || *line != "W" || *line !+ "N" || *line != " ")
			return (false);
		*line++;
	}
	return (true);
}

void	add_map_line(t_program *p, char *line)
{
	static int index = 0;
	static int 	first_call = 1;
	int	x;

	if (first_call)
	{
		p->map = malloc(p->map_width * p->map_height + 1);
		if (!p->map)
		{
			free(p->map);
			exit(1);
		}
		first_call = 0;
	}
	x = 0;
	while (x < p->map_widht)
	{
		if (line[x] == "\n" || line[x] == "\0")
			return ;
		p->map[index++] = line[x];
		x++;

}
