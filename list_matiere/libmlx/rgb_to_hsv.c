/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hsv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:09:41 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/22 18:40:20 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

t_hsv				ret_hsv(t_rgb r, t_chsv *c)
{
	if (c->delta < 0.00001)
	{
		c->out.s = 0;
		c->out.h = 0;
	}
	if (c->max > 0.0)
		c->out.s = (c->delta / c->max);
	else
	{
		c->out.s = 0.0;
		c->out.v = NAN;
	}
	if (r.r >= c->max)
		c->out.h = (r.g - r.b) / c->delta;
	else
	{
		if (r.g >= c->max)
			c->out.h = 2.0 + (r.b - r.r) / c->delta;
		else
			c->out.h = 4.0 + (r.r - r.g) / c->delta;
	}
	c->out.h *= 60.0;
	if (c->out.h < 0.0)
		c->out.h += 360.0;
	return (c->out);
}

t_hsv				rgb_to_hsv(t_rgb rgb)
{
	t_chsv			c;

	c.min = rgb.r < rgb.g ? rgb.r : rgb.g;
	c.min = c.min < rgb.b ? c.min : rgb.b;
	c.max = rgb.r > rgb.g ? rgb.r : rgb.g;
	c.max = c.max > rgb.b ? c.max : rgb.b;
	c.out.v = c.max / 255;
	c.delta = c.max - c.min;
	return (ret_hsv(rgb, &c));
}
