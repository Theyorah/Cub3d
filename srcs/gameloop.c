/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:38:56 by kralison          #+#    #+#             */
/*   Updated: 2025/02/02 11:15:33 by kralison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	st_handle_key(t_program *p)
{
	(void)p;
}

static void	st_update_logic(t_program *p)
{
	(void)p;
}

static void	st_update_rendering(t_program *p)
{
	(void)p;
}

int	main_loop(t_program *p)
{
	clear_win_img(&p->win, rgb(0, 0, 0));
	st_handle_key(p);
	st_update_logic(p);
	st_update_rendering(p);
	mlx_put_image_to_window(p->mlx, p->win.win, p->win.img, 0, 0);
	return (0);
}
