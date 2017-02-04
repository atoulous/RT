/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:50:44 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/04 15:12:35 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	moves_actions(t_env *e, t_v3d *pos)
{
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
}

int			moves(t_env *e)
{
	t_v3d		*pos;
	t_list		*list;
	t_object	*obj;

	if (!(list = e->scene->obj_focus))
		pos = &CAM_POS;
	else
	{
		obj = (t_object *)(list->content);
		pos = &(obj->pos);
	}
	moves_actions(e, pos);
	(list && e->update_obj_pos[obj->type]) ?
								e->update_obj_pos[obj->type](obj) : 0;
	if (MOVES > 0)
	{
		create_img(e);
		menu_object(e);
	}
	return (0);
}
