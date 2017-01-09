/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:50:33 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/09 19:09:47 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	torus_error(t_object *obj)
{
	if (obj->r1 > obj->r2)
	{
		ft_putstr("\033[31mError: Torus : r1 doit etre inferieur a r2\n");
		exit (0);
	}
}
