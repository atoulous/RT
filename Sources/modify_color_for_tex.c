/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_color_for_tex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:12:58 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/30 16:40:49 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb		modify_color_for_tex(char *tex, t_v3d vec)
{
	if (!ft_strcmp(tex, "wood"))
		return (wood(vec));
	if (!ft_strcmp(tex, "marbre"))
		return (marbre(vec));
	else 
		return(rgb_create(55, 55, 55));
}
