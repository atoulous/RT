/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:55:45 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/07 14:28:05 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	change_motion_blur(t_env *e)
{
	if (IS_MOTION_BLUR)
	{
		OPT ^= MOTION_BLUR;
		ft_putendl("Motion blur is OFF");
	}
	else
	{
		(IS_STEREO) ? change_option(e, STEREO) : 0;
		OPT |= MOTION_BLUR;
		CAM_POS.x += 0.1;
		create_img(e);
		CAM_POS.x -= 0.1;
		ft_putendl("Motion blur is ON");
	}
	menu_object(e);
	create_img(e);
}

void	change_option(t_env *e, int opt)
{
	if (opt == GREY && IS_SEPIA)
		OPT ^= SEPIA;
	else if (opt == SEPIA && IS_GREY)
		OPT ^= GREY;
	(OPT & opt) ? (OPT ^= opt) : (OPT |= opt);
	menu_image_filter(e);
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
		OPT ^= PHONG;
		OPT ^= GLOBQ;
	}
	else
	{
		OPT |= LIGHT;
		OPT |= SHINE;
		OPT |= SHADOW;
		OPT |= REFLX;
		OPT |= OPT_I1;
		OPT |= PHONG;
		OPT |= GLOBQ;
	}
	change_btn_light(e);
	create_img(e);
}
