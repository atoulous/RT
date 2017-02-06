/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:41:19 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/05 15:40:27 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Compute VW_UP_LEFT
** This function is called only once before performing the raytracing
*/

static void	init_param(t_param *param, t_env *e)
{
	VW_RAY.pos = CAM_POS;
	CAM_UP = v3d(0, 1, 0);
	CAM_RIGHT = cross_v3d(CAM_UP, CAM_DIR);
	CAM_UP = cross_v3d(CAM_DIR, CAM_RIGHT);
	VW_UP_LEFT = sub_v3d(add_v3d(add_v3d(CAM_POS,
			smul_v3d(CAM_DIR, VW_DIST)), smul_v3d(CAM_UP, VW_HEIGHT / 2.0)),
			smul_v3d(CAM_RIGHT, VW_WIDTH / 2.0));
}

/*
** Initialize view ray parameters
** This function is called for every pixel of the calculated image
*/

static void	init_vw_ray(t_env *e, t_param *param, int i_reflec)
{
	if (i_reflec)
	{
		REF_COEFF *= VW_RAY.obj->mat.diffuse;
		if (IS_CRTN && (cos_v3d(VW_RAY.norm, VW_RAY.dir) > -0.3 && \
			VW_RAY.obj->type != 2 && cos_v3d(VW_RAY.norm, VW_RAY.dir) \
			< -0.000001))
			REF_COEFF = 0;
		VW_RAY.pos = VW_RAY.inter;
		VW_RAY.dir = unit_v3d(sub_v3d(VW_RAY.dir,
		smul_v3d(VW_RAY.norm, 2.0 * cos_v3d(VW_RAY.dir, VW_RAY.norm))));
	}
	else
	{
		VW_RAY.dir = unit_v3d(sub_v3d(add_v3d(VW_UP_LEFT, sub_v3d(smul_v3d(
			CAM_RIGHT, GAP_X * X), smul_v3d(CAM_UP, GAP_Y * Y))), CAM_POS));
		VW_RAY.pos = CAM_POS;
		REF_COEFF = 1;
	}
	VW_RAY.obj = NULL;
	VW_RAY.dist = DIST_MAX;
}

/*
** Process every item of the objects list and determine if it crosses the ray
** Keep the closest object found and compute the position of the intersection
** Save the color (black if no objects and white if object has focus on)
** Call the apply_light function to determinate the color regarding the light
** Save the pixel color on the image
*/

static void	perform_raytracing(t_env *e, t_param *param)
{
	t_list		*lst_obj;
	t_object	*obj;
	t_object	*obj_sel;
	int			i_reflec;

	i_reflec = -1;
	init_reflect(param);
	while (++i_reflec <= NB_REF && REF_COEFF > 0.000001)
	{
		lst_obj = ENV->scene->obj;
		init_vw_ray(ENV, param, i_reflec);
		while (lst_obj)
		{
			obj = (t_object *)lst_obj->content;
			(*(e->obj_fct_obj[obj->type]))(e, obj, &VW_RAY, &SOL);
			lst_obj = lst_obj->next;
		}
		VW_RAY.inter = add_v3d(VW_RAY.pos, smul_v3d(VW_RAY.dir, VW_RAY.dist));
		COLOR = VW_RAY.obj ? VW_RAY.obj->color : 0;
		if (param->e->scene->obj_focus)
		{
			obj_sel = (t_object *)param->e->scene->obj_focus->content;
			if (VW_RAY.obj == obj_sel)
				if (cos_v3d(VW_RAY.norm, VW_RAY.dir) > -0.3 && VW_RAY.obj->type
						!= 1 && cos_v3d(VW_RAY.norm, VW_RAY.dir) < -0.000001)
				{
					F_COLOR.r = 255;
					F_COLOR.g = 255;
					F_COLOR.b = 255;
					break;
				}
		}
		(VW_RAY.obj && IS_LIGHT) ? apply_light(ENV, param) : 0;
		if (!VW_RAY.obj)
			break;
		add_reflected_color(param);
		if (!IS_REFLX)
			break;
	}
	img_put_pixel(&e->img, X, Y, param);
}

/*
** Process the raytracing for each image pixel in the thread
*/

void		*raytracer(void *arg)
{
	t_param		*param;
	t_env		*e;

	param = (t_param *)arg;
	init_param(param, ENV);
	e = ENV;
	Y = TH * (IMG_HEIGHT / NB_TH) - 1;
	while (++Y < (TH + 1) * IMG_HEIGHT / NB_TH)
	{
		X = -1;
		while (++X < IMG_WIDTH)
			perform_raytracing(e, param);
	}
	pthread_exit(0);
}
