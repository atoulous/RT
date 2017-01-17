/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:50:44 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/16 17:13:39 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	moves2(t_v3d **pos, t_list *list, t_object **obj)
{
	(*obj) = (t_object *)(list->content);
	(*pos) = &(*obj)->pos;
}

void	rotations(t_env *e)
{
	if (ROT & M_LEFT)
		CAM_DIR = sub_v3d(CAM_DIR, smul_v3d(CAM_RIGHT, SPEED / 2));
	if (ROT & M_RIGHT)
		CAM_DIR = add_v3d(CAM_DIR, smul_v3d(CAM_RIGHT, SPEED / 2));
	if (ROT & M_DOWN)
		CAM_DIR = sub_v3d(CAM_DIR, smul_v3d(CAM_UP, SPEED / 2));
	if (ROT & M_UP)
		CAM_DIR = add_v3d(CAM_DIR, smul_v3d(CAM_UP, SPEED / 2));
}

int		moves(t_env *e)
{
	t_v3d		*pos;
	t_list		*list;
	t_object	*obj;

	if (!(list = e->scene->obj_focus))
		pos = &CAM_POS;
	else
		moves2(&pos, list, &obj);
	if (MOVES & M_UP)
		*pos = add_v3d(*pos, smul_v3d(CAM_UP, SPEED));
	if (MOVES & M_DOWN)
		*pos = sub_v3d(*pos, smul_v3d(CAM_UP, SPEED));
	if (MOVES & M_RIGHT)
		*pos = add_v3d(*pos, smul_v3d(CAM_RIGHT, SPEED));
	if (MOVES & M_LEFT)
		*pos = sub_v3d(*pos, smul_v3d(CAM_RIGHT, SPEED));
	if (MOVES & M_FORWARD)
		*pos = add_v3d(*pos, smul_v3d(CAM_DIR, SPEED));
	if (MOVES & M_BACKWARD)
		*pos = sub_v3d(*pos, smul_v3d(CAM_DIR, SPEED));
	(list && e->update_obj_pos[obj->type]) ? e->update_obj_pos[obj->type](obj)\
		: 0;
	rotations(e);
	MOVES || ROT ? create_img(e) : 0;
	return (0);
}
