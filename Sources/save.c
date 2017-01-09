#include "rt.h"

/*
** Take a scene struct and save it in a file
** It's pretty much like invert parsing of the scene
*/
void	save_scene(t_env *e)
{
	FILE	*fd;

	fd = fopen("/tmp/test.txt", "w+");
	fprintf(fd, "scene {name{%s}", e->scene->name);
	fprintf(fd, "camera{origin{ %lf %lf %lf }dir{ %lf %lf %lf }}", CAM_POS.x, CAM_POS.y, CAM_POS.z, CAM_DIR.x, CAM_DIR.y, CAM_DIR.z );
	fprintf(fd, "render{ %d %d }", IMG_WIDTH, IMG_HEIGHT);
	//fputs("This is testing for fputs...\n", fd);
	fclose(fd);
}
