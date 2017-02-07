/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_events2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:16:04 by atoulous          #+#    #+#             */
/*   Updated: 2017/02/07 14:09:39 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		change_motion_blur(t_env *e)
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
