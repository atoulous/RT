/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 21:18:41 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/27 18:02:59 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	noise(double x, double y, double z);

double		modify_color(t_v3d inter, double coef, double diffuse)
{
	double mult = 100;
	double output = 0;
	double noiseCoef = 0;
	for (int level = 1; level < 10; level ++)
	{
		noiseCoef += (1.0 / level) * fabs(noise(level * 0.05 * inter.x * mult, \
					level * 0.05 * inter.y * mult, level * 0.05 * inter.z * mult));
	};
	noiseCoef = 0.5 * sinf((inter.x * mult + inter.y * mult) * 0.5 + noiseCoef) + 0.5;
	//noiseCoef = 0.5 * carre(inter.x * mult + inter.z * mult) * 0.5 + noiseCoef;
	output += coef * noiseCoef * diffuse + (1.0 - noiseCoef);
	return (output);
}
