/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 11:04:38 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/16 14:32:14 by mmoullec         ###   ########.fr       */
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

	obj->mat.shine = 0;
	obj->mat.diffuse = 0.5;
	if ((tmp = get_in_acc("mat", str)))
	{
		if (find_param("shine", tmp))
			obj->mat.shine = get_double("shine", tmp);
		if (find_param("diffuse", tmp))
			obj->mat.diffuse = get_double("diffuse", tmp);
		free(tmp);
	}
}

/*
 ** Parse the object type
 ** 0 -> light
 ** 1 -> sphere
 ** 2 -> plane
 ** 3 -> cube
 ** 4 -> cone
 ** 5 -> cylinder
 ** 6 -> torus
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

void			build_object(t_env *e, char *str)
{
	t_object	obj;
	t_list		*elem;

	if (!(obj.name = get_in_acc("name", str)))
		error_perso(e, "No name found in object");
	if ((obj.type = get_obj_type(e, str)) == -1)
		error_perso(e, "No type found in object");
	obj.pos = get_v3d("origin", str);
	obj.dir = get_v3d("dir", str);
	obj.p1 = get_v3d("p1", str);
	obj.p2 = get_v3d("p2", str);
	obj.r1 = get_double("r1", str);
	obj.r2 = get_double("r2", str);
	obj.angle = get_double("angle", str);
	if (obj.type == 6)
		torus_error(&obj, e);
	if (e->calc_obj_param[obj.type])
		e->calc_obj_param[obj.type](&obj);
	if ((obj.color = get_obj_color(str)) == -1)
		error_perso(e, "No color found in object");
	add_mat(&obj, str);
	elem = ft_lstnew(&obj, sizeof(obj));
	if (obj.type == 0)
		ft_lstadd(&(e->scene->light), elem);
	else
		ft_lstadd(&(e->scene->obj), elem);
	free(obj.name);
}
