/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:57:19 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/06 14:42:57 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_sphere(void *arg)
{
	t_env		*e;
	t_object	obj;
	t_list		*elem;

	e = (t_env *)arg;
	obj.name = ft_strdup("new sphere");
	obj.type = 2;
	obj.pos = add_v3d(CAM_POS, smul_v3d(CAM_DIR, 10.0));
	obj.r1 = 1.0;
	obj.color = 0x00FF0000;
	obj.mat.shine = 100;
	obj.mat.diffuse = 0.2;
	obj.mat.specular = 1;
	obj.mat.ambient = 0.1;
	obj.pro = NULL;
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
	create_img(e);
	menu_object(e);
}

void	add_cylinder(void *arg)
{
	t_env		*e;
	t_object	obj;
	t_list		*elem;

	e = (t_env *)arg;
	obj.name = ft_strdup("new cylinder");
	obj.type = 3;
	obj.p1 = add_v3d(add_v3d(CAM_POS, smul_v3d(CAM_DIR, 10)), \
			smul_v3d(CAM_UP, 1));
	obj.p2 = add_v3d(add_v3d(CAM_POS, smul_v3d(CAM_DIR, 10)), \
			smul_v3d(CAM_UP, -1));
	obj.r1 = 1.0;
	obj.color = 0x0000FF00;
	obj.mat.shine = 100;
	obj.mat.diffuse = 0.2;
	obj.mat.specular = 1;
	obj.mat.ambient = 0.1;
	obj.pro = NULL;
	e->calc_obj_param[obj.type](&obj);
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
	create_img(e);
	menu_object(e);
}

void	add_plane(void *arg)
{
	t_env		*e;
	t_object	obj;
	t_list		*elem;

	e = (t_env *)arg;
	obj.name = ft_strdup("new plane");
	obj.type = 1;
	obj.pos = add_v3d(CAM_POS, smul_v3d(CAM_UP, -2.0));
	obj.dir = CAM_UP;
	obj.color = 0x0000FF00;
	obj.mat.shine = 100;
	obj.mat.diffuse = 0.2;
	obj.mat.specular = 1;
	obj.mat.ambient = 0.1;
	obj.pro = NULL;
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
	create_img(e);
	menu_object(e);
}

void	add_cone(void *arg)
{
	t_env		*e;
	t_object	obj;
	t_list		*elem;

	e = (t_env *)arg;
	obj.name = ft_strdup("new cone");
	obj.type = 4;
	obj.p1 = add_v3d(CAM_POS, smul_v3d(CAM_DIR, 10.0));
	obj.p2 = add_v3d(obj.p1, smul_v3d(CAM_UP, 1.0));
	obj.r1 = 1;
	obj.r2 = 0;
	obj.color = 0x0000FF00;
	obj.mat.shine = 100;
	obj.mat.diffuse = 0.2;
	obj.mat.specular = 1;
	obj.mat.ambient = 0.1;
	obj.pro = NULL;
	e->calc_obj_param[obj.type](&obj);
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
	create_img(e);
	menu_object(e);
}

void	add_torus(void *arg)
{
	t_env		*e;
	t_object	obj;
	t_list		*elem;

	e = (t_env *)arg;
	obj.name = ft_strdup("new torus");
	obj.type = 5;
	obj.p1 = v3d(0, 0, 0);
	obj.p2 = v3d(0, 0, 1);
	obj.r1 = 1;
	obj.r2 = 2;
	obj.color = 0x0000FF00;
	obj.mat.shine = 100;
	obj.mat.diffuse = 0.2;
	obj.mat.specular = 1;
	obj.mat.ambient = 0.1;
	obj.pro = NULL;
	elem = ft_lstnew(&obj, sizeof(obj));
	ft_lstadd(&(e->scene->obj), elem);
	e->scene->obj_focus = elem;
	create_img(e);
	menu_object(e);
}
