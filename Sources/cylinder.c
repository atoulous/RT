/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:58:17 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/20 11:16:51 by jubarbie         ###   ########.fr       */
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

static void		find_dist(t_object *obj, t_ray *ray, double *sol)
{
	int		i;
	double	max;
	int		index;

	i = -1;
	max = ray->dist;
	while (++i < 4)
		if (sol[i] > 0 && sol[i] < max)
		{
			index = i;
			max = sol[i];
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

static void		find_solutions(t_object *obj, t_ray *ray, t_v3d abc)
{
	t_v3d	tmp;
	double	det;
	double	sol[4];

	if ((det = ft_solve_quadratic(abc.x, abc.y, abc.z, sol)) >= 0)
	{
		sol[2] = -1;
		while (++sol[2] < 2)
			if (sol[(int)sol[2]] >= 0)
			{
				tmp = add_v3d(ray->pos, smul_v3d(ray->dir, sol[(int)sol[2]]));
				if (!(dot_v3d(O_DIR, sub_v3d(tmp, O_POS)) > 0 &&
										dot_v3d(O_DIR, sub_v3d(tmp, O_P2)) < 0))
					sol[(int)sol[2]] = -1;
			}
		sol[2] = caps(ray, O_R1, O_DIR, O_P2);
		sol[3] = caps(ray, O_R1, smul_v3d(O_DIR, -1), O_POS);
		find_dist(obj, ray, sol);
	}
}

void			cylinder(t_object *obj, t_ray *ray)
{
	t_v3d	abc;
	t_v3d	dp;
	t_v3d	tmp;

	dp = sub_v3d(ray->pos, O_POS);
	tmp = sub_v3d(ray->dir, smul_v3d(O_DIR, dot_v3d(ray->dir, O_DIR)));
	abc.x = dot_v3d(tmp, tmp);
	abc.y = 2 * dot_v3d((sub_v3d(ray->dir, smul_v3d(O_DIR,
dot_v3d(ray->dir, O_DIR)))), sub_v3d(dp, smul_v3d(O_DIR, dot_v3d(dp, O_DIR))));
	tmp = sub_v3d(dp, smul_v3d(O_DIR, dot_v3d(dp, O_DIR)));
	abc.z = dot_v3d(tmp, tmp) - pow(O_R1, 2.0);
	find_solutions(obj, ray, abc);
}

void			calc_cylinder_param(t_object *obj)
{
	O_POS = O_P1;
	O_DIR = unit_v3d(sub_v3d(O_P2, O_POS));
}
