/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:29:49 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/06 20:30:14 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	deform_menu_event(t_env *e, int x, int y, t_object *obj)
{
	char 	*tex;

	if (x < WIN_WIDTH - 120)
		tex =  ft_strdup("bump");
	else 
		tex = ft_strdup("water");
	if (obj->asp && ft_strcmp(obj->asp, tex))
	{
		free(obj->asp);
		obj->asp = NULL;
		obj->asp = ft_strdup(tex);
	}
	else if (obj->asp && !ft_strcmp(obj->asp, tex))
	{
		free(obj->asp);
		obj->asp = NULL;
	}
	else
		obj->asp = ft_strdup(tex);
	free(tex);
	menu_object(e);
	create_img(e);
}

void	text_menu_event(t_env *e, int x, int y, t_object *obj)
{
	char 	*tex;

	if (x < WIN_WIDTH - 120)
		tex = (y < 598) ? ft_strdup("marbre") : ft_strdup("damier");
	else 
		tex = (y < 598) ? ft_strdup("wood") : ft_strdup("random");
	if (obj->pro && ft_strcmp(obj->pro, tex))
	{
		free(obj->pro);
		obj->pro = NULL;
		obj->pro = ft_strdup(tex);
	}
	else if (obj->pro && !ft_strcmp(obj->pro, tex))
	{
		free(obj->pro);
		obj->pro = NULL;
	}
	else
		obj->pro = ft_strdup(tex);
	free(tex);
	menu_object(e);
	create_img(e);
}


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
	else if (y > 484 && y < 501)
		(obj->mat.diffuse + step > 0 && obj->mat.diffuse + step < 1) 
			? obj->mat.diffuse += step : 0;
	else if (y > 509 && y < 526)
		(obj->mat.ambient + step > 0 && obj->mat.ambient + step < 1)
			? obj->mat.ambient += step : 0;
	else if (y > 533 && y < 551)
		(obj->mat.shine + step > 0)
			? obj->mat.shine += step : 0;
	else if (y > 559 && y < 575)
		(obj->mat.specular + step > 0 && obj->mat.specular + step < 1)
			? obj->mat.specular += step : 0;
	else if (y > 544 && y < 562)
		obj->coef += (step * 100);
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
		else if (x > WIN_WIDTH - 98 && x < WIN_WIDTH - 65)
			screenshot(e);
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
	if (e->scene->obj_focus)
	{
		if (x > WIN_WIDTH - 231 && x < WIN_WIDTH - 9 && y > 136
			&& y < 307)
			color_selector(e, x - WIN_WIDTH + 231, y - 136);
		if (x > WIN_WIDTH - 42 && x < WIN_WIDTH - 4 && y > 362
			&& y < 630)
			object_menu_event(e, x, y, (t_object *)(e->scene->obj_focus->content));
		if (x > WIN_WIDTH - 231 && x < WIN_WIDTH - 9 && y > 572 && y < 629)
			text_menu_event(e, x, y, (t_object *)(e->scene->obj_focus->content));
		if (x > WIN_WIDTH - 231 && x < WIN_WIDTH - 9 && y > 636 && y < 662)
			deform_menu_event(e, x, y, (t_object *)(e->scene->obj_focus->content));

	}
	else if (x > WIN_WIDTH - 176 && x < WIN_WIDTH - 68)
	{
		(y > 183 && y < 208) ? active_grey(e) : 0;
		(y > 213 && y < 238) ? active_sepia(e) : 0;
		(y > 242 && y < 267) ? change_option(e, CRTN) : 0;
	}
}
