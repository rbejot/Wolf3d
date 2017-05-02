/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:30:31 by rbejot            #+#    #+#             */
/*   Updated: 2016/06/09 18:43:24 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

void	usage(int condition)
{
	if (condition == 1)
		ft_putendl("WRONG NUMBER OF ARGUMENTS.");
	if (condition == 2)
		ft_putendl("FILE DOES NOT EXIST.");
	if (condition == 3)
		ft_putendl("LINE DOEST NOT MATCH.");
	if (condition == 4)
		ft_putendl("THE GAME NEED A MAP OF 25x25.");
	if (condition == 5)
		ft_putendl("THERE IS A NON-NUMERICAL ENTRY IN YOUR MAP.");
	exit(1);
}
