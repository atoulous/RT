/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:48:09 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/05 13:01:06 by jubarbie         ###   ########.fr       */
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
	OPT |= OPT_I1;
	OPT |= OPT_I2;
	OPT |= GLOBQ;
	LUMI = 0.5;
	SPEED = 0.2;
	ALPHA_ROT = 20;
	MOVES = 0;
	ROT = 0;
	COMMAND = 0;
}
