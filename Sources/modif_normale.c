/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_normale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:53:42 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/06 17:13:29 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		modif_normale(double density, double alpha, t_v3d *norm, t_v3d inter)
{
//	t_v3d tmp;
	t_v3d tmp2;
	double noiseCoefx = noise(alpha * inter.x, alpha * inter.y, alpha * inter.z);
	double noiseCoefy = noise(alpha * inter.y, alpha * inter.z, alpha * inter.x);
	double noiseCoefz = noise(alpha * inter.z, alpha * inter.x, alpha * inter.y);

	tmp2.x = (1.0f - density) * norm->x + density * noiseCoefx;
	tmp2.y = (1.0f - density) * norm->y + density * noiseCoefy;
	tmp2.z = (1.0f - density) * norm->z + density * noiseCoefz;

	*norm = unit_v3d(tmp2);


	double tt = length_v3d(tmp2);
	double temp = carre(tt);
	if (temp == 0.0f)
		return ;
	else
	{
		tt = 1 / tt;
		norm->x = tmp2.x * tt;
		norm->y = tmp2.y * tt;
		norm->z = tmp2.z * tt;
		unit_v3d(*norm);
	}
}
