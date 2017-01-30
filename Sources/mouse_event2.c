/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 09:49:59 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/30 09:59:39 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_mouse_click2(int x, int y, t_env *e)
{
	if (x < 66)
		change_luminosite_mouse(e, y);
	else if (x > 79 && x < 119)
		del_focus_object(e);
	else if (x > 79 && x < 149)
		undo_del_object(e);
	else if (x > WIN_WIDTH / 2 - 64 && x < WIN_WIDTH / 2 + 64)
		change_global_quality(e);
	else if ( x > WIN_WIDTH - 50)
		save_scene(e);
}

void			ft_mouse_click3(int x, t_env *e)
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
