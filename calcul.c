/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:51:49 by rbejot            #+#    #+#             */
/*   Updated: 2016/06/09 18:42:33 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

int			ft_neg(double ray, double *sided, double mapi, double deltad)
{
	*sided = (ray - mapi) * deltad;
	return (-1);
}

int			ft_pos(double ray, double *sided, double mapi, double deltad)
{
	*sided = (mapi + 1.0 - ray) * deltad;
	return (1);
}

t_info		init_data(t_info d, double camerax)
{
	d.raypos.x = d.player.x;
	d.raypos.y = d.player.y;
	d.raydir.x = d.direction.x + d.plane.x * camerax;
	d.raydir.y = d.direction.y + d.plane.y * camerax;
	d.map.x = d.raypos.x;
	d.map.y = d.raypos.y;
	d.deltadist.x = sqrt(1 + (d.raydir.y * d.raydir.y)
			/ (d.raydir.x * d.raydir.x));
	d.deltadist.y = sqrt(1 + (d.raydir.x * d.raydir.x)
			/ (d.raydir.y * d.raydir.y));
	if (d.raydir.x < 0)
		d.step.x = ft_neg(d.raypos.x, &(d.sidedist.x), d.map.x, d.deltadist.x);
	else
		d.step.x = ft_pos(d.raypos.x, &(d.sidedist.x), d.map.x, d.deltadist.x);
	if (d.raydir.y < 0)
		d.step.y = ft_neg(d.raypos.y, &(d.sidedist.y), d.map.y, d.deltadist.y);
	else
		d.step.y = ft_pos(d.raypos.y, &(d.sidedist.y), d.map.y, d.deltadist.y);
	return (d);
}

int			calc(t_info data, t_env *e)
{
	t_pos	coord;
	t_vert	draw;

	coord.x = 0;
	while (coord.x < WIDTH)
	{
		coord.y = 0;
		e->camerax = 2 * coord.x / WIDTH - 1;
		data = init_data(data, e->camerax);
		data = ft_hit(&e->side, &data, e->wl_map);
		draw = init_draw(e->side, &data, e);
		while (coord.y < HEIGHT)
		{
			data.color = color(&data);
			if (!(coord.y > draw.start))
				data.color = CLEAR_BLUE;
			if (!(coord.y < draw.end))
				data.color = WHITE;
			ft_draw(data.image, coord.x, coord.y, data.color);
			coord.y += 1;
		}
		coord.x += 1;
	}
	return (0);
}
