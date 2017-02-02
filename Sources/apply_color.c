/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:39:07 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/02 17:01:10 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			do_phong_calcls(t_param *param, t_object *light, \
		t_light *datas)
{
	t_v3d	test;
	t_v3d	r;

	test = smul_v3d(VW_RAY.norm, 2 * datas->angle_light);
	r = unit_v3d(sub_v3d(test, PHO_RAY.dir));
	datas->omega = cos_v3d(VW_RAY.dir, r);
}

#define RGB datas->rgb
#define ALI datas->angle_light

void		apply_color(t_env *e, t_param *param, t_object *light, t_light *datas)
{
	datas->angle_light = cos_v3d(VW_RAY.norm, PHO_RAY.dir);
	do_phong_calcls(param, light, datas);
	if (OPT_2)
	{
		RGB.r += (ALI * RGB.r * VW_RAY.obj->mat.diffuse * -1);
		RGB.g += (ALI * RGB.g * VW_RAY.obj->mat.diffuse * -1);
		RGB.b += (ALI * RGB.b * VW_RAY.obj->mat.diffuse * -1);
	}
	if (OPT_3)
	{
		if (datas->omega > 0.000001)
		{
			RGB.r += RGB.r * VW_RAY.obj->mat.specular * pow(datas->omega, \
					VW_RAY.obj->mat.shine);
			RGB.g += RGB.g * VW_RAY.obj->mat.specular * pow(datas->omega, \
					VW_RAY.obj->mat.shine);
			RGB.b += RGB.b * VW_RAY.obj->mat.specular * pow(datas->omega, \
					VW_RAY.obj->mat.shine);
		}
	}
}
