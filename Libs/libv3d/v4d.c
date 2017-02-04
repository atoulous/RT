/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:07:47 by atoulous          #+#    #+#             */
/*   Updated: 2017/01/23 14:08:59 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libv3d.h"

t_v4d	v4d(double x, double y, double z, double w)
{
	t_v4d	matrice;

	matrice.x = x;
	matrice.y = y;
	matrice.z = z;
	matrice.w = w;
	return (matrice);
}
