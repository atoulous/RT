/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:50:33 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/16 14:30:54 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		test_v3d_torus(t_v3d axis)
{
	if (axis.x == 0 && axis.y == 0 && axis.z == 0)
		return (1);
	return (0);
}

void	torus_error(t_object *obj, t_env *e)
{
	if (obj->r1 > obj->r2)
	{
		ft_putstr("\033[31mError: Torus : r1 doit etre inferieur a r2\n");
		free(e);
		exit(0);
	}
	if (test_v3d_torus(obj->p2))
	{
		ft_putstr("\033[31mError: Torus: p2 (axe) ne doit pas etre egal a 0\n");
		free(e);
		exit(0);
	}
}
