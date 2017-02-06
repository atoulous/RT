/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lampe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 19:49:17 by atoulous          #+#    #+#             */
/*   Updated: 2017/02/06 14:42:55 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	addsphere(void *arg)
{
	t_env		*e;
	t_object	obj;
	t_list		*elem;

	e = (t_env *)arg;
	obj.name = ft_strdup("new sphere");
	obj.type = 2;
	obj.pos = v3d(0, -4, 0);
	obj.r1 = 2;
	obj.color = 0xFF0000;
	obj.mat.shine = 100;
	obj.mat.diffuse = 0.2;
	obj.mat.specular = 1;
	obj.mat.ambient = 0.1;
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
	create_img(e);
	menu_object(e);
}

static void	addcylinder(void *arg)
{
	t_env		*e;
	t_object	obj;
	t_list		*elem;

	e = (t_env *)arg;
	obj.name = ft_strdup("new cylinder");
	obj.type = 3;
	obj.p1 = v3d(0, -5, 0);
	obj.p2 = v3d(0, 0, 0);
	obj.r1 = 0.5;
	obj.color = 0x00FF00;
	obj.mat.shine = 100;
	obj.mat.diffuse = 0.2;
	obj.mat.specular = 1;
	obj.mat.ambient = 0.1;
	e->calc_obj_param[obj.type](&obj);
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
	create_img(e);
	menu_object(e);
}

static void	addcone(void *arg)
{
	t_env		*e;
	t_object	obj;
	t_list		*elem;

	e = (t_env *)arg;
	obj.name = ft_strdup("new cone");
	obj.type = 4;
	obj.p1 = v3d(0, 0, 0);
	obj.p2 = v3d(0, 4, 0);
	obj.r1 = 3;
	obj.r2 = 1;
	obj.t1 = 1;
	obj.t2 = 1;
	obj.color = 0x0000FF;
	obj.mat.shine = 100;
	obj.mat.diffuse = 0.2;
	obj.mat.specular = 1;
	obj.mat.ambient = 0.1;
	e->calc_obj_param[obj.type](&obj);
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
	create_img(e);
	menu_object(e);
}

void	add_lampe(void *arg)
{
	t_env		*e;
	t_object	obj;

	e = (t_env *)arg;
	addsphere(e);
	addcylinder(e);
	addcone(e);
}
