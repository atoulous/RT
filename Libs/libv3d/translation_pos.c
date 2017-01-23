/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:08:37 by atoulous          #+#    #+#             */
/*   Updated: 2017/01/23 14:08:55 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libv3d.h"

t_v4d	translation_pos(t_v4d pos, t_v4d translation)
{
	t_v4d	new;

	new.x = pos.x + translation.x * pos.w;
	new.y = pos.y + translation.y * pos.w;
	new.z = pos.z + translation.z * pos.w;
	new.w = pos.w;
	return (new);
}
