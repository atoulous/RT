/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:11:28 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/30 20:42:00 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	find_dist(t_object *obj, t_ray *ray, t_sol *sol)
{
	if (((T[1] < T[0]) && (T[1] > 0)) || ((T[1] > T[0]) && (T[0] < 0)))
		T[0] = T[1];
	if (T[0] > 0 && T[0] < ray->dist)
	{
		ray->obj = obj;
		ray->dist = T[0];
		ray->inter = add_v3d(ray->pos, smul_v3d(ray->dir, ray->dist));
		ray->norm = unit_v3d(sub_v3d(ray->inter, O_POS));
	}
}

void		sphere(t_env *e, t_object *obj, t_ray *ray, t_sol *sol)
{
	t_v3d	dp;

	dp = sub_v3d(ray->pos, O_POS);
	A = dot_v3d(ray->dir, ray->dir);
	B = 2.0 * dot_v3d(ray->dir, dp);
	C = dot_v3d(dp, dp) - pow(O_R1, 2.0);
	if (ft_solve_quadratic(A, B, C, T) >= 0)
		find_dist(obj, ray, sol);
}
