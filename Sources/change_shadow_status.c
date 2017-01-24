/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_shadow_status.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:11:31 by atoulous          #+#    #+#             */
/*   Updated: 2017/01/23 18:22:32 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		change_shadow_status(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	(OPT & (1 << 4)) ? (OPT ^= (1 << 4)) : (OPT |= (1 << 4));
	create_img(e);
}

void		change_brillance_status(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	(OPT & (1 << 3)) ? (OPT ^= (1 << 3)) : (OPT |= (1 << 3));
	create_img(e);
}

void		change_ambiance(t_env *e, int keycode)
{
	keycode == 71 && AMBIANCE + 0.05 <= 1 ? AMBIANCE += 0.05 : 0;
	keycode == 81 && AMBIANCE - 0.05 >= 0 ? AMBIANCE -= 0.05 : 0;
	create_img(e);
}

void		change_luminosite(t_env *e, int keycode)
{
	keycode == 67 && LUMI + 0.1 <= 1 ? LUMI += 0.1 : 0;
	keycode == 75 && LUMI - 0.1 >= 0 ? LUMI -= 0.1 : 0;
	create_img(e);
}
