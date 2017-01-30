/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:45:18 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/30 19:16:33 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_v3d	get_torus_normal(t_object *obj, t_v3d cam, t_v3d ray, double ret)
{
	t_v3d	pt;
	t_v3d	cent_pt;
	float	cent_pt_dot;
	t_v3d	dir;
	t_v3d	norm;

	pt = smul_v3d(ray, ret);
	pt = add_v3d(pt, cam);
	cent_pt = sub_v3d(pt, obj->p1);
	cent_pt_dot = dot_v3d(cent_pt, obj->p2);
	dir = smul_v3d(obj->p2, cent_pt_dot);
	dir = sub_v3d(cent_pt, dir);
	dir = unit_v3d(dir);
	norm = smul_v3d(dir, obj->r2);
	norm = sub_v3d(pt, add_v3d(obj->p1, norm));
	return (unit_v3d(norm));
}
