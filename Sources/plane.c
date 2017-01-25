/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 19:55:56 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/25 23:31:53 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	plane(t_object *obj, t_ray *ray, t_sol *sol)
{
	t_v3d	tmp;

	DET = dot_v3d(O_DIR, ray->dir);
	if (DET < 0.0000001)
	{
		tmp = sub_v3d(O_POS, ray->pos);
		T[0] = dot_v3d(tmp, O_DIR) / DET;
		if (T[0] > 0.0000001 && T[0] < ray->dist)
		{
			ray->det = DET;
			ray->obj = obj;
			ray->dist = T[0];
			ray->norm = smul_v3d(O_DIR, -1);
			//modif_normale(0.1, &ray->norm, smul_v3d(ray->dir, T[0]));
		}
	}
}
