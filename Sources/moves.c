/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:50:44 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/23 14:21:37 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	moves2(t_v3d **pos, t_list *list, t_object **obj)
{
	(*obj) = (t_object *)(list->content);
	(*pos) = &(*obj)->pos;
}

void	matrice(t_env *e)
{
	t_v4d	pos;
	t_v4d	trans;

	pos = v4d(CAM_DIR.x, CAM_DIR.y, CAM_DIR.z, 0);
	trans = v4d(1, 0, 0, 1);
	pos = translation_pos(pos, trans);
	CAM_DIR = v3d(pos.x, pos.y, pos.z);
}

void	rotations(t_env *e)
{
	double	alpha;

	alpha = 10 * (M_PI / 180);
	if (ROT & M_LEFT)
		CAM_DIR = rodrigues_rotation(CAM_DIR, CAM_UP, -alpha);
	if (ROT & M_RIGHT)
		CAM_DIR = rodrigues_rotation(CAM_DIR, CAM_UP, alpha);
	if (ROT & M_UP)
		CAM_DIR = rodrigues_rotation(CAM_DIR, CAM_RIGHT, -alpha);
	if (ROT & M_DOWN)
		CAM_DIR = rodrigues_rotation(CAM_DIR, CAM_RIGHT, alpha);
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
