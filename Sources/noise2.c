/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:21:59 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/30 16:50:31 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_xyz(t_noise *noise, double x, double y, double z)
{
	XX = (int)floor(x) & 255;
	YY = (int)floor(y) & 255;
	ZZ = (int)floor(z) & 255;
}

void	fill_uvw(t_noise *noise, double x, double y, double z)
{
	U = fade(x);
	V = fade(y);
	W = fade(z);
}

void	fill_baba(t_noise *noise)
{
	A1 = PER[XX] + YY;
	AA = PER[A1] + ZZ;
	AB = PER[A1 + 1] + ZZ;
	B1 = PER[XX + 1] + YY;
	BA = PER[B1] + ZZ;
	BB = PER[B1 + 1] + ZZ;
}

double		noise_to_ret(t_noise *noise, double x, double y, double z)
{
	return (lerp(W, lerp(V, lerp(U, grad(PER[AA], x, y, z),
						grad(PER[BA], x - 1, y, z)),
					lerp(U, grad(PER[AB], x, y - 1, z),
						grad(PER[BB], x - 1, y - 1, z))),
				lerp(V, lerp(U, grad(PER[AA + 1], x, y, z - 1),
						grad(PER[BA + 1], x - 1, y, z - 1)),
					lerp(U, grad(PER[AB + 1], x, y - 1, z - 1),
						grad(PER[BB + 1], x - 1, y - 1, z - 1)))));
}
