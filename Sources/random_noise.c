/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:20:53 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/05 19:37:47 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb		new_col(double n, t_rgb r1, double v1, t_rgb r2, double v2)
{
	t_rgb a;

	a.r = r1.r * (n - v1) / (v2 - v1) + r2.r * (v2 - n) / (v2 - v1);
	a.g = r1.g * (n - v1) / (v2 - v1) + r2.g * (v2 - n) / (v2 - v1);
	a.b = r1.b * (n - v1) / (v2 - v1) + r2.b * (v2 - n) / (v2 - v1);
	return (a);
}

t_rgb		random_noise(double coef, t_v3d vec, t_rgb rgb)
{
	double	n;
	t_4d	v;
	t_rgb	a;
	t_rgb	b;
	t_rgb	c;

	v.a = 0.0;
//	a = rgb_create(rgb.r, 15, rgb.b);
	a = rgb;
	rgb_s_mult(&a, 2);
	rgb_reg(&a);
	v.b = 0.3;
	b = rgb_create(15, rgb.g, rgb.b);
	v.c = 0.6;
	c = rgb_create(rgb.r, 15, rgb.b);
	v.d = 1;
	n = noise(vec.x * coef, vec.y * coef, vec.z * coef);
	if (n < v.b)
		return (new_col(n, a, v.a, b, v.b));
	if (n < v.c)
		return (new_col(n, b, v.b, c, v.c));
	if (n < v.d)
		return (new_col(n, c, v.c, rgb, v.d));
	return (rgb);
}
