/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:48:09 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/05 15:59:10 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_opt(t_env *e, int opt)
{
	OPT = opt;
	OPT |= LIGHT;
	OPT |= SHINE;
	OPT |= SHADOW;
	OPT |= REFLX;
	OPT |= OPT_I1;
	OPT |= PHONG;
	OPT |= GLOBQ;
}
