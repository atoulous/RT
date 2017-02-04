/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_events2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:16:04 by atoulous          #+#    #+#             */
/*   Updated: 2017/02/04 22:19:23 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	back_plane(void	*arg)
{
	t_env	*e;

	e = (t_env *)arg;
	IS_BPLANE ? (OPT ^= BPLANE) : (OPT |= BPLANE);
	(IS_BPLANE && IS_OPT_D) ? ft_putendl("Swith OFF back_plane") : 0;
	(!IS_BPLANE && IS_OPT_D) ? ft_putendl("Switch ON back_plane") : 0;
	create_img(e);
}

void		active_cartoon(void *arg)
{
	t_env	*e;

	e = (t_env *)arg;
	(IS_CRTN) ? (OPT ^= CRTN) : (OPT |= CRTN);
	menu_object(e);
	create_img(e);
}

void		active_motion_blur(void *arg)
{
	t_env	*e;

	e = (t_env *)arg;
	if (IS_MOTION_BLUR)
	{
		OPT ^= MOTION_BLUR;
		ft_putendl("Motion blur is OFF");
	}
	else
	{
		OPT |= MOTION_BLUR;
		CAM_POS.x += 0.1;
		create_img(e);
		CAM_POS.x -= 0.1;
		ft_putendl("Motion blur is ON");
	}
	menu_object(e);
	create_img(e);
}

void		active_sepia(void *arg)
{
	t_env	*e;

	e = (t_env *)arg;
	(IS_GREY && !IS_SEPIA) ? (OPT ^= GREY) : 0;
	(IS_SEPIA) ? (OPT ^= SEPIA) : (OPT |= SEPIA);
	menu_object(e);
	create_img(e);
}

void		active_grey(void *arg)
{
	t_env	*e;

	e = (t_env *)arg;
	(IS_SEPIA && !IS_GREY) ? (OPT ^= SEPIA) : 0;
	(IS_GREY) ? (OPT ^= GREY) : (OPT |= GREY);
	menu_object(e);
	create_img(e);
}
