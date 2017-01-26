/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 21:18:41 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/26 22:49:37 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	noise(double x, double y, double z);

t_rgb		modify_color(t_v3d inter, t_rgb out)
{
	t_rgb ret;
	printf("r %f - g %f - b %f\n", out.r, out.g, out.b);
	double output = 0;
	double noiseCoef = 0;
	for (int level = 1; level < 10; level ++)
	{
		noiseCoef += (1.0 / level) * fabs(noise(level * 0.05 * inter.x, \
					level * 0.05 * inter.y, level * 0.05 * inter.z));
	};
	noiseCoef = 0.5 * sinf((inter.x + inter.y) * 0.5 + noiseCoef) + 0.5;
	printf("%f\n", noiseCoef);
	out.r = noiseCoef;
	out.g += noiseCoef;
	out.b += noiseCoef;
	rgb_reg(&out);
	ret.r = out.r;
	ret.g = out.g;
	ret.b = out.b;

	printf("r %f - g %f - b %f\n", out.r, out.g, out.b);
	return (ret);
}
