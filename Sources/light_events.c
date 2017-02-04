/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_shadow_status.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:11:31 by atoulous          #+#    #+#             */
/*   Updated: 2017/02/04 15:07:54 by atoulous         ###   ########.fr       */
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

void		change_phong_status(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	(OPT & (1 << 5)) ? (OPT ^= (1 << 5)) : (OPT |= (1 << 5));
	create_img(e);
}

void		change_intensite1(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	(OPT & (1 << 6)) ? (OPT ^= (1 << 6)) : (OPT |= (1 << 6));
	menu_object(e);
	create_img(e);
}

void		change_intensite2(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	(OPT & (1 << 7)) ? (OPT ^= (1 << 7)) : (OPT |= (1 << 7));
	menu_object(e);
	create_img(e);
}
