/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_color_for_tex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:12:58 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/30 17:20:45 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		modify_color_for_tex(char *tex, t_v3d vec, t_rgb *rgb)
{
	if (!ft_strcmp(tex, "wood"))
	{
		*rgb = wood(vec);
		return (1);
	}
	if (!ft_strcmp(tex, "marbre"))
	{
		*rgb = marbre(vec);
		return (1);
	}
	return (0);
}
