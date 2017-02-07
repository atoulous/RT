/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:12:48 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/07 18:05:17 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_light_param(char *str, t_object *obj, void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	obj->pos = get_v3d("origin", str);
	obj->dir = get_v3d("dir", str);
	if ((obj->angle = get_double("angle", str)))
		obj->angle *= (M_PI / 180);
}

void	get_plane_param(char *str, t_object *obj, void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	obj->pos = get_v3d("origin", str);
	obj->dir = get_v3d("dir", str);
}

void	get_sphere_param(char *str, t_object *obj, void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	obj->pos = get_v3d("origin", str);
	obj->r1 = get_double("r1", str);
}

void	get_cylinder_param(char *str, t_object *obj, void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	obj->p1 = get_v3d("p1", str);
	obj->p2 = get_v3d("p2", str);
	obj->r1 = get_double("r1", str);
	obj->t1 = get_double("t1", str);
	obj->t2 = get_double("t2", str);
}

void	get_cone_torus_param(char *str, t_object *obj, void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	obj->p1 = get_v3d("p1", str);
	obj->p2 = get_v3d("p2", str);
	obj->r1 = get_double("r1", str);
	obj->r2 = get_double("r2", str);
	obj->t1 = get_double("t1", str);
	obj->t2 = get_double("t2", str);
	if (obj->r1 > obj->r2 && obj->type == 5)
		error_perso(e, "Torus: r1 must be lower than r2");
}
