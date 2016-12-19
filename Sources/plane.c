/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 19:55:56 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/19 17:05:35 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	plane(t_object *obj, t_ray *ray)
{
	t_v3d	tmp;
	double	t;
	double	det;

	det = dot_v3d(O_DIR, ray->dir);
	if (det < 0.0000001)
	{
		tmp = sub_v3d(O_POS, ray->pos);
		t = dot_v3d(tmp, O_DIR) / det;
		if (t > 0.0000001 && t < ray->dist)
		{
			ray->det = det;
			ray->obj = obj;
			ray->dist = t;
			ray->norm = O_DIR;
		}
	}
}
