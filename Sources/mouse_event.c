/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:46:55 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/09 14:28:00 by mmoullec         ###   ########.fr       */
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
		(*(e->obj_fct_obj[obj->type]))(obj, &MOUS_RAY, &SOL);
		if (MOUS_RAY.obj == obj)
			foc_obj = lst_obj;
		lst_obj = lst_obj->next;
	}
	if (foc_obj == e->scene->obj_focus)
		foc_obj = NULL;
	e->scene->obj_focus = foc_obj;
}

void		change_light_status(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	(OPT_L) ? (OPT ^= (1 << 1)) : (OPT |= (1 << 1));
	create_img(e);
}

void		change_brillance_status(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	(OPT & (1 << 3)) ? (OPT ^= (1 << 3)) : (OPT |= (1 << 3));
	create_img(e);
}

int			ft_mouse_click(int button, int x, int y, t_env *e)
{
	if (button == 1 && x >= 14 && x < WIN_WIDTH - 14 && y >= 10 && y <= 50)
	{
		if (x < 50)
			del_focus_object(e);
		else if (x < 86)
			undo_del_object(e);
		else if (x > WIN_WIDTH / 2 - 64 && x < WIN_WIDTH / 2 + 64)
			change_light_status(e);
		else if ( x > WIN_WIDTH - 50)
			save_scene(e);
	}
	else if (button == 1 && x >= IMG_GAP
						&& x <= WIN_WIDTH - IMG_GAP
						&& y > 48 && y < 48 + IMG_HEIGHT)
	{
		raytrace_mouse(e, x - IMG_GAP, y - 49);
		create_img(e);
	}
	else if (button == 1 && y > WIN_HEIGHT - 122 && y < WIN_HEIGHT - 10
					&& x > WIN_WIDTH / 2 - 268 && x < WIN_WIDTH / 2 + 268)
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
	return (0);
}
