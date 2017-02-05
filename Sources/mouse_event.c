/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:46:55 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/05 12:16:04 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init_mouse_ray(t_env *e, t_param *param)
{
	MOUS_RAY.obj = NULL;
	MOUS_RAY.dist = DIST_MAX;
	MOUS_RAY.dir = unit_v3d(sub_v3d(add_v3d(VW_UP_LEFT, sub_v3d(smul_v3d(
				CAM_RIGHT, GAP_X * X), smul_v3d(CAM_UP, GAP_Y * Y))), CAM_POS));
}

static void	raytrace_mouse(t_env *e, int x, int y)
{
	t_list		*lst_obj;
	t_object	*obj;
	t_param		*param;
	t_list		*foc_obj;

	param = e->param[0];
	X = x;
	Y = y;
	MOUS_RAY.pos = CAM_POS;
	lst_obj = e->scene->obj;
	init_mouse_ray(e, param);
	foc_obj = NULL;
	while (lst_obj)
	{
		obj = (t_object *)lst_obj->content;
		(*(e->obj_fct_obj[obj->type]))(e, obj, &MOUS_RAY, &SOL);
		if (MOUS_RAY.obj == obj)
			foc_obj = lst_obj;
		lst_obj = lst_obj->next;
	}
	if (foc_obj == e->scene->obj_focus)
		foc_obj = NULL;
	e->scene->obj_focus = foc_obj;
	menu_object(e);
}

void		ft_mouse_click2(int x, int y, t_env *e)
{
	if (x < 66)
		change_luminosite_mouse(e, y);
	else if (x > 79 && x < 119)
		del_focus_object(e);
	else if (x > 79 && x < 149)
		undo_del_object(e);
	else if (x > WIN_WIDTH / 2 - 64 && x < WIN_WIDTH / 2 + 64)
		change_global_quality(e);
	else if (x > WIN_WIDTH - 50)
		save_scene(e);
}

void		ft_mouse_click3(int x, t_env *e)
{
	if (x < WIN_WIDTH / 2 - 160)
		add_sphere(e);
	else if (x < WIN_WIDTH / 2 - 50)
		add_plane(e);
	else if (x < WIN_WIDTH / 2 + 50)
		add_cylinder(e);
	else if (x < WIN_WIDTH / 2 + 160)
		add_cone(e);
}

int			ft_mouse_click(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		top_menu_event(e, x, y);
		bottom_menu_event(e, x, y);
		right_menu_event(e, x, y);
		if (x >= IMG_GAP_X && x <= WIN_WIDTH - 240 - IMG_GAP_X
				&& y > 49 + IMG_GAP_Y && y < 49 + IMG_GAP_Y + IMG_HEIGHT)
		{
			raytrace_mouse(e, x - IMG_GAP_X, y - 49 - IMG_GAP_Y);
			create_img(e);
		}
	}
	return (0);
}
