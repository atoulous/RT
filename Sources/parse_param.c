/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 21:00:06 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/17 21:56:40 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	get_depth(int d, char c)
{
	if (c == '{')
		d++;
	if (c == '}')
		d--;
	return (d);
}

char		*find_param(char *small, char *big)
{
	int		i;
	int		j;
	int		d;

	i = -1;
	d = 0;
	while (big[++i])
	{
		if ((d = get_depth(d, big[i])) == 0)
		{
			j = -1;
			while (big[i] && big[i] == small[++j])
				i++;
			if (j >= 0 && small[j] == '\0')
			{
				while (big[i] == ' ' || big[i] == '\n' || big[i] == '\t')
					i++;
				if (big[i] != '{')
					return (NULL);
				return (&big[++i]);
			}
		}
	}
	return (NULL);
}

double		get_double(char *name, char *str)
{
	char	*tmp;
	double	nb;

	if (!(tmp = get_in_acc(name, str)))
		return (0);
	else
	{
		nb = ft_atof(tmp);
		free(tmp);
		return (nb);
	}
	return (0);
}

t_v3d		get_v3d(char *name, char *str)
{
	char	*tmp;
	char	**v;
	int		i;
	t_v3d	ret;

	if (!(tmp = get_in_acc(name, str)))
		return (v3d(0, 0, 0));
	else
	{
		v = ft_strsplit(tmp, ' ');
		i = 0;
		while (v[i])
			i++;
		if (i != 3)
			return (v3d(0, 0, 0));
		ret = v3d(ft_atof(v[0]), ft_atof(v[1]), ft_atof(v[2]));
		free(tmp);
		ft_free_tab(v);
		return (ret);
	}
}
