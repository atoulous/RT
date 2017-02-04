/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:51:36 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/04 14:54:53 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		change_luminosite(t_env *e, int keycode)
{
	keycode == 67 && LUMI + 0.05 <= 1 ? LUMI += 0.05 : 0;
	keycode == 75 && LUMI - 0.05 >= -0.5 ? LUMI -= 0.05 : 0;
	create_img(e);
}

void		change_luminosite_mouse(t_env *e, int y)
{
	if (y < 25)
		LUMI + 0.05 <= 1 ? LUMI += 0.05 : 0;
	else
		LUMI - 0.05 >= -0.5 ? LUMI -= 0.05 : 0;
	create_img(e);
}
