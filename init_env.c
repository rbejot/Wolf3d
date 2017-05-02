/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 20:01:45 by rbejot            #+#    #+#             */
/*   Updated: 2016/06/09 18:42:57 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

void	window(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "wolf3d");
}

void	new_image(t_env *e)
{
	e->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data.image.imag = mlx_get_data_addr(e->img_ptr,
			&e->data.image.bpp,
			&e->data.image.size_line, &e->data.image.endian);
}

t_env	init_player(t_env *e)
{
	e->data.player.x = 10;
	e->data.player.y = 2;
	e->data.direction.x = -1;
	e->data.direction.y = 0;
	e->data.plane.x = 0;
	e->data.plane.y = 0.66;
	return (*e);
}
