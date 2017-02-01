#include "rt.h"

void	object_menu_event(t_env *e, int y, t_object *obj)
{
	
}

void	top_menu_event(t_env *e, int x, int y)
{
	if (x >= 53 && x < WIN_WIDTH - 14 && y >= 10 && y <= 50)
	{
		if (x < 70)
			change_luminosite_mouse(e, y);
		else if (x > 82 && x < 116)
			x = x + 0; //move_on
		else if (x > 116 && x < 151)
			y = y + 0; //turn_on
		else if (x > 163 && x < 197)
			del_focus_object(e);
		else if (x > 197 && x < 232)
			undo_del_object(e);
		else if (x > WIN_WIDTH / 2 - 64 && x < WIN_WIDTH / 2 + 64)
			change_global_quality(e);
		else if ( x > WIN_WIDTH - 50)
			save_scene(e);
	}
}

void	bottom_menu_event(t_env *e, int x, int y)
{
	if (y > WIN_HEIGHT - 122 && y < WIN_HEIGHT - 10
			&& x > WIN_WIDTH / 2 - 268 && x < WIN_WIDTH / 2 + 268)
	{
		if (x < WIN_WIDTH / 2 - 160)
			add_sphere(e);
		else if (x < WIN_WIDTH / 2 - 50)
			add_plane(e);
		else if (x < WIN_WIDTH / 2 + 50)
			add_cylinder(e);
		else if (x < WIN_WIDTH / 2 + 160)
			add_cone(e);
		else
			add_torus(e);
	}
}

void	right_menu_event(t_env *e, int x, int y)
{
	if (x > WIN_WIDTH - 231 && x < WIN_WIDTH - 9 && y > 136
			&& y < 307)
		color_selector(e, x - WIN_WIDTH + 231, y - 136);
	if (x > WIN_WIDHT - 42 && x < WIN_WIDTH - 4 && y > 362
			&& e->scene->obj_focus)
		object_menu_event(e, y, (t_object *)(e->scene->obj_focus->content));
}
