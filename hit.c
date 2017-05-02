/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 20:01:14 by rbejot            #+#    #+#             */
/*   Updated: 2016/06/09 18:42:51 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

t_info		lateral_orientation(t_info *d)
{
	if (d->player.y > d->map.y)
		d->orientation = 4;
	else
		d->orientation = 2;
	return (*d);
}

t_info		front_orientation(t_info *d)
{
	if (d->player.x > d->map.x)
		d->orientation = 3;
	else
		d->orientation = 1;
	return (*d);
}

t_info		ft_hit(int *side, t_info *d, int worldmap[25][25])
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if ((d->sidedist.x) < (d->sidedist.y))
		{
			(d->sidedist.x) += (d->deltadist.x);
			(d->map.x) += (d->step.x);
			front_orientation(d);
			*side = 0;
		}
		else
		{
			(d->sidedist.y) += (d->deltadist.y);
			(d->map.y) += (d->step.y);
			lateral_orientation(d);
			*side = 1;
		}
		if (worldmap[(int)(d->map.x)][(int)(d->map.y)] > 0)
			hit = 1;
	}
	return (*d);
}
