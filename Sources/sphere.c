/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:11:28 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/19 18:32:22 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	find_dist(t_object *obj, t_ray *ray, double *t)
{
	if ((t[1] < t[0] && t[1] > 0) || (t[1] > t[0] && t[0] < 0))
		t[0] = t[1];
	if (t[0] > 0 && t[0] < ray->dist)
	{
		ray->obj = obj;
		ray->dist = t[0];
		ray->norm = unit_v3d(sub_v3d(ray->inter, O_POS));
	}
}

void		sphere(t_object *obj, t_ray *ray)
{
	t_v3d	abc;
	t_v3d	dp;
	double	t[2];

	dp = sub_v3d(ray->pos, O_POS);
	abc.x = dot_v3d(ray->dir, ray->dir);
	abc.y = 2.0 * dot_v3d(dp, ray->dir);
	abc.z = dot_v3d(dp, dp) - O_R1 * O_R1;
	if (ft_solve_quadratic(abc.x, abc.y, abc.z, t) >= 0)
		find_dist(obj, ray, t);
}
