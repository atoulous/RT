/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:24:58 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/09 14:25:53 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		calc_cone_param(t_object *obj)
{
	O_POS = add_v3d(O_P1, smul_v3d(smul_v3d(sub_v3d(O_P2, O_P1), O_R1),
				1 / (O_R1 - O_R2)));
	O_DIR = unit_v3d(sub_v3d(O_P2, O_P1));
	O_ANG = atan((O_R1 - O_R2) / length_v3d(sub_v3d(O_P2, O_P1)));
}

void		update_cone_pos(t_object *obj)
{
	double	l;

	l = fabs(O_R2) / tan(O_ANG);
	O_P2 = add_v3d(O_POS, smul_v3d(O_DIR, l));
	l = fabs(O_R1) / tan(O_ANG);
	O_P1 = add_v3d(O_POS, smul_v3d(O_DIR, -l));
}
