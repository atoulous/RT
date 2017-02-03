/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgameiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:03:41 by dgameiro          #+#    #+#             */
/*   Updated: 2017/02/03 13:30:38 by dgameiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_reflect(t_param *param)
{
	F_COLOR.r = 0;
	F_COLOR.g = 0;
	F_COLOR.b = 0;
	REF_COEFF = 1;
}

void		add_reflected_color(t_param *param)
{
	F_COLOR.r += (COLOR & 0x00FF) * REF_COEFF;
	F_COLOR.g += ((COLOR & 0x00FF00) >> 8) * REF_COEFF; 
	F_COLOR.b += ((COLOR & 0x00FF0000) >> 16) * REF_COEFF;
}


