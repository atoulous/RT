/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:48:09 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/04 20:56:41 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_opt(t_env *e, char opt)
{
	OPT = opt;
	OPT |= LIGHT;
	OPT |= SHADOW;
	OPT |= SHINE;
	OPT |= REFLX;
	OPT |= PHONG;
	OPT |= OPT_I1;
	OPT |= OPT_I2;
}
