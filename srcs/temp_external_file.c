#include <X11/X.h>
#include <cub3d.h>
#include <math.h>

void	draw_circle(t_program *p, t_entity t, int color)
{
	int	i;
	int	j;

	j = t.y - t.size;
	while (j <= t.y + t.size)
	{
		i = t.x - t.size;
		while (i <= t.x + t.size)
		{
			if (t.size >= sqrt(i * i + j * j))
				put_pixel_win_img(&p->win, i, j, color);
			i++;
		}
		j++;
	}
}

void	collision_x(t_program *p)
{
	t_entity	t;
	int	i;

	i = 0;
	while (p->map[i])
	{
		t = entity((i % p->map_width) * BLOCK_SIZE + p->map_x,
			(int)(i / p->map_width) * BLOCK_SIZE + p->map_y, BLOCK_SIZE);
		if (p->map[i] == '1')
		{
			if (collide(entity(p->player.x, p->player.y, p->player.size), t))
			{
				if (p->player.v_x > 0)
					p->player.x = t.x - p->player.size - 1;
				if (p->player.v_x < 0)
					p->player.x = t.x + t.size + 1;
				p->player.v_x = 0;
			}
		}
		i++;
	}
}

void	collision_y(t_program *p)
{
	t_entity	t;
	int	i;

	i = 0;
	while (p->map[i])
	{
		t = entity((i % p->map_width) * BLOCK_SIZE + p->map_x,
			(int)(i / p->map_width) * BLOCK_SIZE + p->map_y, BLOCK_SIZE);
		if (p->map[i] == '1')
		{
			if (collide(entity(p->player.x, p->player.y, p->player.size), t))
			{
				if (p->player.v_y > 0)
					p->player.y = t.y - p->player.size - 1;
				if (p->player.v_y < 0)
					p->player.y = t.y + t.size + 1;
				p->player.v_y = 0;
			}
		}
		i++;
	}
}

void	draw_square(t_program *p, t_entity square, int color)
{
	int	i;
	int	j;

	j = square.y;
	while (j <= square.y + square.size)
	{
		i = square.x;
		while (i <= square.x + square.size)
		{
			if (i == square.x
				|| j == square.y
					|| i == square.x + square.size
						|| j == square.y + square.size)
				put_pixel_win_img(&p->win, i, j, color);
			i++;
		}
		j++;
	}
}

void	draw_map(t_program *p)
{
	int	i;

	i = 0;
	while (i <= p->map_width * p->map_height)
	{
		if (p->map[i] == '1')
			draw_square(p, entity((i % p->map_width) * BLOCK_SIZE + p->map_x,
				(int)(i / p->map_width) * BLOCK_SIZE + p->map_y,
					BLOCK_SIZE), rgb(50, 50, 50));
		i++;
	}
}

int	init_map(t_program *p)
{
	p->map_height = 7;
	p->map_width = 7;
	p->map_x = 80;
	p->map_y = 80;
	p->map = ft_memcpy(ft_calloc(p->map_height * p->map_width + 1,
				sizeof(char)),
					"1111111100N00110010011100011100100110000011111111",
						p->map_width * p->map_height);
	if (p->map == NULL)
		return (1);
	return (0);
}

void	free_map(t_program *p)
{
	if (p->map != NULL)
		free(p->map);
}

void	init_player(t_program *p)
{
	int	i;

	i = 0;
	while (p->map[i] != 'N')
		i++;
	p->player.direction = 3 * M_PI / 2;
	p->player.v_x = 0;
	p->player.v_y = 0;
	p->player.speed = 0.1;
	p->player.size = 6;
	p->player.v_dir = 0;
	p->player.x = (i % p->map_width) * BLOCK_SIZE + p->map_x + 1;
	p->player.y = (int)(i / p->map_width) * BLOCK_SIZE + p->map_y + 1;
}

bool	collide(t_entity t1, t_entity t2)
{
	if (t1.x <= t2.x + t2.size)
	{
		if (t1.x + t1.size >= t2.x)
		{
			if (t1.y <= t2.y + t2.size)
			{
				if (t1.y + t1.size >= t2.y)
					return (1);
			}
		}
	}
	return (0);
}

