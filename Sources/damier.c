/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damier.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:31:50 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/06 19:16:49 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		pair(int a)
{
	if (a % 2 == 0)
		return (1);
	return (0);
}

t_rgb	damier(double l, t_v3d inter, t_rgb col)
{
	t_rgb	a;

	a = rgb_create(255, 255, 255);
	if (pair(inter.x / l))
	{
		if ((pair(inter.y) && pair(inter.z)) ||
				(!pair(inter.y) && !pair(inter.z)))
			return (col);
		else
			return (a);
	}
	else
	{
		if ((pair(inter.y) && pair(inter.z)) ||
				(!pair(inter.y) && !pair(inter.z)))
			return (a);
		else
			return (col);
	}
}
