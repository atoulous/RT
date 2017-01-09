#include "rt.h"

static void	put_objects_to_file(t_list *first, FILE *fd)
{
	t_list 		*list;
	t_object	*obj;
	char		**obj_alwd;
	int			t;

	list = first;
	obj_alwd = ft_strsplit(OBJ_ALLOWED, ' ');
	while (list)
	{
		obj = (t_object *)list->content;
		t = obj->type;
		fprintf(fd, "\tobject{\n\t\tname{oui}\n\t\ttype{%s}\n", obj_alwd[t]);
		if (t == 0 || t == 1 || t == 2)
			fprintf(fd, "\t\torigin{%f %f %f}\n", O_POS.x, O_POS.y, O_POS.z);
		if (t == 2)
			fprintf(fd, "\t\tdir{%f %f %f}\n", O_DIR.x, O_DIR.y, O_DIR.z);
		if (t == 4 || t == 5)
		{
			fprintf(fd, "\t\tp1{%f %f %f}\n", O_P1.x, O_P1.y, O_P1.z);
			fprintf(fd, "\t\tp2{%f %f %f}\n", O_P2.x, O_P2.y, O_P2.z);
		}
		if (t == 1 || t == 4 || t == 5)
			fprintf(fd, "\t\tr1{%f}\n", O_R1);
		if (t == 4)
			fprintf(fd, "\t\tr2{%f}\n", O_R2);
		fprintf(fd, "\t\tcolor{0x%08X}\n", obj->color);
		fprintf(fd, "\t}\n");
		list = list->next;
	}
	ft_free_tab(obj_alwd);
}

/*
** Take a scene struct and save it in a file
** It's pretty much like invert parsing of the scene
*/
void	save_scene(t_env *e)
{
	FILE	*fd;

	mkdir("Scenes", '+');
	fd = fopen("Scenes/test.rt", "w+");
	fprintf(fd, "scene {\n\tname{%s}", e->scene->name);
	fprintf(fd, "\n\tcamera{\n\t\torigin{ %f %f %f }\n\t\tdir{ %f %f %f }\n\t}", CAM_POS.x, CAM_POS.y, CAM_POS.z, CAM_DIR.x, CAM_DIR.y, CAM_DIR.z );
	fprintf(fd, "\n\trender{ %d %d }\n", IMG_WIDTH, IMG_HEIGHT);
	put_objects_to_file(e->scene->light, fd);
	put_objects_to_file(e->scene->obj, fd);
	fprintf(fd, "}");	
	fclose(fd);
}
