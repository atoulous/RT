/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:55:45 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/04 19:19:33 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	change_light_status(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	(IS_LIGHT) ? (OPT ^= LIGHT) : (OPT |= LIGHT);
	create_img(e);
}

void	change_brillance_status(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	(IS_SHINE) ? (OPT ^= SHINE) : (OPT |= SHINE);
	create_img(e);
}

void	change_shadow_status(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	(IS_SHADOW) ? (OPT ^= SHADOW) : (OPT |= SHADOW);
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
		OPT ^= GLOBQ;
	}
	else
	{
		OPT |= LIGHT;
		OPT |= SHINE;
		OPT |= SHADOW;
		OPT |= REFLX;
		OPT |= GLOBQ;
	}
	change_btn_light(e);
	create_img(e);
}
