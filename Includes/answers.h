/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:51:48 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/18 13:19:56 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSWERS_H
# define ANSWERS_H

# include "rt.h"

typedef struct		s_col_res
{
	t_rgb			rgb;
	t_hsv			tmp;
	double			angle_light;
	double			omega;
	double			intensite;
	t_v3d			ref;
	t_v3d			test;
	t_v3d			r;
}					t_col_res;

#endif
