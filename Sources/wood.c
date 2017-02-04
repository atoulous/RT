/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wood.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:16:09 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/30 16:40:51 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb			wood(t_v3d inter)
{
	double	coefnoise;
	double	coef;
	int		z;
	double	v;

	coef = 0.4;
	coefnoise = fabs(noise(inter.x * coef, inter.y * coef, inter.z * coef));
	v = 20 * coefnoise;
	z = (int)v;
	v -= z;
	if (v < 0.2)
		return (rgb_create(83, 55, 7));
	else if (v < 0.4)
		return (rgb_create(129, 99, 29));
	else if (v < 0.6)
		return (rgb_create(143, 107, 28));
	else if (v < 0.8)
		return (rgb_create(118, 84, 23));
	else
		return (rgb_create(141, 102, 28));
}
