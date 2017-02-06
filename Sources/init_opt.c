/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:48:09 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/06 17:07:44 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_opt(t_env *e, int opt)
{
	MOVES = 0;
	ROT = 0;
	COMMAND = 0;
	OPT = opt;
	OPT |= LIGHT;
	OPT |= SHINE;
	OPT |= SHADOW;
	OPT |= REFLX;
	OPT |= OPT_I1;
	OPT |= PHONG;
	OPT |= GLOBQ;
}
