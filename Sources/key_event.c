/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 15:06:00 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/22 11:06:24 by jubarbie         ###   ########.fr       */
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
	else if (keycode == 13)
		MOVES |= M_FORWARD;
	else if (keycode == 1)
		MOVES |= M_BACKWARD;
}

int			ft_key_release(int keycode, t_env *e)
{
	if (keycode == 126)
		MOVES ^= M_UP;
	else if (keycode == 125)
		MOVES ^= M_DOWN;
	else if (keycode == 123)
		MOVES ^= M_LEFT;
	else if (keycode == 124)
		MOVES ^= M_RIGHT;
	else if (keycode == 13)
		MOVES ^= M_FORWARD;
	else if (keycode == 1)
		MOVES ^= M_BACKWARD;
	return (0);
}

int			ft_key_press(int keycode, t_env *e)
{
	if (OPT_D)
		printf("%d\n", keycode);
	if (keycode == 53)
	{
		if (e->scene->obj_focus)
		{
			e->scene->obj_focus = NULL;
			create_img(e);
		}
		else
			quit_rt(e);
	}
	if (keycode == 48)
		select_next_obj(e);
	if (keycode == 51)
		del_sel_object(e);
	else if (keycode == 37)
		change_light_status(e);
	else
		move(keycode, e);
	return (0);
}
