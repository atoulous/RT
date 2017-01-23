/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libv3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:51:03 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/23 14:22:41 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBV3D_H
# define LIBV3D_H

# include <math.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_v3d
{
	double	x;
	double	y;
	double	z;
}				t_v3d;

typedef struct	s_v4d
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_v4d;

void			print_v3d(t_v3d v, char *name);
double			length_v3d(t_v3d v);
double			cos_v3d(t_v3d v1, t_v3d v2);
double			dot_v3d(t_v3d v1, t_v3d v2);
t_v3d			v3d(double x, double y, double z);
t_v3d			add_v3d(t_v3d v1, t_v3d v2);
t_v3d			sub_v3d(t_v3d v1, t_v3d v2);
t_v3d			smul_v3d(t_v3d v, double nb);
t_v3d			cross_v3d(t_v3d v1, t_v3d v2);
t_v3d			unit_v3d(t_v3d v);
t_v3d			rodrigues_rotation(t_v3d vec_dir, t_v3d axis, double alpha);
t_v4d			v4d(double x, double y, double z, double w);
t_v4d			translation_pos(t_v4d pos, t_v4d translation);

#endif
