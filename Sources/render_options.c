/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 09:48:00 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/01 18:36:54 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	change_global_quality(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	if (OPT_GQ)
	{
		OPT ^= (1 << 1);
		OPT ^= (1 << 3);
		OPT ^= (1 << 4);
		OPT ^= (1 << 5);
	}
	else
	{
		OPT |= (1 << 1);
		OPT |= (1 << 3);
		OPT |= (1 << 4);
		OPT |= (1 << 5);
	}
	change_btn_light(e);
	create_img(e);
}
