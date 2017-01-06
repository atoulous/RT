/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:46:55 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/04 18:52:18 by atoulous         ###   ########.fr       */
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

	param = e->param[0];
	X = x;
	Y = y;
	MOUS_RAY.pos = CAM_POS;
	lst_obj = e->scene->obj;
	init_mouse_ray(e, param);
	while (lst_obj)
	{
		obj = (t_object *)lst_obj->content;
		(*(e->obj_fct_obj[obj->type]))(obj, &MOUS_RAY, &SOL);
		if (MOUS_RAY.obj == obj)
			e->scene->obj_focus = lst_obj;
		lst_obj = lst_obj->next;
	}
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

void		change_shadow_status(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	(OPT & (1 << 4)) ? (OPT ^= (1 << 4)) : (OPT |= (1 << 4));
	create_img(e);
}

int			ft_mouse_click(int button, int x, int y, t_env *e)
{
	int		i;

	if (button == 1 && x >= 0 && x < 34)
	{
		i = y / (BTN_SIZE + 4);
		i < NB_BTN ? MENU[i].btn_fct(e) : 0;
	}
	else if (button == 1 && x >= 40 && x <= WIN_WIDTH
			&& y >= 0 && y <= WIN_HEIGHT)
	{
		raytrace_mouse(e, x - 40, y);
		create_img(e);
	}
	return (0);
}
