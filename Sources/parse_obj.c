/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 11:04:38 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/07 18:04:14 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Parse the matiere of the object
** If no matiere specified in file, set it to defined values
*/

static void		add_mat(t_object *obj, char *str)
{
	char	*tmp;

	fill_matiere_in_case(&obj->mat);
	if ((tmp = get_in_acc("mat", str)))
	{
		if (find_param("ambient", tmp))
			obj->mat.ambient = get_double("ambient", tmp);
		if (find_param("specular", tmp))
			obj->mat.specular = get_double("specular", tmp);
		if (find_param("diffuse", tmp))
			obj->mat.diffuse = get_double("diffuse", tmp);
		if (find_param("shine", tmp))
			obj->mat.shine = get_double("shine", tmp);
		if (find_param("density", tmp))
			obj->mat.density = get_double("density", tmp);
		free(tmp);
	}
	obj->pro = NULL;
	obj->asp = NULL;
	obj->pro = get_in_acc("tex", str);
	obj->asp = get_in_acc("asperite", str);
}

/*
** Parse the object type
** 0 -> light
** 1 -> plane
** 2 -> sphere
** 3 -> cylinder
** 4 -> cone
** 5 -> torus
*/

static int		get_obj_type(t_env *e, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = get_in_acc("type", str)))
		return (-1);
	while (e->obj_allowed[i] && ft_strcmp(tmp, e->obj_allowed[i]))
		i++;
	free(tmp);
	if (!e->obj_allowed[i])
		error_perso(e, "Object type is not supported");
	else
		return (i);
	return (-1);
}

/*
** Parse the object color and return it as an int
** Return -1 if no color found
*/

static int		get_obj_color(char *str)
{
	char	*tmp1;
	char	*tmp2;
	int		color;

	if (!(tmp1 = get_in_acc("color", str)))
		return (-1);
	tmp2 = ft_convert_base(tmp1, "0123456789ABCDEF", "0123456789");
	color = ft_atoi(tmp2);
	free(tmp1);
	free(tmp2);
	return (color);
}

/*
** Parse and build the object
** Quit program with adequate message if error encountered
*/

void			init_obj_param(t_env *e)
{
	int	i;

	i = -1;
	e->get_obj_param[0] = &get_light_param;
	e->get_obj_param[1] = &get_plane_param;
	e->get_obj_param[2] = &get_sphere_param;
	e->get_obj_param[3] = &get_cylinder_param;
	e->get_obj_param[4] = &get_cone_torus_param;
	e->get_obj_param[5] = &get_cone_torus_param;
}

void			build_object(t_env *e, char *str)
{
	t_object	obj;
	t_list		*elem;

	obj.t1 = 0;
	obj.t2 = 0;
	if (!(obj.name = get_in_acc("name", str)))
		error_perso(e, "No name found in object");
	if ((obj.type = get_obj_type(e, str)) == -1)
		error_perso(e, "No type found in object");
	e->get_obj_param[obj.type](str, &obj, (void *)e);
	e->calc_obj_param[obj.type] ? e->calc_obj_param[obj.type](&obj) : 0;
	if (!(obj.coef = get_double("coef", str)) || obj.coef < 0.0)
		obj.coef = 10;
	if (!(obj.density = get_double("density", str)) || obj.density < 0.0)
		obj.density = 10;
	if ((obj.color = get_obj_color(str)) == -1)
		error_perso(e, "No color found in object");
	add_mat(&obj, str);
	elem = ft_lstnew(&obj, sizeof(obj));
	if (obj.type == 0)
		ft_lstadd(&(e->scene->light), elem);
	else
		ft_lstadd(&(e->scene->obj), elem);
}
