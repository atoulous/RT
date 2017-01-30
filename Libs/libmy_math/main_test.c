/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:39:39 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/18 15:43:41 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "my_math.h"
#include "stdio.h"

int		main(void)
{
	int i;

	i = -1;
	while (++i < 10)
		printf("%f\n", ft_rand_double(0.1, 1.0));
	i = -1;
	while (++i < 10)
		printf("%d\n", ft_rand_int(0, 10000));
	return (0);
}
