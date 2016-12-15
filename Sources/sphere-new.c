/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:11:28 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/15 14:53:43 by jubarbie         ###   ########.fr       */
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
	double	t[2];

	abc.x = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y +
			ray->dir.z * ray->dir.z;
	abc.y = 2.0 * (ray->dir.x * (ray->pos.x - O_POS.x) +
ray->dir.y * (ray->pos.y - O_POS.y) + ray->dir.z * (ray->pos.z - O_POS.z));
	abc.z = (pow(ray->pos.x - O_POS.x, 2.0) + pow(ray->pos.y - O_POS.y, 2.0) +
			pow(ray->pos.z - O_POS.z, 2.0)) - O_R1 * O_R1;
	if ((O_R1 = ft_solve_quadratic(abc.x, abc.y, abc.z, t)) >= 0.01)
		find_dist(obj, ray, t);
}
