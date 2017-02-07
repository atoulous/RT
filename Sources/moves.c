/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:50:44 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/07 15:53:47 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	moves2(t_v3d **pos, t_v3d **dir, t_list *list, t_object **obj)
{
	(*obj) = (t_object *)(list->content);
	(*pos) = &(*obj)->pos;
	if ((*obj)->type == 5)
		(*dir) = &(*obj)->p2;
	else
		(*dir) = &(*obj)->dir;
}

/*
** useless now
*/

void	matrice(t_env *e)
{
	t_v4d	pos;
	t_v4d	trans;

	pos = v4d(CAM_DIR.x, CAM_DIR.y, CAM_DIR.z, 0);
	trans = v4d(1, 0, 0, 1);
	pos = translation_pos(pos, trans);
	CAM_DIR = v3d(pos.x, pos.y, pos.z);
}

void	rotations(t_env *e, t_v3d *dir)
{
	double	alpha;

	if (e->scene->obj_focus)
		alpha = -ALPHA_ROT;
	else
		alpha = ALPHA_ROT;
	ROT & M_LEFT ? *dir = rodrigues_rot(*dir, v3d(0, 1, 0), -ALPHA_ROT) : *dir;
	ROT & M_RIGHT ? *dir = rodrigues_rot(*dir, v3d(0, 1, 0), ALPHA_ROT) : *dir;
	ROT & M_UP ? *dir = rodrigues_rot(*dir, v3d(1, 0, 0), -ALPHA_ROT) : *dir;
	ROT & M_DOWN ? *dir = rodrigues_rot(*dir, v3d(1, 0, 0), ALPHA_ROT) : *dir;
}

int		moves(t_env *e)
{
	t_v3d		*pos;
	t_v3d		*dir;
	t_list		*list;
	t_object	*obj;

	if (!(list = e->scene->obj_focus))
	{
		pos = &CAM_POS;
		dir = &CAM_DIR;
	}
	else
		moves2(&pos, &dir, list, &obj);
	MOVES & M_UP ? *pos = add_v3d(*pos, smul_v3d(CAM_UP, SPEED)) : *pos;
	MOVES & M_DOWN ? *pos = sub_v3d(*pos, smul_v3d(CAM_UP, SPEED)) : *pos;
	MOVES & M_RIGHT ? *pos = add_v3d(*pos, smul_v3d(CAM_RIGHT, SPEED)) : *pos;
	MOVES & M_LEFT ? *pos = sub_v3d(*pos, smul_v3d(CAM_RIGHT, SPEED)) : *pos;
	MOVES & M_FORWARD ? *pos = add_v3d(*pos, smul_v3d(CAM_DIR, SPEED)) : *pos;
	MOVES & M_BACKWARD ? *pos = sub_v3d(*pos, smul_v3d(CAM_DIR, SPEED)) : *pos;
	rotations(e, dir);
	list && e->update_obj_pos[obj->type] ?
		e->update_obj_pos[obj->type](obj) : 0;
	MOVES ? unit_v3d(*pos) : *pos;
	MOVES || ROT ? menu_object(e) : 0;
	MOVES || ROT ? create_img(e) : 0;
	return (0);
}
