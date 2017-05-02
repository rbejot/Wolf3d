/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 20:00:15 by rbejot            #+#    #+#             */
/*   Updated: 2016/06/09 19:26:29 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

int			ft_absl(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

double		ft_fabs(double nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void		ft_draw(t_im im, int x, int y, int color)
{
	int		i;
	int		index;

	i = 0;
	while (i < im.bpp / 8)
	{
		index = (y * im.size_line) + (x * (im.bpp / 8)) + i;
		im.imag[index] = color >> (i * 8);
		i++;
	}
}

t_vert		init_draw(int side, t_info *data, t_env *e)
{
	t_vert	draw2;
	int		lineheight;

	if (side == 0)
		e->perpwalldist = ft_fabs((data->map.x - data->raypos.x
					+ (1 - data->step.x) / 2) / data->raydir.x);
	else
		e->perpwalldist = ft_fabs((data->map.y - data->raypos.y
					+ (1 - data->step.y) / 2) / data->raydir.y);
	lineheight = ft_absl(HEIGHT / e->perpwalldist);
	if (((draw2.start = ((-lineheight / 2) + (HEIGHT / 2))) < 0))
		draw2.start = 0;
	if ((draw2.end = ((lineheight / 2) + (HEIGHT / 2))) >= HEIGHT)
		draw2.end = HEIGHT - 1;
	return (draw2);
}
