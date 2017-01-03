/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:58:17 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/22 10:58:44 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	set_cone_norm(t_object *obj, t_ray *ray)
{
	double	l;

	ray->inter = add_v3d(ray->pos, smul_v3d(ray->dir, ray->dist));
	l = length_v3d(sub_v3d(ray->inter, O_POS));
	l /= cos(O_ANG);
	if (dot_v3d(O_DIR, sub_v3d(ray->inter, O_POS)) < 0)
		l *= -1;
	ray->norm = unit_v3d(sub_v3d(ray->inter,
										add_v3d(O_POS, smul_v3d(O_DIR, l))));
}

static int	find_dist(t_object *obj, t_ray *ray, t_sol *sol)
{
	int		i;
	double	max;
	int		index;

	i = -1;
	max = ray->dist;
	while (++i < 4)
		if (T[i] > 0 && T[i] < max)
		{
			index = i;
			max = T[i];
		}
	if (max < ray->dist)
	{
		ray->dist = max;
		if (index == 0 || index == 1)
			set_cone_norm(obj, ray);
		else if (index == 2)
			ray->norm = O_DIR;
		else if (index == 3)
			ray->norm = smul_v3d(O_DIR, -1);
		return (1);
	}
	return (0);
}

static int	find_solutions(t_object *obj, t_ray *ray, t_sol *sol)
{
	t_v3d	tmp;

	if ((DET = ft_solve_quadratic(A, B, C, T)) >= 0)
	{
		T[2] = -1;
		while (++T[2] < 2)
			if (T[(int)T[2]] >= 0)
			{
				tmp = add_v3d(ray->pos, smul_v3d(ray->dir, T[(int)T[2]]));
				if (!(dot_v3d(O_DIR, sub_v3d(tmp, O_P1)) > 0 &&
							dot_v3d(O_DIR, sub_v3d(tmp, O_P2)) < 0))
					T[(int)T[2]] = -1;
			}
		T[2] = caps(ray, O_R2, O_DIR, O_P2);
		T[3] = caps(ray, O_R1, smul_v3d(O_DIR, -1), O_P1);
		if (find_dist(obj, ray, sol))
			return (1);
	}
	return (0);
}

void		cone(t_object *obj, t_ray *ray, t_sol *sol)
{
	t_v3d	dp;
	t_v3d	v_tmp;
	double	sina2;
	double	cosa2;

	dp = sub_v3d(ray->pos, O_POS);
	sina2 = pow(sin(O_ANG), 2.0);
	cosa2 = pow(cos(O_ANG), 2.0);
	v_tmp = sub_v3d(ray->dir, smul_v3d(O_DIR, dot_v3d(ray->dir, O_DIR)));
	A = cosa2 * dot_v3d(v_tmp, v_tmp) - sina2 * dot_v3d(O_DIR, ray->dir) *
		dot_v3d(O_DIR, ray->dir);
	B = (2 * cosa2 * dot_v3d(sub_v3d(ray->dir,
			smul_v3d(O_DIR, dot_v3d(O_DIR, ray->dir))), sub_v3d(dp,
			smul_v3d(O_DIR, dot_v3d(dp, O_DIR))))) - 2 * sina2 *
		dot_v3d(O_DIR, ray->dir) * dot_v3d(dp, O_DIR);
	v_tmp = sub_v3d(dp, smul_v3d(O_DIR, dot_v3d(dp, O_DIR)));
	C = cosa2 * dot_v3d(v_tmp, v_tmp) - sina2 *
			dot_v3d(dp, O_DIR) * dot_v3d(dp, O_DIR);
	if (find_solutions(obj, ray, sol))
		ray->obj = obj;
}

void		calc_cone_param(t_object *obj)
{
	O_POS = add_v3d(O_P1, smul_v3d(smul_v3d(sub_v3d(O_P2, O_P1), O_R1),
														1 / (O_R1 - O_R2)));
	O_DIR = unit_v3d(sub_v3d(O_P2, O_P1));
	O_ANG = atan((O_R1 - O_R2) / length_v3d(sub_v3d(O_P2, O_P1)));
}
