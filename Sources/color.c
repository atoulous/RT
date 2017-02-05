/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:30:51 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/05 11:48:31 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb	transfo(unsigned int col, t_light *datas)
{
	t_hsv h;

	rgb_to_hsv(col, &h.h, &h.s, &h.v);
	datas->shadow = 0.0;
	return (my_hsv_to_rgb(h));
}

int		add_color(int c1, int c2, double i)
{
	int	r;
	int	g;
	int	b;

	i = fmin(1, i);
	b = ft_min(((c1 & 0x000000FF) >> 0) + ((c2 & 0x000000FF) >> 0) * i, 255);
	g = ft_min(((c1 & 0x0000FF00) >> 8) + ((c2 & 0x0000FF00) >> 8) * i, 255);
	r = ft_min(((c1 & 0x00FF0000) >> 16) + ((c2 & 0x00FF0000) >> 16) * i, 255);
	return ((r << 16) + (g << 8) + b);
}
