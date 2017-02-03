/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_phong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 21:42:32 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/01 17:51:40 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "answers.h"

#ifdef MY_MATH_H
# undef R

# ifndef ANSWERS_H
#  define ANSWERS_H
# endif

# ifndef ANSWERS
#  define ANSWERS
#  define ANGLE_LIGHT res->angle_light
#  define INTENSITE res->intensite
#  define TEST res->test
#  define OMEGA res->omega
#  define R res->r
#  define TMP res->tmp
# endif

# ifdef OPT
#  undef OPT
#  define OPT param->e->opt

void			do_phong_calcls(t_param *param, t_object *light, \
		t_col_res *res)
{
	TEST = smul_v3d(VW_RAY.norm, 2 * ANGLE_LIGHT);
	R = sub_v3d(TEST, PHO_RAY.dir);
	OMEGA = cos_v3d(VW_RAY.dir, R);
}
/*
   double			get_color_phong(t_param *param, t_object *light, \
   t_hsv *hsv, t_col_res *res)
   {
   t_object	*obj_sel;

   INTENSITE += VW_RAY.obj->mat.ambient;
   if (OPT_2)
   {
   if (ANGLE_LIGHT < 0)
   INTENSITE += (ANGLE_LIGHT * -1 * VW_RAY.obj->mat.diffuse);
   }
   do_phong_calcls(param, light, hsv, res);
//	if (OMEGA > 0)
//	{
//	if (OPT_3)
//	{
//		if (OPT_O && PHO_RAY.obj)
//				INTENSITE += 0;
//		else
//			INTENSITE += (VW_RAY.obj->mat.specular * pow(OMEGA, \
//						cos(VW_RAY.obj->mat.shine)));
//	}}
if (OPT_O && PHO_RAY.obj)
hsv->v = hsv->v - param->AMBIANCE;
return (INTENSITE);
}
*/
#  undef OPT
#  define OPT e->opt
# endif

void			get_color_jubarbie(t_param *param, t_object *light, \
		t_col_res *res, t_hsv *hsv)
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
		hsv->v = fmax(VW_RAY.obj->mat.diffuse, hsv->v - param->AMBIANCE);
	if (param->e->scene->obj_focus)
	{
		obj_sel = (t_object *)param->e->scene->obj_focus->content;
		if (VW_RAY.obj == obj_sel)
			hsv->s = 0;
	}
}

double			ft_ambient(double ambient)
{
	return (ambient);
}

double			ft_diffuse(double ambient, double angle)
{
	return (ambient * angle * -1);
}

double			ft_specular(double omega, double spec, double shine)
{
	return (spec * pow(omega, shine));
}

double			get_color(t_v3d *retour, t_env *e, t_param *param, t_object *light, t_hsv *hsv, t_rgb *rgb)
{
	double intensite;
	t_col_res res;

	t_rgb tmp = *rgb;
	*rgb = rgb_0();
	res.intensite = 0;
	res.angle_light = cos_v3d(VW_RAY.norm, PHO_RAY.dir);
	res.ref = sub_v3d(PHO_RAY.dir, smul_v3d(VW_RAY.norm, 2.0 *
				dot_v3d(PHO_RAY.dir, VW_RAY.norm)));
	if (OPT_1)
	{
		rgb->r += tmp.r * VW_RAY.obj->mat.ambient;
		rgb->g += tmp.g * VW_RAY.obj->mat.ambient;
		rgb->b += tmp.b * VW_RAY.obj->mat.ambient;
	}
	double lambert = ft_diffuse(res.angle_light, VW_RAY.obj->mat.diffuse);
	if (OPT_2 && res.angle_light < 0)
	{
		rgb->r += lambert * rgb->r;
		rgb->g += lambert * rgb->g;
		rgb->b += lambert * rgb->b;
	}
	do_phong_calcls(param, light, &res);
	//if (OPT_3)
	//{
		if (OPT_O && PHO_RAY.obj)
		{
			rgb->r += rgb->r * ft_specular(res.omega, VW_RAY.obj->mat.specular - param->AMBIANCE, VW_RAY.obj->mat.shine);
			rgb->g += rgb->g * ft_specular(res.omega, VW_RAY.obj->mat.specular - param->AMBIANCE, VW_RAY.obj->mat.shine);
			rgb->b += rgb->b * ft_specular(res.omega, VW_RAY.obj->mat.specular - param->AMBIANCE, VW_RAY.obj->mat.shine);
		}
		else
			if (res.omega > 0.00001)
		{
			rgb->r += rgb->r * ft_specular(res.omega, VW_RAY.obj->mat.specular, VW_RAY.obj->mat.shine);
			rgb->g += rgb->g * ft_specular(res.omega, VW_RAY.obj->mat.specular, VW_RAY.obj->mat.shine);
			rgb->b += rgb->b * ft_specular(res.omega, VW_RAY.obj->mat.specular, VW_RAY.obj->mat.shine);
		}
	//}
	if (OPT_O && PHO_RAY.obj)
		return (hsv->v - param->AMBIANCE);
	else
		return(hsv->v);
}
# undef R
# define R sol.res1
#endif
