/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:50:53 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/09 13:55:43 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			calc_cylinder_param(t_object *obj)
{
	O_POS = O_P1;
	O_DIR = unit_v3d(sub_v3d(O_P2, O_POS));
}

void			update_cylinder_pos(t_object *obj)
{
	double	l;

	l = length_v3d(sub_v3d(O_P1, O_P2));
	O_P1 = O_POS;
	O_P2 = add_v3d(O_P1, smul_v3d(O_DIR, l));
	calc_cylinder_param(obj);
}
