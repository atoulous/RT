/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 08:30:59 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/18 18:51:49 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		change_luminosite(t_env *e, int keycode)
{
	keycode == 67 && LUMI + 0.1 <= 1 ? LUMI += 0.1 : 0;
	keycode == 75 && LUMI - 0.1 >= 0 ? LUMI -= 0.1 : 0;
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

void	do_shininess(t_param *param, t_object *light, t_hsv *hsv, t_v3d ref)
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
 ** Perform lights
 */

void		apply_light(t_env *e, t_param *param)
{
	t_list		*lst_light;
	t_list		*lst_obj;
	t_object	*obj;
	t_hsv		hsv;
	double		vm;
	double		intensite;
	intensite = 0;

	rgb_to_hsv(VW_RAY.obj->color, &hsv.h, &hsv.s, &hsv.v);
	vm = hsv.v;
	if (OPT_1)
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
		get_color(e, param, (t_object *)lst_light->content, &hsv, &intensite);
		lst_light = lst_light->next;
	}
	t_rgb rgb;
	if (OPT_1)
		COLOR = hsv_to_rgb(hsv.h, hsv.s, LUMI + (hsv.v * vm));
	else
	{
		rgb = my_hsv_to_rgb(hsv);
		rgb_s_mult(&rgb, intensite);
		rgb_reg(&rgb);
		hsv = my_rgb_to_hsv(rgb);
		COLOR = hsv_to_rgb(hsv.h, hsv.s, LUMI + (hsv.v * vm));
	}
}
