/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:29:13 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/03 15:49:15 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		change_luminosite_mouse(t_env *e, int y)
{
	if (y < 25)
		LUMI + 0.05 <= 1 ? LUMI += 0.05 : 0;
	else
		LUMI - 0.05 >= -0.5 ? LUMI -= 0.05 : 0;
	create_img(e);
}

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

t_rgb		transfo(unsigned int col, t_light *datas)
{
	t_hsv h;
	rgb_to_hsv(col, &h.h, &h.s, &h.v);
	datas->shadow = 0.0;
	return (my_hsv_to_rgb(h));
}

void		obj_sel(t_light *datas, t_param *param, t_object *light)
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
//		datas->shadow -= param->AMBIANCE * cos_v3d(PHO_RAY.dir, VW_RAY.norm) * -1;
}

void		apply_light(t_env *e, t_param *param)
{
	t_list		*lst_obj;
	t_list		*lst_light;
	t_light		datas;

	datas.rgb = transfo(VW_RAY.obj->color, &datas);
	if (OPT_1)
		rgb_s_mult(&datas.rgb, VW_RAY.obj->mat.ambient + LUMI);
	lst_light = e->scene->light;
	while (lst_light)
	{
		if (init_light_ray(param, lst_light->content))
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
				obj_sel(&datas, param, (t_object *)lst_light->content);
				!CARTOON ? apply_color(e, param, (t_object *)lst_light->content, &datas) : 0;
				CARTOON ? apply_cartoon_color(e, param, (t_object *)lst_light->content, &datas) : 0;
			}
		lst_light = lst_light->next;
	}
	datas.hsv = my_rgb_to_hsv(datas.rgb);
	COLOR = hsv_to_rgb(datas.hsv.h, datas.hsv.s, datas.hsv.v + datas.shadow);
}
