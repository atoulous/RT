/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 10:01:48 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/05 16:57:32 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		put_mat_to_file(t_object *obj, FILE *fd)
{
	fprintf(fd, "\t\tmat{\n\t\t\tdiffuse{%f}", obj->mat.diffuse);
	fprintf(fd, "\n\t\t\tshine{%f}\n\t\t}\n", obj->mat.shine);
}

static void		put_obj_param_to_file(t_object *obj, char **obj_a, FILE *fd)
{
	int	t;

	t = obj->type;
	fprintf(fd, "\t\tname{%s}\n\t\ttype{%s}\n", obj->name, obj_a[t]);
	if (t == 0 || t == 1 || t == 2)
		fprintf(fd, "\t\torigin{%f %f %f}\n", O_POS.x, O_POS.y, O_POS.z);
	if (t == 1)
		fprintf(fd, "\t\tdir{%f %f %f}\n", O_DIR.x, O_DIR.y, O_DIR.z);
	if (t == 3 || t == 4 || t == 5)
	{
		fprintf(fd, "\t\tp1{%f %f %f}\n", O_P1.x, O_P1.y, O_P1.z);
		fprintf(fd, "\t\tp2{%f %f %f}\n", O_P2.x, O_P2.y, O_P2.z);
	}
	(t > 1) ? fprintf(fd, "\t\tr1{%f}\n", O_R1) : 0;
	(t == 4 || t == 5) ? fprintf(fd, "\t\tr2{%f}\n", O_R2) : 0;
	fprintf(fd, "\t\tcolor{0x%08X}\n", obj->color);
	put_mat_to_file(obj, fd);
}

static void		put_objects_to_file(t_env *e, t_list *first, FILE *fd)
{
	t_list		*list;
	t_object	*obj;

	list = first;
	while (list)
	{
		obj = (t_object *)list->content;
		fprintf(fd, "\tobject{\n");
		put_obj_param_to_file(obj, e->obj_allowed, fd);
		fprintf(fd, "\t}\n");
		list = list->next;
	}
}

/*
** Take a scene struct and save it in a file
** It's pretty much like invert parsing of the scene
*/

void		save_scene(t_env *e)
{
	FILE	*fd;
	char	*file_name;
	char	*path;

	mkdir("Save", 0777);
	ft_putstr("Nom de votre fichier: ");
	get_next_line(0, &file_name);
	path = ft_strjoin("Save/", file_name);
	if ((fd = fopen(path, "w+")) > 0)
	{
		fprintf(fd, "scene {\n\tname{%s}", e->scene->name);
		fprintf(fd, "\n\tcamera{\n\t\torigin{ %f %f %f }\n\t\tdir{ %f %f %f }\
	\n\t}", CAM_POS.x, CAM_POS.y, CAM_POS.z, CAM_DIR.x, CAM_DIR.y, CAM_DIR.z);
		fprintf(fd, "\n\trender{ %d %d }\n", IMG_WIDTH, IMG_HEIGHT);
		put_objects_to_file(e, e->scene->light, fd);
		put_objects_to_file(e, e->scene->obj, fd);
		fprintf(fd, "}");
		ft_putstr("\033[32mScene saved into ");
		ft_putstr(path);
		ft_putstr("\033[0m\n");
		fclose(fd);
	}
	else
		error_perso(e, "Impossible to open file");
	free(file_name);
	free(path);
}
