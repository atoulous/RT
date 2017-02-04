/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_shadow_status.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:11:31 by atoulous          #+#    #+#             */
/*   Updated: 2017/02/04 19:19:55 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		change_phong_status(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	(IS_PHONG) ? (OPT ^= PHONG) : (OPT |= PHONG);
	create_img(e);
}

void		change_intensite1(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	(IS_OPT_I1) ? (OPT ^= OPT_I1) : (OPT |= OPT_I1);
	menu_object(e);
	create_img(e);
}

void		change_intensite2(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	(IS_OPT_I2) ? (OPT ^= OPT_I2) : (OPT |= OPT_I2);
	menu_object(e);
	create_img(e);
}
