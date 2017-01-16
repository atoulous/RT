/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_shadow_status.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:11:31 by atoulous          #+#    #+#             */
/*   Updated: 2017/01/16 15:11:33 by atoulous         ###   ########.fr       */
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
