/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:47:35 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/09 13:32:47 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
		create_img(e);
	}
	tmp = e->scene->obj_trash;
}
