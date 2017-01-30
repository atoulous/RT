/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 21:18:41 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/30 17:12:34 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int pair(int a)
{
	if (a % 2 == 0)
		return (1);
	return (0);
}

t_rgb		color_damier(t_v3d inter)
{
	double l = 1;
	t_rgb c1 = rgb_create(12, 54, 111);
	t_rgb c2 = rgb_create(255, 1, 66);
	if (pair(inter.x / l))
	{
		if ((pair(inter.y) && pair(inter.z)) || (!pair(inter.y) && !pair(inter.z)))
			return (c1);
		else
			return (c2);
	}
	else
	{
		if ((pair(inter.y) && pair(inter.z)) || (!pair(inter.y) && !pair(inter.z)))
			return (c2);
		else
			return (c1);
	}
}

t_rgb		modify_color(t_v3d inter, double coef)
{
//	double mult = 100;
//	double output = 0;
	double noiseCoef = 0;
	t_rgb r;
	inter = smul_v3d(inter, coef);
//	for (int level = 1; level < 10; level ++)
//	{
//		noiseCoef += (1.0 / level) * fabs(noise(level * 0.05 * inter.x * mult, \
//					level * 0.05 * inter.y * mult, level * 0.05 * inter.z * mult));
//	};
	//noiseCoef = 0.5 * sinf((inter.x * mult + inter.y * mult) * 0.5 + noiseCoef) + 0.5;
	//noiseCoef = 0.5 * carre(inter.x * mult + inter.z * mult) * 0.5 + noiseCoef;
	
	//output += coef * noiseCoef * diffuse + (1.0 - noiseCoef);
	noiseCoef = fabs(noise(inter.x * coef, inter.y * coef, inter.z * coef));
//	noiseCoef = cos(inter.y + inter.x + noise(inter.x, inter.y, inter.z));
	double v = 20 * noiseCoef;
	int z = (int)v;
	v = v - z;
	if (v < 0.2)
		r = rgb_create(12, 45, 12);
	else if (v < 0.4)
		r = rgb_create(34, 77, 233);
	else if (v < 0.6)
		r = rgb_create(99, 143, 9);
	else if (v < 0.8)
		r = rgb_create(45, 34, 66);
	else
		r = rgb_create(255, 233, 244);
	return (r);
//	return (noiseCoef);
}
