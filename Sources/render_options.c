/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:55:45 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/05 15:09:21 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	change_luminosite_mouse(t_env *e, int y)
{
	if (y < 25)
		LUMI + 0.05 <= 1 ? LUMI += 0.05 : 0;
	else
		LUMI - 0.05 >= -0.5 ? LUMI -= 0.05 : 0;
	create_img(e);
}

void	active_filter(t_env *e, int keycode)
{
	if (keycode == 41)
	{
		(IS_GREY && !IS_SEPIA) ? (OPT ^= GREY) : 0;
		(IS_SEPIA) ? (OPT ^= SEPIA) : (OPT |= SEPIA);
	}
	else if (keycode == 39)
	{
		(IS_SEPIA && !IS_GREY) ? (OPT ^= SEPIA) : 0;
		(IS_GREY) ? (OPT ^= GREY) : (OPT |= GREY);
	}
	menu_object(e);
	create_img(e);
}

void	change_option(t_env *e, int opt)
{
	(OPT & opt) ? (OPT ^= opt) : (OPT |= opt);
	create_img(e);
}

void	change_global_quality(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	if (IS_GLOBQ)
	{
		OPT ^= LIGHT;
		OPT ^= SHINE;
		OPT ^= SHADOW;
		OPT ^= REFLX;
		OPT ^= OPT_I1;
		OPT ^= OPT_I2;
		OPT ^= GLOBQ;
	}
	else
	{
		OPT |= LIGHT;
		OPT |= SHINE;
		OPT |= SHADOW;
		OPT |= REFLX;
		OPT |= OPT_I1;
		OPT |= OPT_I2;
		OPT |= GLOBQ;
	}
	change_btn_light(e);
	create_img(e);
}
