/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_color_for_tex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:12:58 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/05 17:22:06 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		modify_color_for_tex(char *tex, t_v3d vec, t_light *datas)
{
	datas->shadow = 0.0;
	if (tex)
	{
		if (!ft_strcmp(tex, "wood"))
		{
			datas->rgb = wood(vec);
			return (1);
		}
		if (!ft_strcmp(tex, "marbre"))
		{
			datas->rgb = marbre(vec);
			return (1);
		}
		if (!ft_strcmp(tex, "random"))
		{
			datas->rgb = random_noise(vec, datas->rgb);
			return (1);
		}
	}
	return (0);
}
