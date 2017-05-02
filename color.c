/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:50:02 by rbejot            #+#    #+#             */
/*   Updated: 2016/06/09 18:42:40 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

int			color(t_info *d)
{
	int		color;

	color = 0xFFFFFF;
	if (d->orientation == 1)
		color = RED;
	if (d->orientation == 2)
		color = GREEN;
	if (d->orientation == 3)
		color = BLUE;
	if (d->orientation == 4)
		color = YELLOW;
	return (color);
}
