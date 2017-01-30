#include "rt.h"

void	get_light_param(char *str, t_object *obj, void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	obj->pos = get_v3d("origin", str, e);
}

void	get_plane_param(char *str, t_object *obj, void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	obj->pos = get_v3d("origin", str, e);
	obj->dir = get_v3d("dir", str, e);
}

void	get_sphere_param(char *str, t_object *obj, void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	obj->pos = get_v3d("origin", str, e);
	obj->r1 = get_double("r1", str, e);
}

void	get_cone_param(char *str, t_object *obj, void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	obj->dir = get_v3d("dir", str, e);
	obj->p1 = get_v3d("p1", str, e);
	obj->p2 = get_v3d("p2", str, e);
	obj->r1 = get_double("r1", str, e);
	obj->r2 = get_double("r2", str, e);
}

void	get_cylinder_param(char *str, t_object *obj, void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	obj->p1 = get_v3d("p1", str, e);
	obj->p2 = get_v3d("p2", str, e);
	obj->r1 = get_double("r1", str, e);
}

void	get_torus_param(char *str, t_object *obj, void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	obj->p1 = get_v3d("p1", str, e);
	obj->p2 = get_v3d("p2", str, e);
	obj->r1 = get_double("r1", str, e);
	obj->r2 = get_double("r2", str, e);
	if (obj->r1 > obj->r2)
		error_perso(e, "Torus: r1 must be lower than r2");
}
