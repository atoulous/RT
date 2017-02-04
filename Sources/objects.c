/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:47:35 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/04 14:40:41 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	color_selector(t_env *e, int x, int y)
{
	int			h;
	double		s;
	double		v;
	t_object	*obj;

	if (e->scene->obj_focus)
	{
		h = 360 * x / 222;
		s = (y < 86) ? 1 * y / 86.0 : 1;
		v = (y > 86) ? (1 * (172 - y) / 86.0) : 1;
		obj = (t_object *)e->scene->obj_focus->content;
		obj->color = hsv_to_rgb(h, s, v);
		create_img(e);
	}
}

void	del_focus_object(t_env *e)
{
	t_list	*lst;
	t_list	*new;

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
		new = ft_lstnew(e->scene->obj_focus->content,
											e->scene->obj_focus->content_size);
		ft_lstadd(&(e->scene->obj_trash), new);
		ft_lstdelone(&(e->scene->obj_focus), &free_obj);
		e->scene->obj_focus = NULL;
		menu_object(e);
		create_img(e);
	}
}

void	undo_del_object(t_env *e)
{
	t_list	*tmp;
	t_list	*new;

	if (e->scene->obj_trash)
	{
		new = ft_lstnew(e->scene->obj_trash->content,
											e->scene->obj_trash->content_size);
		ft_lstadd(&(e->scene->obj), new);
		tmp = e->scene->obj_trash;
		ft_lstdelone(&(e->scene->obj_trash), &free_obj);
		e->scene->obj_trash = tmp->next;
		e->scene->obj_focus = NULL;
		menu_object(e);
		create_img(e);
	}
	tmp = e->scene->obj_trash;
}
