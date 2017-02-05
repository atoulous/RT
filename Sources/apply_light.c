/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:29:13 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/05 13:39:10 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	init_light_ray(t_param *param, t_object *light)
{
	t_v3d	tmp;

	PHO_RAY.pos = light->pos;
	tmp = sub_v3d(VW_RAY.inter, PHO_RAY.pos);
	PHO_RAY.dist = length_v3d(tmp);
	PHO_RAY.dir = unit_v3d(tmp);
	PHO_RAY.obj = NULL;
	if (light->angle && (dot_v3d(PHO_RAY.dir, light->dir) < cos(light->angle)))
		return (0);
	return (1);
}

static void	obj_sel(t_light *datas, t_param *param, t_object *light)
{
	t_object *obj_sel;

	datas->ray = 1;
	if (param->e->scene->obj_focus)
	{
		obj_sel = (t_object *)param->e->scene->obj_focus->content;
		if (VW_RAY.obj == obj_sel)
			datas->ray = 0;
	}
	if (PHO_RAY.obj)
		datas->shadow -= param->AMBIANCE;
	//datas->shadow -= param->AMBIANCE * cos_v3d(PHO_RAY.dir, VW_RAY.norm) * -1;
}

static void	perform_light(t_env *e, t_param *param, t_list *light,
				t_light datas)
{
	t_list		*lst_obj;

	if (init_light_ray(param, light->content))
		if (cos_v3d(PHO_RAY.dir, VW_RAY.norm) < 0.00001)
		{
			lst_obj = e->scene->obj;
			while (lst_obj)
			{
				datas.obj = (t_object *)lst_obj->content;
				if (datas.obj != VW_RAY.obj)
					(*(e->obj_fct_obj[datas.obj->type]))(e, datas.obj, \
							&PHO_RAY, &SOL);
				lst_obj = lst_obj->next;
			}
		}
	obj_sel(&datas, param, (t_object *)light->content);
	!IS_CRTN ? apply_color(e, param, (t_object *)light->content, &datas) : 0;
	IS_CRTN ?
		apply_cartoon_color(e, param, (t_object *)light->content, &datas) : 0;
}

void		apply_light(t_env *e, t_param *param)
{
	t_list		*lst_light;
	t_light		datas;

	datas.rgb = transfo(VW_RAY.obj->color, &datas);
	if (IS_PHONG)
		rgb_s_mult(&datas.rgb, VW_RAY.obj->mat.ambient + LUMI);
	lst_light = e->scene->light;
	while (lst_light)
	{
		perform_light(e, param, lst_light, datas);
		lst_light = lst_light->next;
	}
	datas.hsv = my_rgb_to_hsv(datas.rgb);
	COLOR = hsv_to_rgb(datas.hsv.h, datas.hsv.s, datas.hsv.v + datas.shadow);
}
