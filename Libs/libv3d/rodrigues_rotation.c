/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rodrigues_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:25:37 by atoulous          #+#    #+#             */
/*   Updated: 2017/01/24 13:47:56 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libv3d.h"

/*
**rotation autour d'un axe, angle au choix
*/

t_v3d	rodrigues_rotation(t_v3d vec_dir, t_v3d axis, double alpha)
{
	alpha = alpha * (M_PI / 180);
	return (add_v3d(add_v3d(smul_v3d(vec_dir, cos(alpha)),
		smul_v3d(smul_v3d(axis, dot_v3d(vec_dir, axis)), (1 - cos(alpha)))),
		smul_v3d(cross_v3d(axis, vec_dir), sin(alpha))));
}
