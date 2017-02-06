/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_text_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 21:20:00 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/06 21:32:20 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	deform_menu_event(t_env *e, int x, int y, t_object *obj)
{
	char	*tex;

	if (x < WIN_WIDTH - 120)
		tex = ft_strdup("bump");
	else
		tex = ft_strdup("water");
	if (obj->asp && ft_strcmp(obj->asp, tex))
	{
		free(obj->asp);
		obj->asp = NULL;
		obj->asp = ft_strdup(tex);
	}
	else if (obj->asp && !ft_strcmp(obj->asp, tex))
	{
		free(obj->asp);
		obj->asp = NULL;
	}
	else
		obj->asp = ft_strdup(tex);
	free(tex);
	menu_object(e);
	create_img(e);
}

void	text_menu_event(t_env *e, int x, int y, t_object *obj)
{
	char	*tex;

	if (x < WIN_WIDTH - 120)
		tex = (y < 635) ? ft_strdup("marbre") : ft_strdup("damier");
	else
		tex = (y < 635) ? ft_strdup("wood") : ft_strdup("random");
	if (obj->pro && ft_strcmp(obj->pro, tex))
	{
		free(obj->pro);
		obj->pro = NULL;
		obj->pro = ft_strdup(tex);
	}
	else if (obj->pro && !ft_strcmp(obj->pro, tex))
	{
		free(obj->pro);
		obj->pro = NULL;
	}
	else
		obj->pro = ft_strdup(tex);
	free(tex);
	menu_object(e);
	create_img(e);
}
