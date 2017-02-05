/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marbre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:23:00 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/05 17:06:38 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb		marbre(t_v3d inter)
{
	int			level;
	int			mult;
	double		noisecoef;

	level = 0;
	mult = 10;
	noisecoef = 0;
	while (++level < 10)
	{
		noisecoef += (1.0 / level) * fabs(noise(level * 0.5 * inter.x * \
					mult, level * 0.5 * inter.y * mult, level * 0.5 * \
					inter.z * mult));
	}
	noisecoef = 0.5 * sinf((inter.x * mult + inter.y * mult) * 0.5 + \
			noisecoef) + 0.5;
	if (noisecoef < 0.3)
		return (rgb_create(12, 12, 12));
	if (noisecoef < 0.6)
		return (rgb_create(130, 130, 130));
	else
		return (rgb_create(255, 255, 255));
}
