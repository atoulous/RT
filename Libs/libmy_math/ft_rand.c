/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:08:02 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/18 15:30:18 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_math.h"

int		ft_rand_int(int a, int b)
{
	srand(time(NULL));
	if (a < b)
		return (rand() % (b - a) + a);
	else
		return (rand() % (a - b) + b);
}

double	ft_rand_double(double a, double b)
{
	srand(time(NULL));
	if (a < b)
		return (rand() / (double)RAND_MAX * (a - b) + b);
	else
		return (rand() / (double)RAND_MAX * (b - a) + a);
}
