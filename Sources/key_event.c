/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 15:06:00 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/05 20:07:00 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	esc_n_select_obj(t_env *e, int keycode)
{
	if (keycode == 48)
	{
		if (!e->scene->obj_focus)
			e->scene->obj_focus = e->scene->obj;
		else
			e->scene->obj_focus = e->scene->obj_focus->next;
	}
	else if (keycode == 53)
	{
		if (!e->scene->obj_focus)
			quit_rt(e);
		else
			e->scene->obj_focus = NULL;
	}
	menu_object(e);
	create_img(e);
}

static void	move(t_env *e, int keycode)
{
	keycode == 126 ? MOVES |= M_UP : 0;
	keycode == 125 ? MOVES |= M_DOWN : 0;
	keycode == 123 || keycode == 0 ? MOVES |= M_LEFT : 0;
	keycode == 124 || keycode == 2 ? MOVES |= M_RIGHT : 0;
	keycode == 13 || keycode == 69 ? MOVES |= M_FORWARD : 0;
	keycode == 1 || keycode == 78 ? MOVES |= M_BACKWARD : 0;
	keycode == 86 ? ROT |= M_LEFT : 0;
	keycode == 88 ? ROT |= M_RIGHT : 0;
	keycode == 84 ? ROT |= M_DOWN : 0;
	keycode == 91 ? ROT |= M_UP : 0;
}

static void	after_effects(t_env *e, int keycode)
{
	keycode == 41 ? active_sepia(e) : 0;
	keycode == 39 ? active_grey(e) : 0;
	keycode == 8 ? change_option(e, CRTN) : 0;
	keycode == 46 ? active_motion_blur(e) : 0;
}

int			ft_key_release(int keycode, t_env *e)
{
	keycode == 126 ? MOVES ^= M_UP : 0;
	keycode == 125 ? MOVES ^= M_DOWN : 0;
	keycode == 123 || keycode == 0 ? MOVES ^= M_LEFT : 0;
	keycode == 124 || keycode == 2 ? MOVES ^= M_RIGHT : 0;
	keycode == 13 || keycode == 69 ? MOVES ^= M_FORWARD : 0;
	keycode == 1 || keycode == 78 ? MOVES ^= M_BACKWARD : 0;
	keycode == 86 ? ROT ^= M_LEFT : 0;
	keycode == 88 ? ROT ^= M_RIGHT : 0;
	keycode == 84 ? ROT ^= M_DOWN : 0;
	keycode == 91 ? ROT ^= M_UP : 0;
	COMMAND = 0;
	return (0);
}

int			ft_key_press(int keycode, t_env *e)
{
	IS_OPT_D ? ft_putnbr(keycode) : 0;
	keycode == 53 || keycode == 48 ? esc_n_select_obj(e, keycode) : 0;
	keycode == 51 ? del_focus_object(e) : 0;
	keycode == 31 ? change_option(e, SHADOW) : 0;
	keycode == 11 ? change_option(e, SHINE) : 0;
	keycode == 37 ? change_option(e, LIGHT) : 0;
	keycode == 18 ? change_option(e, PHONG) : 0;
	keycode == 19 ? change_option(e, OPT_I1) : 0;
	keycode == 20 ? change_option(e, SHINE) : 0;
	keycode == 27 || keycode == 24 ? change_speed_rotation(e, keycode) : 0;
	keycode == 67 || keycode == 75 ? change_luminosite(e, keycode) : 0;
	keycode == 71 || keycode == 81 ? change_ambiance(e, keycode) : 0;
	keycode == 259 ? COMMAND = 1 : 0;
	keycode == 7 ? antialiasing(e): 0;
	keycode == 6 && COMMAND == 1 ? undo_del_object(e) : 0;
	keycode == 47 ? SPEED += 0.1 : 0;
	keycode == 43 ? SPEED -= 0.1 : 0;
	keycode == 49 ? reset_cam(e) : 0;
	keycode == 50 ? screenshot(e) : 0;
	keycode == 35 ? change_option(e, BPLANE) : 0;
	keycode == 15 || keycode == 17 ? change_indice_reflection(e, keycode) : 0;
	keycode == 40 ? add_lampe(e) : 0;
	move(e, keycode);
	after_effects(e, keycode);
	return (0);
}
