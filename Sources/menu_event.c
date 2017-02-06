/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:29:49 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/06 21:40:31 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	light_menu_event2(t_env *e, int x, int y, t_object *obj)
{
	double	step;

	step = (x > WIN_WIDTH - 20) ? 0.02 : -0.02;
	if (y > 450 && y < 467)
		(obj->mat.diffuse + step > 0 && obj->mat.diffuse + step < 1)
			? obj->mat.diffuse += step : 0;
	else if (y > 475 && y < 492)
		(obj->mat.ambient + step > 0 && obj->mat.ambient + step < 1)
			? obj->mat.ambient += step : 0;
	else if (y > 499 && y < 517)
		(obj->mat.specular + step > 0)
			? obj->mat.specular += step : 0;
	else if (y > 544 && y < 562)
		obj->coef += step;
	else if (y > 570 && y < 587)
		obj->density += (step * 100);
}

static void	object_menu_event(t_env *e, int x, int y, t_object *obj)
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
	else if (y > 450 && y < 587)
		light_menu_event2(e, x, y, obj);
	else
		click = 0;
	if (click)
	{
		(e->calc_obj_param[type]) ? e->calc_obj_param[type](obj) : 0;
		menu_object(e);
		create_img(e);
	}
}

void		top_menu_event(t_env *e, int x, int y)
{
	if (x >= 53 && x < WIN_WIDTH - 14 && y >= 10 && y <= 50)
	{
		if (x < 70)
			change_luminosite_mouse(e, y);
		else if (x > 82 && x < 116)
			del_focus_object(e);
		else if (x > 116 && x < 151)
			undo_del_object(e);
		else if (x > WIN_WIDTH / 2 - 64 && x < WIN_WIDTH / 2 + 64)
			change_global_quality(e);
		else if (x > WIN_WIDTH - 98 && x < WIN_WIDTH - 65)
			screenshot(e);
		else if (x > WIN_WIDTH - 50)
			save_scene(e);
	}
}

void		bottom_menu_event(t_env *e, int x, int y)
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

void		right_menu_event(t_env *e, int x, int y)
{
	t_object *obj;

	if (e->scene->obj_focus)
	{
		obj = (t_object *)(e->scene->obj_focus->content);
		if (x > WIN_WIDTH - 231 && x < WIN_WIDTH - 9 && y > 136 && y < 307)
			color_selector(e, x - WIN_WIDTH + 231, y - 136);
		if (x > WIN_WIDTH - 42 && x < WIN_WIDTH - 4 && y > 362 && y < 630)
			object_menu_event(e, x, y, obj);
		if (x > WIN_WIDTH - 231 && x < WIN_WIDTH - 9 && y > 600 && y < 659)
			text_menu_event(e, x, y, obj);
		if (x > WIN_WIDTH - 231 && x < WIN_WIDTH - 9 && y > 665 && y < 691)
			deform_menu_event(e, x, y, obj);
	}
	else if (x > WIN_WIDTH - 176 && x < WIN_WIDTH - 68)
	{
		(y > 183 && y < 208) ? active_grey(e) : 0;
		(y > 213 && y < 238) ? active_sepia(e) : 0;
		(y > 242 && y < 267) ? change_option(e, CRTN) : 0;
	}
}
