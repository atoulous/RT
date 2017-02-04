/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:29:49 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/04 19:18:36 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	object_menu_event(t_env *e, int x, int y, t_object *obj)
{
	double	step;
	int		type;
	int		click;

	step = (x > WIN_WIDTH - 20) ? 0.02 : -0.02;
	type = obj->type;
	click = 1;
	if (y > 360 && y < 382 && (type == 2 || type == 4))
		(obj->r1 + step > 0) ? obj->r1 += step : 0;
	else if (y > 384 && y < 406 && (type == 3 || type == 5))
		(obj->r1 + step > 0) ? obj->r1 += step : 0;
	else if (y > 408 && y < 430 && (type == 4 || type == 5))
		((obj->r2 + step > 0 && type == 5) || type == 4) ? obj->r2 += step : 0;
	else
		click = 0;
	if (click)
	{
		(e->calc_obj_param[type]) ? e->calc_obj_param[type](obj) : 0;
		menu_object(e);
		create_img(e);
	}
}

void	top_menu_event(t_env *e, int x, int y)
{
	if (x >= 53 && x < WIN_WIDTH - 14 && y >= 10 && y <= 50)
	{
		if (x < 70)
			change_luminosite_mouse(e, y);
		else if (x > 82 && x < 116)
			x = x + 0;
		else if (x > 116 && x < 151)
			y = y + 0;
		else if (x > 163 && x < 197)
			del_focus_object(e);
		else if (x > 197 && x < 232)
			undo_del_object(e);
		else if (x > WIN_WIDTH / 2 - 64 && x < WIN_WIDTH / 2 + 64)
			change_global_quality(e);
		else if (x > WIN_WIDTH - 50)
			save_scene(e);
	}
}

void	bottom_menu_event(t_env *e, int x, int y)
{
	if (y > WIN_HEIGHT - 122 && y < WIN_HEIGHT - 10
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
		else
			add_torus(e);
	}
}

void	right_menu_event(t_env *e, int x, int y)
{
	if (x > WIN_WIDTH - 231 && x < WIN_WIDTH - 9 && y > 136
			&& y < 307)
		color_selector(e, x - WIN_WIDTH + 231, y - 136);
	if (x > WIN_WIDTH - 42 && x < WIN_WIDTH - 4 && y > 362
			&& y < 430 && e->scene->obj_focus)
		object_menu_event(e, x, y, (t_object *)(e->scene->obj_focus->content));
}
