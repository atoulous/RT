/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matiere_in_case.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:01:19 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/18 15:43:40 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

#ifndef FILL_MAT
# define FILL_MAT
# define AMB mat->ambient
# define DIFFU mat->diffuse
# define SPEC mat->specular
# define SHI mat->shine
#endif


void	fill_matiere_in_case(t_mat *mat)
{
	AMB = ft_rand_double(0.0, 1.0);
	DIFFU = ft_rand_double(0.0, 1.0);
	SPEC = ft_rand_double(0.0, 1.0);
	SHI = ft_rand_double(100, 2);
}
