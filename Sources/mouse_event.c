/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:46:55 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/30 10:01:42 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init_mouse_ray(t_env *e, t_param *param)
{
	MOUS_RAY.obj = NULL;
	MOUS_RAY.dist = DIST_MAX;
	MOUS_RAY.dir = unit_v3d(sub_v3d(add_v3d(VW_UP_LEFT, sub_v3d(smul_v3d( \
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
	menu_object(e);
}

int			ft_mouse_click(int button, int x, int y, t_env *e)
{
	if (button == 1 && x >= 50 && x < WIN_WIDTH - 14 && y >= 10 && y <= 50)
		ft_mouse_click2(x, y, e);
	else if (button == 1 && x >= IMG_GAP_X
			&& x <= WIN_WIDTH - 240 - IMG_GAP_X
			&& y > 49 + IMG_GAP_Y && y < 49 + IMG_GAP_Y + IMG_HEIGHT)
	{
		raytrace_mouse(e, x - IMG_GAP_X, y - 49 - IMG_GAP_Y);
		create_img(e);
	}
	else if (button == 1 && y > WIN_HEIGHT - 122 && y < WIN_HEIGHT - 10
			&& x > WIN_WIDTH / 2 - 268 && x < WIN_WIDTH / 2 + 268)
		ft_mouse_click3(x, e);
	else if (button == 1 && x > WIN_WIDTH - 231 && x < WIN_WIDTH - 9 && y > 270
			&& y < 442)
		color_selector(e, x - WIN_WIDTH + 231, y - 270);
	return (0);
}
