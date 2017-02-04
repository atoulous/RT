/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_filter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgameiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:38:39 by dgameiro          #+#    #+#             */
/*   Updated: 2017/02/04 18:49:35 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sepia_filter(t_param *param)
{
	double r;
	double g;
	double b;

	r = F_COLOR.r; 
	g = F_COLOR.g; 
	b = F_COLOR.b; 
	F_COLOR.b = (b * 0.393) + (g * 0.769) + (r * 0.189);
	F_COLOR.g = (b * 0.349) + (g * 0.686) + (r * 0.168);
	F_COLOR.r = (b * 0.272) + (g * 0.534) + (r * 0.131);
}

void	grey_filter(t_param *param)
{
	double grey;

	grey = (F_COLOR.r + F_COLOR.g + F_COLOR.b) / 3;
	F_COLOR.r = grey;
	F_COLOR.g = grey;
	F_COLOR.b = grey;
}
