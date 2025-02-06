/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_parse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frakotov <frakotov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:23:40 by frakotov          #+#    #+#             */
/*   Updated: 2025/02/06 12:31:00 by frakotov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	parse_line(t_program *p, char	*line)
{
	static int map_started = 0;

	if (!map_started)
	{
		if (!line || !(*line))
			return ;
		if (is_texture(line))
			parse_texture(p, line);
		else if (is_color_line(line))
			parse_color(p, line);
		else if (is_map_line(line))
		{
			map_started = 1;
			add_map_line(pm, line);
		} 
	}
	else
	{
		if (is_map_line)
			add_map_line(p, line);
		else
			printf("ERROR after the first line\n");
	}
}

bool	is_texture(char	*line)
{
	retrun (ft_strncmp(line, "NO", 3) == 0 || ft_strncmp(line, "SO", 3) == 0 
			|| ft_strncmp(line, "WE", 3) == 0 || ft_strncmp(line, "EA", 3 == 0));
}

bool	is_color_line(char *line)
{
	return (ft_strncmp(line, "F", 2) == 0 || ft_strncmp(line, "C", 2));
}

void	parse_texture(t_program *p, char *line)
{
	char	**token;

	token = ft_split(line, " ");

	if (!token[1] || !token[2])
		return ;
	if (ft_strncmp(token[0], "NO", 2) == 0)
		p->texture[0] = ft_strdup(token[1]);
	else if (ft_strncmp(token[0], "SO", 2) == 0)
		p->texture[1] = ft_strdup(token[1]);
	else if (ft_strncmp(token[0], "WE", 2) == 0)
		p->texture[2] = ft_strdup(token[1]);
	else if (ft_strncmp(token[0], "EA", 2) == 0)
		p->texture[3] = ft_strdup(token[1]);
	free(token[1]);
}

void	parse_color(t_program *p, char *line)
{
	int			r;
	int			g;
	int			b;
	char	**token;

	token = ft_split(line + 2, ",");

	if (!token[0] || !token[1] || !token[2] || !token[3])
		return ;
	r = ft_atoi(token[0]);
	b = ft_atoi(token[1]);
	b = ft_atoi(token[2]);

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		printf("error: value must be between 0 -- 255\n");
		return ;
	}
	if (line[0] == "F")
		p->floor_color = rgb(r, g, b);
	else
		p->ceiling_color = rgn(r, g, b);
	free(token);
}
