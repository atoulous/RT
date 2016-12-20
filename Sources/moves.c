/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:50:44 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/20 10:49:22 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	del_sel_object(t_env *e)
{
	t_list	*lst;

	if (e->scene->obj_focus)
	{
		lst = e->scene->obj;
		if (lst == e->scene->obj_focus)
			e->scene->obj = e->scene->obj->next;
		else
		{
			while (lst && lst->next && lst->next != e->scene->obj_focus)
				lst = lst->next;
			lst->next = e->scene->obj_focus->next;
		}
		ft_lstdelone(&(e->scene->obj_focus), &free_obj);
		e->scene->obj_focus = NULL;
		create_img(e);
	}
}

int		moves(t_env *e)
{
	t_v3d	*pos;

	if (!e->scene->obj_focus)
		pos = &CAM_POS;
	else
		pos = &(((t_object *)(e->scene->obj_focus->content))->pos);
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
	if (MOVES > 0)
		create_img(e);
	return (0);
}
