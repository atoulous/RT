/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 08:30:59 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/09 13:41:15 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		change_luminosite(t_env *e, int keycode)
{
	keycode == 67 && LUMI + 0.05 <= 1 ? LUMI += 0.05 : 0;
	keycode == 75 && LUMI - 0.05 >= -0.5 ? LUMI -= 0.05 : 0;
	create_img(e);
}

void		change_luminosite_mouse(t_env *e, int y)
{
	if (y < 25)
		LUMI + 0.05 <= 1 ? LUMI += 0.05 : 0;
	else
		LUMI - 0.05 >= -0.5 ? LUMI -= 0.05 : 0;
	create_img(e);
}

/*
** Initialize light ray parameters
** This function is called for every pixel of the calculated image
*/

static void	init_light_ray(t_param *param, t_object *light)
{
	t_v3d	tmp;

	PHO_RAY.pos = light->pos;
	tmp = sub_v3d(VW_RAY.inter, PHO_RAY.pos);
	PHO_RAY.dist = length_v3d(tmp);
	PHO_RAY.dir = unit_v3d(tmp);
	PHO_RAY.obj = NULL;
}

/*
** Perform the shininess
*/

static void	do_shininess(t_param *param, t_object *light, t_hsv *hsv, t_v3d ref)
{
	int		color;
	double	angle_ref;

	if (VW_RAY.obj->mat.shine > 0.0)
	{
		angle_ref = cos_v3d(ref, VW_RAY.dir);
		if (angle_ref <= -0.95)
		{
			color = hsv_to_rgb(hsv->h, hsv->s, hsv->v);
			color = add_color(color, light->color, ((-0.95 - angle_ref) / 0.05)
													* VW_RAY.obj->mat.shine);
			rgb_to_hsv(color, &hsv->h, &hsv->s, &hsv->v);
		}
	}
}

/*
** Perform the diffuse light
** Set color to white if object has focus on
*/

static void	get_color(t_param *param, t_object *light, t_hsv *hsv)
{
	double		angle_light;
	t_v3d		ref;
	t_object	*obj_sel;
	t_env 		*e;

	e = param->e;
	angle_light = cos_v3d(VW_RAY.norm, PHO_RAY.dir);
	ref = sub_v3d(PHO_RAY.dir, smul_v3d(VW_RAY.norm, 2.0 *
				dot_v3d(PHO_RAY.dir, VW_RAY.norm)));
	if (angle_light < 0)
	{
		hsv->v -= angle_light * VW_RAY.obj->mat.diffuse;
		hsv->v = fmax(VW_RAY.obj->mat.diffuse, hsv->v);
		OPT_B ? do_shininess(param, light, hsv, ref) : 0;
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

/*
** Perform lights
*/

void		apply_light(t_env *e, t_param *param)
{
	t_list		*lst_light;
	t_list		*lst_obj;
	t_object	*obj;
	t_hsv		hsv;
	double		vm;

	rgb_to_hsv(VW_RAY.obj->color, &hsv.h, &hsv.s, &hsv.v);
	vm = hsv.v;
	hsv.v = VW_RAY.obj->mat.diffuse;
	lst_light = e->scene->light;
	while (lst_light)
	{
		lst_obj = e->scene->obj;
		init_light_ray(param, (t_object *)lst_light->content);
		while (lst_obj)
		{
			obj = (t_object *)lst_obj->content;
			if (obj != VW_RAY.obj)
				(*(e->obj_fct_obj[obj->type]))(obj, &PHO_RAY, &SOL);
			lst_obj = lst_obj->next;
		}
		get_color(param, (t_object *)lst_light->content, &hsv);
		lst_light = lst_light->next;
	}
	COLOR = hsv_to_rgb(hsv.h, hsv.s, LUMI + (hsv.v * vm));
}
