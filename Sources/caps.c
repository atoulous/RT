/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:38:22 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/21 10:40:54 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	caps(t_ray *ray, double r, t_v3d n, t_v3d p)
{
	t_v3d	tmp;
	double	det;

	det = dot_v3d(n, ray->dir);
	if (det < 0.0000001 || det > 0.0000001)
	{
		tmp = sub_v3d(p, ray->pos);
		det = dot_v3d(tmp, n) / det;
		if (det > 0)
		{
			tmp = add_v3d(ray->pos, smul_v3d(ray->dir, det));
			if (dot_v3d(sub_v3d(tmp, p), sub_v3d(tmp, p)) >= r * r)
				return (-1);
			return (det);
		}
	}
	return (-1);
}
