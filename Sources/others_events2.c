/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_events2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:16:04 by atoulous          #+#    #+#             */
/*   Updated: 2017/01/30 20:49:05 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	back_plane(void	*arg)
{
	t_env	*e;

	e = (t_env *)arg;
	BACK_PLANE ? BACK_PLANE = 0 : (BACK_PLANE = 1);
	create_img(e);
}
