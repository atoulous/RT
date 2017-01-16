/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:41:19 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/13 17:42:22 by atoulous         ###   ########.fr       */
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
	VW_UP_LEFT = sub_v3d(add_v3d(add_v3d(CAM_POS,
			smul_v3d(CAM_DIR, VW_DIST)), smul_v3d(CAM_UP, VW_HEIGHT / 2.0)),
			smul_v3d(CAM_RIGHT, VW_WIDTH / 2.0));
}

/*
** Initialize view ray parameters
** This function is called for every pixel of the calculated image
*/

static void	init_vw_ray(t_env *e, t_param *param)
{
	VW_RAY.obj = NULL;
	VW_RAY.dist = DIST_MAX;
	VW_RAY.dir = unit_v3d(sub_v3d(add_v3d(VW_UP_LEFT, sub_v3d(smul_v3d(
			CAM_RIGHT, GAP_X * X), smul_v3d(CAM_UP, GAP_Y * Y))), CAM_POS));
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

	lst_obj = ENV->scene->obj;
	init_vw_ray(ENV, param);
	while (lst_obj)
	{
		obj = (t_object *)lst_obj->content;
		(*(e->obj_fct_obj[obj->type]))(obj, &VW_RAY, &SOL);
		lst_obj = lst_obj->next;
	}
	VW_RAY.inter = add_v3d(VW_RAY.pos, smul_v3d(VW_RAY.dir, VW_RAY.dist));
	COLOR = VW_RAY.obj ? VW_RAY.obj->color : 0;
	if (param->e->scene->obj_focus)
	{
		obj_sel = (t_object *)param->e->scene->obj_focus->content;
		if (VW_RAY.obj == obj_sel)
			COLOR = 0x00FFFFFF;
	}
	(VW_RAY.obj && OPT_L) ? apply_light(ENV, param) : 0;
	img_put_pixel(&e->img, X, Y, COLOR);
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
