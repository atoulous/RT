/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lampe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 19:49:17 by atoulous          #+#    #+#             */
/*   Updated: 2017/02/06 23:20:26 by atoulous         ###   ########.fr       */
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
	obj.pro = ft_strdup("wood");
	obj.coef = 3;
	obj.asp = NULL;
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
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
	obj.p2 = v3d(0, 1, 0);
	obj.r1 = 0.2;
	obj.color = 0x00FF00;
	obj.mat.shine = 100;
	obj.mat.diffuse = 0.2;
	obj.mat.specular = 1;
	obj.mat.ambient = 0.1;
	obj.pro = ft_strdup("marbre");
	obj.asp = NULL;
	obj.coef = 15;
	e->calc_obj_param[obj.type](&obj);
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
}

static void	addcylinder2(void *arg)
{
	t_env		*e;
	t_object	obj;
	t_list		*elem;

	e = (t_env *)arg;
	obj.name = ft_strdup("new cylinder");
	obj.type = 3;
	obj.p1 = v3d(0, -4, 0);
	obj.p2 = v3d(0, -6, 0);
	obj.r1 = 1;
	obj.color = 0x00FF00;
	obj.mat.shine = 100;
	obj.mat.diffuse = 0.2;
	obj.mat.specular = 1;
	obj.mat.ambient = 0.1;
	obj.pro = ft_strdup("wood");
	obj.asp = NULL;
	obj.coef = 3;
	e->calc_obj_param[obj.type](&obj);
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
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
	obj.r2 = 0;
	obj.t1 = 1;
	obj.t2 = 1;
	obj.color = 0xFF0000;
	obj.mat.shine = 100;
	obj.mat.diffuse = 0.2;
	obj.mat.specular = 1;
	obj.mat.ambient = 0.1;
	obj.pro = ft_strdup("random");
	obj.asp = NULL;
	obj.coef = 5;
	e->calc_obj_param[obj.type](&obj);
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
}

void		add_lampe(void *arg)
{
	t_env		*e;
	t_object	light;
	t_list		*elem;

	e = (t_env *)arg;
	addsphere(e);
	addcone(e);
	addcylinder(e);
	addcylinder2(e);
	light.name = ft_strdup("new light");
	light.type = 0;
	light.pos = v3d(0, 4, 0);
	light.dir = v3d(0, -1, 0);
	light.angle = 0.7;
	elem = ft_lstnew(&light, sizeof(light));
	ft_lstadd(&(e->scene->light), elem);
	menu_object(e);
	create_img(e);
}
