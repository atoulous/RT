/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:23:03 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/09 20:08:41 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double			check_ret(double *ret)
{
	int i = -1;
	int j = 0;
	float root;
	float root_rend = 0;
	while (++i < 4)
	{
		root = ret[i];
		if (root > -1 && (root_rend == 0 || root < root_rend))
			root_rend = root;
	}
	return (root_rend);
}

t_v3d get_torus_normal(t_object *obj, t_v3d cam, t_v3d ray, double ret)
{
	t_v3d pt;
	pt = smul_v3d(ray, ret);
	pt = add_v3d(pt, cam);

	t_v3d centerToPoint = sub_v3d(pt, obj->p1);
	float centerToPointDotAxis = dot_v3d(centerToPoint, obj->p2);
	t_v3d direction = smul_v3d(obj->p2, centerToPointDotAxis);
	direction = sub_v3d(centerToPoint, direction);
	direction = unit_v3d(direction);
	t_v3d normal = smul_v3d(direction, obj->r2);
	normal = sub_v3d(pt, add_v3d(obj->p1, normal));
	normal = unit_v3d(normal);

	return (normal);
}

static void	torus_sol(t_ray *ray, t_object *obj, t_sol *sol, double ret)
{
	ray->obj = obj;
	ray->dist = ret;
	ray->inter = add_v3d(ray->pos, smul_v3d(ray->dir, ret));
	ray->norm = get_torus_normal(obj, ray->pos, ray->dir, ret);
}

void      torus(t_object *obj, t_ray *ray, t_sol *sol)
{
	t_v3d center = obj->p1;
	t_v3d axis = unit_v3d(obj->p2);
	t_v3d cam_origin = ray->pos;

	t_v3d centerToRayOrigin = sub_v3d(cam_origin, center);
	const double centerToRayOriginDotDirection = dot_v3d(ray->dir, centerToRayOrigin);
	double centerToRayOriginDotDirectionSquared = dot_v3d(centerToRayOrigin, centerToRayOrigin);

	double innerRadiusSquared = carre(obj->r1);
	double outerRadiusSquared = carre(obj->r2);

	double	axisDotCenterToRayOrigin = dot_v3d(axis, centerToRayOrigin);
	double	axisDotRayDirection = dot_v3d(axis, ray->dir);
	double	a = 1 - axisDotRayDirection * axisDotRayDirection;
	double	b = (dot_v3d(centerToRayOrigin, ray->dir) -
			axisDotCenterToRayOrigin * axisDotRayDirection);
	b *= 2;
	double c = centerToRayOriginDotDirectionSquared -
		axisDotCenterToRayOrigin * axisDotCenterToRayOrigin;
	double	d = centerToRayOriginDotDirectionSquared +
		outerRadiusSquared - innerRadiusSquared;

	t_5pow	zz;
	zz.q4 = 1;
	zz.q3 = 4 * centerToRayOriginDotDirection;
	zz.q2 = 2 * d + zz.q3 * zz.q3 * 0.25 - 4 * outerRadiusSquared * a;
	zz.q1 = zz.q3 * d - 4 * outerRadiusSquared * b;
	zz.q0 = d * d - 4 * outerRadiusSquared * c;

	double ret[4] = {-1.0, -1.0, -1.0, -1.0};
	if (quartic_solver(ret, zz))
		return (torus_sol(ray, obj, sol, check_ret(ret)));

	
//	print_v3d(ray->pos, "pos");
//	print_v3d(ray->dir, "dir");
//	print_v3d(ray->inter,  "inter");
//	print_v3d(ray->norm, "norm");
}
