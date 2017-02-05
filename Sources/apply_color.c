/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:39:07 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/05 13:24:09 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		do_phong_calcls(t_param *param, t_object *light,
		t_light *datas)
{
	t_v3d	test;
	t_v3d	r;

	test = smul_v3d(VW_RAY.norm, 2 * datas->angle_light);
	r = unit_v3d(sub_v3d(test, PHO_RAY.dir));
	datas->omega = cos_v3d(VW_RAY.dir, r);
}

static void	apply_intensity2(t_env *e, t_param *param, t_light *datas)
{
	if (IS_OPT_I2)
	{
		if (datas->omega > 0.000001 && !PHO_RAY.obj)
		{
			if (OMEGA < 0.7)
				OMEGA = 0;
			else if (OMEGA < 0.9)
				OMEGA = 0.7;
			else
				OMEGA = 1;
			RGB.r += 255 * VW_RAY.obj->mat.specular * pow(datas->omega,
					VW_RAY.obj->mat.shine);
			RGB.g += 255 * VW_RAY.obj->mat.specular * pow(datas->omega,
					VW_RAY.obj->mat.shine);
			RGB.b += 255 * VW_RAY.obj->mat.specular * pow(datas->omega,
					VW_RAY.obj->mat.shine);
		}
	}
}

void		apply_color(t_env *e, t_param *param, t_object *light,
		t_light *datas)
{
	datas->angle_light = cos_v3d(VW_RAY.norm, PHO_RAY.dir);
	do_phong_calcls(param, light, datas);
	if (IS_OPT_I1)
	{
		RGB.r += (ALI * 255 * VW_RAY.obj->mat.diffuse * -1);
		RGB.g += (ALI * 255 * VW_RAY.obj->mat.diffuse * -1);
		RGB.b += (ALI * 255 * VW_RAY.obj->mat.diffuse * -1);
	}
	if (IS_OPT_I2)
	{
		if (datas->omega > 0.000001 && !PHO_RAY.obj)
		{
			RGB.r += 255 * VW_RAY.obj->mat.specular * pow(datas->omega,
					VW_RAY.obj->mat.shine);
			RGB.g += 255 * VW_RAY.obj->mat.specular * pow(datas->omega,
					VW_RAY.obj->mat.shine);
			RGB.b += 255 * VW_RAY.obj->mat.specular * pow(datas->omega,
					VW_RAY.obj->mat.shine);
		}
	}
}

void		apply_cartoon_color(t_env *e, t_param *param, t_object *light,
		t_light *datas)
{
	datas->angle_light = cos_v3d(VW_RAY.norm, PHO_RAY.dir);
	do_phong_calcls(param, light, datas);
	if (cos_v3d(VW_RAY.norm, VW_RAY.dir) > -0.3 && VW_RAY.obj->type != 1 &&
			cos_v3d(VW_RAY.norm, VW_RAY.dir) < -0.000001)
	{
		RGB.r = 0;
		RGB.g = 0;
		RGB.b = 0;
		return ;
	}
	if (IS_OPT_I1)
	{
		if (ALI > -0.2)
			ALI = 0;
		else
			ALI = -1;
		RGB.r += (ALI * 255 * VW_RAY.obj->mat.diffuse * -1);
		RGB.g += (ALI * 255 * VW_RAY.obj->mat.diffuse * -1);
		RGB.b += (ALI * 255 * VW_RAY.obj->mat.diffuse * -1);
	}
	apply_intensity2(e, param, datas);
}
