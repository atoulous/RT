/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 15:06:00 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/05 14:52:51 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	keycode == 53 ? ft_esc_key(e) : 0;
	keycode == 48 ? select_next_obj(e) : 0;
	keycode == 51 ? del_focus_object(e) : 0;
	keycode == 31 ? change_option(e, SHADOW) : 0;
	keycode == 11 ? change_option(e, SHINE) : 0;
	keycode == 37 ? change_option(e, LIGHT) : 0;
	keycode == 18 ? change_option(e, PHONG) : 0;
	keycode == 19 ? change_option(e, OPT_I1) : 0;
	keycode == 20 ? change_option(e, OPT_I2) : 0;
	keycode == 27 || keycode == 24 ? change_speed_rotation(e, keycode) : 0;
	keycode == 67 || keycode == 75 ? change_luminosite(e, keycode) : 0;
	keycode == 71 || keycode == 81 ? change_ambiance(e, keycode) : 0;
	keycode == 259 ? COMMAND = 1 : 0;
	keycode == 6 && COMMAND == 1 ? undo_del_object(e) : 0;
	keycode == 47 ? SPEED += 0.1 : 0;
	keycode == 43 ? SPEED -= 0.1 : 0;
	keycode == 49 ? reset_cam(e) : 0;
	keycode == 50 ? screenshot(e) : 0;
	keycode == 35 ? change_option(e, BPLANE) : 0;
	keycode == 15 || keycode == 17 ? change_indice_reflection(e, keycode) : 0;
	keycode == 8 ? change_option(e, CRTN) : 0;
	keycode == 41 || keycode == 39 ? active_filter(e, keycode) : 0;
	move(keycode, e);
	return (0);
}
