/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 20:32:18 by rbejot            #+#    #+#             */
/*   Updated: 2016/06/09 18:43:08 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

void		move_back(t_env *e, int keycode, double movespeed)
{
	if (keycode == S)
	{
		if (e->wl_map[(int)(e->data.player.x - e->data.direction.x
					* movespeed)][(int)(e->data.player.y)] == 0)
			e->data.player.x -= e->data.direction.x * movespeed;
		if (e->wl_map[(int)(e->data.player.x)][(int)(e->data.player.y
					- e->data.direction.y * movespeed)] == 0)
			e->data.player.y -= e->data.direction.y * movespeed;
		new_image(e);
		expose_hook(e);
	}
}

void		move(t_env *e, int keycode)
{
	double	movespeed;

	movespeed = 1;
	if (keycode == W)
	{
		if (e->wl_map[(int)(e->data.player.x + e->data.direction.x
					* movespeed)][(int)(e->data.player.y)] == 0)
			e->data.player.x += e->data.direction.x * movespeed;
		if (e->wl_map[(int)(e->data.player.x)][(int)(e->data.player.y
					+ e->data.direction.y * movespeed)] == 0)
			e->data.player.y += e->data.direction.y * movespeed;
		mlx_destroy_image(e->mlx, e->img_ptr);
		new_image(e);
		expose_hook(e);
	}
	move_back(e, keycode, movespeed);
}

void		rotate_left(t_env *e, int keycode, double rotspeed, t_info old)
{
	if (keycode == A)
	{
		old.direction.x = e->data.direction.x;
		e->data.direction.x = e->data.direction.x * cos(rotspeed)
			- e->data.direction.y * sin(rotspeed);
		e->data.direction.y = old.direction.x * sin(rotspeed)
			+ e->data.direction.y * cos(rotspeed);
		old.plane.x = e->data.plane.x;
		e->data.plane.x = e->data.plane.x * cos(rotspeed)
			- e->data.plane.y * sin(rotspeed);
		e->data.plane.y = old.plane.x * sin(rotspeed)
			+ e->data.plane.y * cos(rotspeed);
		new_image(e);
		expose_hook(e);
	}
}

void		rotate(t_env *e, int keycode)
{
	double	rotspeed;
	t_info	old;

	old.direction.x = e->data.direction.x;
	rotspeed = 0.19;
	if (keycode == D)
	{
		old.direction.x = e->data.direction.x;
		e->data.direction.x = e->data.direction.x * cos(-rotspeed)
			- e->data.direction.y * sin(-rotspeed);
		e->data.direction.y = old.direction.x * sin(-rotspeed)
			+ e->data.direction.y * cos(-rotspeed);
		old.plane.x = e->data.plane.x;
		e->data.plane.x = e->data.plane.x * cos(-rotspeed)
			- e->data.plane.y * sin(-rotspeed);
		e->data.plane.y = old.plane.x * sin(-rotspeed)
			+ e->data.plane.y * cos(-rotspeed);
		new_image(e);
		expose_hook(e);
	}
	rotate_left(e, keycode, rotspeed, old);
}
