/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 21:00:06 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/09 13:44:39 by mmoullec         ###   ########.fr       */
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

/*
** Return a pointer to the first small found in big at the same depth
** Ex:
** --
** big = "	mat {
**				color { red }
**			}
** 			color { red }"
** --
** find_param("color, big) will return a pointer to the second color because the
** first one is one level deeper
*/

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

/*
** Return the value of a double type of param
** For exemple r1 { 2.403 }
*/

double		get_double(char *name, char *str, t_env *e)
{
	char	*tmp;
	double	nb;

	if (!(tmp = get_in_acc(name, str)))
		error_perso(e, name);
	else
	{
		nb = ft_atof(tmp);
		free(tmp);
		return (nb);
	}
	return (0);
}

/*
** Return the value of a 3d vector type of param
** For exemple cam_pos { 2.4 200 10.5 }
*/

t_v3d		get_v3d(char *name, char *str, t_env *e)
{
	char	*tmp;
	char	**v;
	int		i;
	t_v3d	ret;

	if (!(tmp = get_in_acc(name, str)))
		error_perso(e, name);
	else
	{
		v = ft_strsplit(tmp, ' ');
		i = 0;
		while (v[i])
			i++;
		if (i != 3)
			return (v3d(0, 0, 1));
		ret = v3d(ft_atof(v[0]), ft_atof(v[1]), ft_atof(v[2]));
		free(tmp);
		ft_free_tab(v);
		return (ret);
	}
	return (v3d(0, 0, 0));
}
