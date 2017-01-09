/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 15:06:00 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/06 13:29:07 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	select_next_obj(t_env *e)
{
	if (!e->scene->obj_focus)
		e->scene->obj_focus = e->scene->obj;
	else
		e->scene->obj_focus = e->scene->obj_focus->next;
	create_img(e);
}

static void	ft_esc_key(t_env *e)
{
	if (!e->scene->obj_focus)
		quit_rt(e);
	else
		e->scene->obj_focus = NULL;
	create_img(e);
}

static void	move(int keycode, t_env *e)
{
	if (keycode == 126)
		MOVES |= M_UP;
	else if (keycode == 125)
		MOVES |= M_DOWN;
	else if (keycode == 123)
		MOVES |= M_LEFT;
	else if (keycode == 124)
		MOVES |= M_RIGHT;
	else if (keycode == 13 || keycode == 69)
		MOVES |= M_FORWARD;
	else if (keycode == 1 || keycode == 78)
		MOVES |= M_BACKWARD;
}

int			ft_key_release(int keycode, t_env *e)
{
	if (keycode == 126)
		MOVES ^= M_UP;
	else if (keycode == 24)
		save_scene(e);
	else if (keycode == 125)
		MOVES ^= M_DOWN;
	else if (keycode == 123)
		MOVES ^= M_LEFT;
	else if (keycode == 124)
		MOVES ^= M_RIGHT;
	else if (keycode == 13 || keycode == 69)
		MOVES ^= M_FORWARD;
	else if (keycode == 1 || keycode == 78)
		MOVES ^= M_BACKWARD;
	COMMAND = 0;
	return (0);
}

int			ft_key_press(int keycode, t_env *e)
{
	OPT_D ? printf("%d\n", keycode) : 0;
	keycode == 53 ? ft_esc_key(e) : 0;
	keycode == 48 ? select_next_obj(e) : 0;
	keycode == 51 ? del_focus_object(e) : 0;
	keycode == 31 ? change_shadow_status(e) : 0;
	keycode == 11 ? change_brillance_status(e) : 0;
	keycode == 37 ? change_light_status(e) : 0;
	keycode == 67 || keycode == 75 ? change_luminosite(e, keycode) : 0;
	keycode == 259 ? COMMAND = 1 : 0;
	keycode == 6 && COMMAND == 1 ? undo_del_object(e) : 0;
	move(keycode, e);
	return (0);
}
