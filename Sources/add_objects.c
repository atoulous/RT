/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:57:19 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/22 14:57:36 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_sphere(void *arg)
{
	t_env		*e;
	t_object	obj;
	t_list		*elem;

	e = (t_env *)arg;
	obj.name = ft_strdup("sphere");
	obj.type = 1;
	obj.pos = v3d(0, 0, 0);
	obj.r1 = 1.0;
	obj.color = 0x00FF0000;
	obj.mat.shine = 0.2;
	obj.mat.diffuse = 0.2;
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
	create_img(e);
}

void	add_cylinder(void *arg)
{
	t_env		*e;
	t_object	obj;
	t_list		*elem;

	e = (t_env *)arg;
	obj.name = ft_strdup("cylinder");
	obj.type = 5;
	obj.p1 = v3d(0, 1, 0);
	obj.p2 = v3d(0, -1, 0);
	obj.r1 = 1.0;
	obj.color = 0x0000FF00;
	obj.mat.shine = 0.2;
	obj.mat.diffuse = 0.2;
	e->calc_obj_param[5](&obj);
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
	create_img(e);
}

void	add_plane(void *arg)
{
	t_env		*e;
	t_object	obj;
	t_list		*elem;

	e = (t_env *)arg;
	obj.name = ft_strdup("plane");
	obj.type = 2;
	obj.pos = v3d(0, 0, 0);
	obj.dir = v3d(0, 1, 0);
	obj.color = 0x0000FF00;
	obj.mat.shine = 0.2;
	obj.mat.diffuse = 0.2;
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
	create_img(e);
}

void	add_cone(void *arg)
{
	t_env		*e;
	t_object	obj;
	t_list		*elem;

	e = (t_env *)arg;
	obj.name = ft_strdup("cone");
	obj.type = 4;
	obj.p1 = v3d(0, 0, 0);
	obj.p2 = v3d(0, 1, 0);
	obj.r1 = 1;
	obj.r2 = 0;
	obj.color = 0x0000FF00;
	obj.mat.shine = 0.2;
	obj.mat.diffuse = 0.2;
	e->calc_obj_param[4](&obj);
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
	create_img(e);
}
