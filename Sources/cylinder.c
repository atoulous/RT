/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:58:17 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/22 10:55:56 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		set_cylinder_norm(t_object *obj, t_ray *ray)
{
	double	l;

	ray->inter = add_v3d(ray->pos, smul_v3d(ray->dir, ray->dist));
	l = length_v3d(sub_v3d(ray->inter, O_POS));
	l = sqrt(pow(l, 2.0) - pow(O_R1, 2.0));
	ray->norm = unit_v3d(sub_v3d(ray->inter, add_v3d(O_POS,
													smul_v3d(O_DIR, l))));
}

static void		find_dist(t_object *obj, t_ray *ray, t_sol *sol)
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
		ray->obj = obj;
		if (index == 0 || index == 1)
			set_cylinder_norm(obj, ray);
		else if (index == 2)
			ray->norm = O_DIR;
		else if (index == 3)
			ray->norm = smul_v3d(O_DIR, -1);
	}
}

static void		find_solutions(t_object *obj, t_ray *ray, t_sol *sol)
{
	t_v3d	tmp;

	if ((DET = ft_solve_quadratic(A, B, C, T)) >= 0)
	{
		T[2] = -1;
		while (++T[2] < 2)
			if (T[(int)T[2]] >= 0)
			{
				tmp = add_v3d(ray->pos, smul_v3d(ray->dir, T[(int)T[2]]));
				if (!(dot_v3d(O_DIR, sub_v3d(tmp, O_POS)) > 0 &&
										dot_v3d(O_DIR, sub_v3d(tmp, O_P2)) < 0))
					T[(int)T[2]] = -1;
			}
		T[2] = caps(ray, O_R1, O_DIR, O_P2);
		T[3] = caps(ray, O_R1, smul_v3d(O_DIR, -1), O_POS);
		find_dist(obj, ray, sol);
	}
}

void			cylinder(t_object *obj, t_ray *ray, t_sol *sol)
{
	t_v3d	dp;
	t_v3d	tmp;

	dp = sub_v3d(ray->pos, O_POS);
	tmp = sub_v3d(ray->dir, smul_v3d(O_DIR, dot_v3d(ray->dir, O_DIR)));
	A = dot_v3d(tmp, tmp);
	B = 2 * dot_v3d((sub_v3d(ray->dir, smul_v3d(O_DIR,
dot_v3d(ray->dir, O_DIR)))), sub_v3d(dp, smul_v3d(O_DIR, dot_v3d(dp, O_DIR))));
	tmp = sub_v3d(dp, smul_v3d(O_DIR, dot_v3d(dp, O_DIR)));
	C = dot_v3d(tmp, tmp) - pow(O_R1, 2.0);
	find_solutions(obj, ray, sol);
}

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
