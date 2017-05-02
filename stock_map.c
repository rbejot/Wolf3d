/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:40:04 by rbejot            #+#    #+#             */
/*   Updated: 2016/06/09 18:43:19 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

t_env	stock_map(t_env *env)
{
	env->y = 0;
	env->tmp = env->begin_list;
	if (env->tmp->length != 25)
		usage(4);
	while (env->tmp)
	{
		env->x = 0;
		while (env->x < env->tmp->length)
		{
			env->wl_map[env->x][env->y] = env->tmp->tab[env->x];
			env->x++;
		}
		env->y++;
		env->tmp = env->tmp->next;
	}
	free(env->tmp);
	return (*env);
}
