/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_events2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:16:04 by atoulous          #+#    #+#             */
/*   Updated: 2017/02/04 19:18:22 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	back_plane(void	*arg)
{
	t_env	*e;

	e = (t_env *)arg;
	IS_BPLANE ? (OPT ^= BPLANE) : (OPT |= BPLANE);
	(IS_BPLANE && IS_OPT_D) ? ft_putendl("Swith OFF back_plane") : 0;
	(!IS_BPLANE && IS_OPT_D) ? ft_putendl("Switch ON back_plane") : 0;
	menu_object(e);
	create_img(e);
}
