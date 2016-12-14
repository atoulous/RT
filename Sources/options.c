/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 14:54:56 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/14 17:46:59 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		in_opt(char c)
{
	int		i;

	i = -1;
	while (OPT_REF[++i])
		if (c == OPT_REF[i])
			return (i);
	return (-1);
}

int				get_options(int ac, char **av, char *opt)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	*opt = 0;
	while (++i < ac && av[i][0] == '-' && av[i][1])
	{
		j = 0;
		if (av[i][1] == '-' && !av[i][2])
		{
			i++;
			break ;
		}
		if (av[i][1] == '-' && av[i][2])
			error_opt(av[i][1]);
		while (av[i][++j])
			if ((k = in_opt(av[i][j])) != -1)
				*opt |= (1 << k);
			else
				error_opt(av[i][j]);
	}
	return (i - 1);
}
