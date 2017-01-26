/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 22:58:34 by atoulous          #+#    #+#             */
/*   Updated: 2017/01/26 13:39:21 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		change_speed_rotation(t_env *e, int keycode)
{
	keycode == 27 && ALPHA_ROT > 10 ? ALPHA_ROT -= 10 : 0;
	keycode == 24 && ALPHA_ROT < 180 ? ALPHA_ROT += 10 : 0;
	ft_putstr("Alpha rotation changed to ");
	ft_putnbr(ALPHA_ROT);
	ft_putstr("\n");
}

void		change_ambiance(t_env *e, int keycode)
{
	keycode == 71 && AMBIANCE + 0.05 <= 1 ? AMBIANCE += 0.05 : 0;
	keycode == 81 && AMBIANCE - 0.05 >= 0 ? AMBIANCE -= 0.05 : 0;
	ft_putstr("Ambiance indice changed to ");
	ft_putnbr(AMBIANCE);
	printf("%f\n", AMBIANCE);
	create_img(e);
}

void		change_luminosite(t_env *e, int keycode)
{
	keycode == 67 && LUMI + 0.1 <= 1 ? LUMI += 0.1 : 0;
	keycode == 75 && LUMI - 0.1 >= 0 ? LUMI -= 0.1 : 0;
	ft_putstr("Luminosite indice changed to ");
	ft_putnbr(LUMI);
	printf("%f\n", LUMI);
	create_img(e);
}

void		reset_cam(t_env *e)
{
	CAM_POS = e->parse_cam_pos;
	CAM_DIR = e->parse_cam_dir;
	ft_putendl("Camera reinitialized");
	create_img(e);
}
