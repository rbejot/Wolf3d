/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 20:34:05 by rbejot            #+#    #+#             */
/*   Updated: 2016/06/09 18:43:02 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

int			key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		free(e);
		exit(0);
	}
	move(e, keycode);
	rotate(e, keycode);
	if (keycode == RETURN)
	{
		init_player(e);
		new_image(e);
		expose_hook(e);
	}
	return (0);
}

int			expose_hook(t_env *e)
{
	calc(e->data, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

int			ft_exit(void *param)
{
	param = 0;
	exit(1);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	*e;

	e = (t_env*)ft_memalloc(sizeof(t_env));
	if (ac != 2)
		usage(1);
	read_map(av, e);
	stock_map(e);
	init_player(e);
	window(e);
	mlx_key_hook(e->win, key_hook, e);
	new_image(e);
	expose_hook(e);
	mlx_hook(e->win, 2, (1L >> 0), &key_hook, e);
	mlx_hook(e->win, 17, (1L >> 0), ft_exit, e);
	mlx_loop(e->mlx);
	free(e);
	return (0);
}
