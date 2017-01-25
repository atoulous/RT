/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 18:49:11 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/25 18:12:43 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	print_vector(t_v3d v, char *name)
{
	printf("		");
	print_v3d(v, name);
	printf("\n");
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
		print_vector(obj->pos, "origin");
		print_vector(obj->dir, "dir");
		print_vector(obj->p1, "p1");
		print_vector(obj->p2, "p2");
		printf("		r1: %lf\n		r2: %lf\n", O_R1, O_R2);
		printf("		angle: %lf\n", O_ANG);
		printf("		color: 0x%08.8X\n", obj->color);
		printf("		Material:\n");
		printf("		Color ambient: %lf\n", obj->mat.ambient);
		printf("		Color diffuse: %lf\n", obj->mat.diffuse);
		printf("		Color specular: %lf\n", obj->mat.specular);
		printf("		Shiness: %lf\n", obj->mat.shine);
		printf("		----------\n");
		elem = elem->next;
	}
}

static void	print_light(t_env *e)
{
	t_list		*elem;
	t_object	*obj;

	elem = e->scene->light;
	printf("	Lights:\n");
	if (!elem)
		printf("		No light specified\n");
	while (elem)
	{
		obj = (t_object *)(elem->content);
		printf("		name: \"%s\"\n", obj->name);
		printf("		type: \"%d\"\n", obj->type);
		print_vector(O_POS, "origin");
		printf("		color: 0x%08.8X\n", obj->color);
		printf("		----------\n");
		elem = elem->next;
	}
}

static void	print_scene(t_env *e)
{
	printf("\n----   DEBUG    ----\n\n");
	printf("	Image resolution: %d x %d px\n\n", IMG_WIDTH, IMG_HEIGHT);
	printf("	Scene name: \"%s\"\n", e->scene->name);
	printf("	Camera:\n");
	print_vector(CAM_POS, "origin");
	print_vector(CAM_DIR, "dir");
	print_obj(e);
	print_light(e);
}

void		debug(t_env *e)
{
	if (OPT_D)
		print_scene(e);
}
