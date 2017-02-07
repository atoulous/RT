/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 19:55:56 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/07 16:04:34 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	plane(t_env *e, t_object *obj, t_ray *ray, t_sol *sol)
{
	t_v3d	tmp;

	DET = dot_v3d(O_DIR, ray->dir);
	if ((DET < 0.0000001 && IS_BPLANE) || (DET && !IS_BPLANE))
	{
		tmp = sub_v3d(O_POS, ray->pos);
		T[0] = dot_v3d(tmp, O_DIR) / DET;
		if (T[0] > 0.0000001 && T[0] < ray->dist)
		{
			ray->det = DET;
			ray->obj = obj;
			ray->dist = T[0];
			ray->norm = O_DIR;
			if (obj->asp && (!ft_strcmp(obj->asp, "water")))
				normal_water(obj->density, &ray->norm, \
					sub_v3d(ray->inter, obj->pos), O_DIR);
			if (obj->asp && (!ft_strcmp(obj->asp, "bump")))
				modif_normale(obj->density, 4, &ray->norm, \
					sub_v3d(ray->inter, obj->pos));
		}
	}
}
