/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:23:03 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/30 20:41:44 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

#ifndef TORUS_C
# define TORUS_C
# define CENT_CAM_DOT q.alpha.t[0]
# define CENT_CAM_DOT_SQUARED q.alpha.t[1]
# define CARRE_I_RAD q.alpha.t[2]
# define CARRE_O_RAD q.alpha.t[3]
# define CENT_CAM_AXIS_DOT q.alpha.a
# define RAY_AXIS_DOT q.alpha.b
# define RET q.beta.t
# define BA q.beta.a
# define BB q.beta.b
# define BC q.beta.c
# define BD q.beta.det
#endif

double			check_ret(double *ret)
{
	int			i;
	float		root;
	float		root_rend;

	i = -1;
	root_rend = 0;
	while (++i < 4)
	{
		root = ret[i];
		if (root > -1 && (root_rend == 0 || root < root_rend))
			root_rend = root;
	}
	return (root_rend);
}

static void		torus_sol(t_ray *ray, t_object *obj, t_sol *sol, double ret)
{
	obj->pos = obj->p1;
	T[0] = ret;
	if (T[0] < ray->dist)
	{
		ray->det = dot_v3d(O_P1, ray->dir);
		ray->obj = obj;
		ray->dist = ret;
		ray->inter = add_v3d(ray->pos, smul_v3d(ray->dir, ret));
		ray->norm = get_torus_normal(obj, ray->pos, ray->dir, ret);
	}
}

static void		torus_2(t_5pow *zz, t_sol_3 q)
{
	zz->q4 = 1;
	zz->q3 = 4 * CENT_CAM_DOT;
	zz->q2 = 2 * BD + zz->q3 * zz->q3 * 0.25 - 4 * CARRE_O_RAD * BA;
	zz->q1 = zz->q3 * BD - 4 * CARRE_O_RAD * BB;
	zz->q0 = BD * BD - 4 * CARRE_O_RAD * BC;
}

void		torus_for_the_norm(t_v3d *axis, t_v3d *cent_cam, t_ray *ray,\
		t_object *obj)
{
	*axis = unit_v3d(obj->p2);
	*cent_cam = sub_v3d(ray->pos, obj->p1);
}


void			torus(t_env *e, t_object *obj, t_ray *ray, t_sol *sol)
{
	t_sol_3		q;
	t_v3d		axis;
	t_v3d		cent_cam;
	t_5pow		zz;
	int			i;

	i = -1;
	torus_for_the_norm(&axis, &cent_cam, ray, obj);
	CENT_CAM_DOT = dot_v3d(ray->dir, cent_cam);
	q.alpha.det = CENT_CAM_DOT > 0.5 ? 0 : 1;
	CENT_CAM_DOT_SQUARED = dot_v3d(cent_cam, cent_cam);
	CARRE_I_RAD = carre(obj->r1);
	CARRE_O_RAD = carre(obj->r2);
	CENT_CAM_AXIS_DOT = dot_v3d(axis, cent_cam);
	RAY_AXIS_DOT = dot_v3d(axis, ray->dir);
	BA = 1 - carre(RAY_AXIS_DOT);
	BB = 2 * ((dot_v3d(cent_cam, ray->dir) -
				CENT_CAM_AXIS_DOT * RAY_AXIS_DOT));
	BC = CENT_CAM_DOT_SQUARED - carre(CENT_CAM_AXIS_DOT);
	BD = CENT_CAM_DOT_SQUARED + CARRE_O_RAD - CARRE_I_RAD;
	torus_2(&zz, q);
	while (++i < 4)
		RET[i] = -1.0;
	if (q.alpha.det && quartic_solver(RET, zz))
		return (torus_sol(ray, obj, sol, check_ret(RET)));
}
