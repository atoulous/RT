/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_phong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 21:42:32 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/17 22:46:24 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#ifndef ANSWERS
# define ANSWERS
# define ANGLE_LIGHT res->angle_light
# define INTENSITE res->intensite
typedef struct		s_col_res
{
	t_rgb			rgb;
	double			angle_light;
	double			intensite;
	t_v3d			ref;
}					t_col_res;
#endif


void	get_color_phong(t_param *param, t_object *light, t_hsv *hsv, \
		t_col_res *res)
{
	t_object	*obj_sel;
	t_hsv		h;
	double		omega;


	rgb_to_hsv(VW_RAY.obj->color, &h.h, &h.s, &h.v);
	res->rgb = my_hsv_to_rgb(h);
	INTENSITE += VW_RAY.obj->mat.ambient;
	INTENSITE += (ANGLE_LIGHT * VW_RAY.obj->mat.diffuse);
	t_v3d test= smul_v3d(VW_RAY.norm, 2 * ANGLE_LIGHT);
	t_v3d r = sub_v3d(test, PHO_RAY.dir);
	omega = cos_v3d(VW_RAY.dir, r);
	INTENSITE += (VW_RAY.obj->mat.specular * pow(omega, \
				VW_RAY.obj->mat.shine));
	rgb_s_mult(&res->rgb, INTENSITE);
	rgb_reg(&res->rgb);
	*hsv = my_rgb_to_hsv(res->rgb);
}

void	get_color_jubarbie(t_param *param, t_object *light, t_col_res *res, \
		t_hsv *hsv)
{
	t_object	*obj_sel;
	if (ANGLE_LIGHT < 0)
	{
		hsv->v -= ANGLE_LIGHT * VW_RAY.obj->mat.diffuse;
		hsv->v = fmax(VW_RAY.obj->mat.diffuse, hsv->v);
		OPT_B ? do_shininess(param, light, hsv, res->ref) : 0;
	}
	light = light + 1 - 1;
	if (OPT_O && PHO_RAY.obj)
		hsv->v = fmax(VW_RAY.obj->mat.diffuse, hsv->v - 0.1);
	if (param->e->scene->obj_focus)
	{
		obj_sel = (t_object *)param->e->scene->obj_focus->content;
		if (VW_RAY.obj == obj_sel)
			hsv->s = 0;
	}
}


void	get_color(t_env *e, t_param *param, t_object *light, t_hsv *hsv)
{
	t_col_res res;

	res.intensite = 0;
	res.angle_light = cos_v3d(smul_v3d(VW_RAY.norm, -1), PHO_RAY.dir);
	res.ref = sub_v3d(PHO_RAY.dir, smul_v3d(VW_RAY.norm, 2.0 *
				dot_v3d(PHO_RAY.dir, VW_RAY.norm)));
	if (OPT_C)
		get_color_jubarbie(param, light, &res, hsv);
	else
		get_color_phong(param, light, hsv, &res);


}
