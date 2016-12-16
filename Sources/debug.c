/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 18:49:11 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/16 17:29:47 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	print_mat(t_object *obj)
{
	printf("		Material:\n");
	printf("			Color diffuse: %lf\n", obj->mat.diffuse);
	printf("			Shiness: %lf\n", obj->mat.shine);
}

static void	print_obj(t_env *e)
{
	t_list		*elem;
	t_object	*obj;

	elem = e->scene->obj;
	printf("	Objects:\n");
	while (elem)
	{
		obj = (t_object *)(elem->content);
		printf("		name: \"%s\"\n", obj->name);
		printf("		type: \"%d\"\n", obj->type);
		printf("		");
		print_v3d(obj->pos, "origin");
		printf("\n");
		printf("		");
		print_v3d(obj->dir, "dir");
		printf("\n");
		printf("		");
		print_v3d(obj->p1, "p1");
		printf("\n");
		printf("		");
		print_v3d(obj->p2, "p2");
		printf("\n");
		printf("		r1: %lf\n", obj->r1);
		printf("		r2: %lf\n", obj->r2);
		printf("		angle: %lf\n", obj->angle);
		printf("		color: 0x%08.8X\n", obj->color);
		print_mat(obj);
		printf("		----------\n");
		elem = elem->next;
	}
}

static void	print_light(t_env *e)
{
	t_list		*elem;
	t_object	*obj;
	int			i;

	elem = e->scene->light;
	printf("	Lights:\n");
	if (!elem)
		printf("		No light specified\n");
	while (elem)
	{
		obj = (t_object *)(elem->content);
		printf("		name: \"%s\"\n", obj->name);
		printf("		type: \"%d\"\n", obj->type);
		printf("		param:\n");
		i = -1;
		while (++i < obj->nb_param)
			printf("			%lf\n", obj->param[i]);
		printf("		origin(%lf, %lf, %lf)\n", obj->pos.x,
												obj->pos.y, obj->pos.z);
		printf("		color: 0x%08.8X\n", obj->color);
		printf("		----------\n");
		elem = elem->next;
	}
}

static void	print_scene(t_env *e)
{
	printf("\n\n----   DEBUG    ----\n");
	printf("	Scene name: \"%s\"\n", e->scene->name);
	printf("	Camera:\n");
	printf("		origin(%lf, %lf, %lf)\n", e->scene->cam_pos.x,
			e->scene->cam_pos.y, e->scene->cam_pos.z);
	print_obj(e);
	print_light(e);
}

void		debug(t_env *e)
{
	if (D)
		print_scene(e);
}
