/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:20:53 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/05 17:38:17 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb		create_variation_rgb(t_rgb r, double coef)
{
	t_rgb a;

	a = r;
	rgb_s_mult(&a, coef);
	rgb_reg(&a);
	rgb_reg_min(&a);
	return (a);
}

t_rgb		random_noise(t_v3d vec, t_rgb rgb)
{
	double	n;
	t_v3d	v;
	t_rgb	a;
	t_rgb	b;
	t_rgb	c;

	v.x = 0.2;
	v.y = 0.4;
	v.z = 0.6;
	a = create_variation_rgb(rgb, 2);
	b = create_variation_rgb(rgb, 1 / 2);
	c = create_variation_rgb(rgb, 1 / 3);
	n = noise(vec.x, vec.y, vec.z);
	if (n == v.x)
		return (a);
	if (n == v.y)
		return (b);
	if (n == v.z)
		return (c);
	return (rgb);

}

