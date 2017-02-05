/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:48:09 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/05 14:57:46 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_opt(t_env *e, char opt)
{
	OPT = opt;
	OPT |= PHONG;
	OPT |= OPT_I1;
	OPT |= OPT_I2;
	LUMI = 0.5;
	SPEED = 0.2;
	ALPHA_ROT = 20;
	MOVES = 0;
	ROT = 0;
	COMMAND = 0;
}
