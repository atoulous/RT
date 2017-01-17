/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:39:39 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/09 16:42:03 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "my_math.h"

int		main(void)
{
	t_5pow		d;
	double		*ret;
	int			i;
	int			y;

	ret = (double *)malloc(sizeof(double) * 4);
	i = -1;
	while (++i < 4)
		ret[i] = -1.0;
	d.q4 = 2;
	d.q3 = -10;
	d.q2 = -12;
	d.q1 = 123;
	d.q0 = 123;
	y = quartic_solver(ret, d);
	printf("%d\n", y);
	i = -1;
	while (++i < 4)
		printf("%f\n", ret[i]);
	free(ret);
	return (0);
}
