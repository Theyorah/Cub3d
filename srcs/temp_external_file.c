#include <cub3d.h>

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
			draw_square(p, entity((i % p->map_width) * BLOCK_SIZE + p->map_pos.x,
				(int)(i / p->map_width) * BLOCK_SIZE + p->map_pos.y,
					BLOCK_SIZE), rgb(90, 60, 60));
		i++;
	}
}

int	init_map(t_program *p)
{
	p->map_height = 15;
	p->map_width = 33;
	/*p->map_height = 8;*/
	/*p->map_width = 8;*/
	p->map_pos.x = 0;
	p->map_pos.y = 0;
	/*p->map = ft_memcpy(ft_calloc(p->map_height * p->map_width + 1, sizeof(char)), "111111111000000110001001100000011000N001100000011000000111111111", p->map_width * p->map_height);*/
	p->map = ft_memcpy(ft_calloc(p->map_height * p->map_width + 1,
				sizeof(char)),
					"000000010000000000000000000000000        0111111111111111111111111        10000N0000110000000000001        1011000001110000000000001        100100000000000000000000111111111101100000111000000000000110000000001100000111011111111111111110111111111011100000010001    11110111111111011101010010001    11000000110101011100000010001    10000000000000001100000010001    10000000000000001101010010001    1100000111010101111101100000111  11110111 1110101 101111010001    11111111 1111111 111111111111    ",
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
	p->player.direction = vector(0, 100);
	p->player.plane = vector(66.6, 0);
	p->player.vel.x = 0;
	p->player.vel.y = 0;
	p->player.r_speed = 0;
	p->player.size = BLOCK_SIZE / 4;
	p->player.pos.x = (i % p->map_width) * BLOCK_SIZE + p->map_pos.x + 1
		+ (double)BLOCK_SIZE / 2 - (double)p->player.size / 2;
	p->player.pos.y = (int)(i / p->map_width) * BLOCK_SIZE + p->map_pos.y + 1
		+ (double)BLOCK_SIZE / 2 - (double)p->player.size / 2;
	p->player.speed = p->player.size * 0.05;
}
