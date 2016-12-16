/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:21:36 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/16 17:37:31 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char		*go_to_next_acc(char *str, int n)
{
	char	*tmp;

	tmp = str;
	while ((*tmp == '\n' || *tmp == '\t' || *tmp == ' ') && tmp != '\0'
																	&& n-- > 0)
		tmp++;
	if (*tmp != '{')
		return (NULL);
	return (++tmp);
}

void		check_acc(t_env *e, char *str)
{
	int		i;
	int		nb;

	i = -1;
	nb = 0;
	while (str[++i] && nb >= 0)
	{
		if (str[i] == '{')
			nb++;
		else if (str[i] == '}')
			nb--;
	}
	if (nb != 0)
		error_perso(e, "missing one \"}\" in file");
}

int			size_to_end_acc(char *str)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '{')
			j++;
		if (str[i] == '}' && j == 0)
			return (i);
		if (str[i] == '}' && j > 0)
			j--;
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	return (-1);
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
	//char	*tmpy;
	//char	*tmpz;
	int		i;

	if (!(tmp = get_in_acc(name, str)))
		return (v3d(0, 0, 0));
	else
	{
		printf("str: %s\n", tmp);
		v = ft_strsplit(tmp, ' ');
		i = 0;
		while (tmp[i])
			i++;
		printf("i: %d\n", i);
		//if (i != 4)
		//	return (v3d(0, 0, 0));
		/*
		while ((*tmp == '\n' || *tmp == '\t' || *tmp == ' ') && n-- > 0)
			tmp++;
		tmpy = tmp;
		while (*tmpy != '\n' && *tmpy != '\t' && *tmpy != ' ' && n-- > 0)
			tmpy++;
		while ((*tmpy == '\n' || *tmpy == '\t' || *tmpy == ' ') && n-- > 0)
			tmpy++;
		tmpz = tmpy;
		while (*tmpz != '\n' && *tmpz != '\t' && *tmpz != ' ' && n-- > 0)
			tmpz++;*/
		return (v3d(ft_atof(v[0]), ft_atof(v[1]), ft_atof(v[2])));
		free(tmp);
	}
}

char		*get_in_acc(char *param, char *str)
{
	char	*tmp;
	char	*tmp1;
	char	*tmp2;
	int		len;

	if (!(tmp = find_param(param, str)))
		return (NULL);
	if ((len = size_to_end_acc(tmp)) == -1)
		return (NULL);
	tmp1 = strndup(tmp, size_to_end_acc(tmp));
	tmp2 = ft_strtrim(tmp1);
	free(tmp1);
	return (tmp2);
}

char		*find_param(char *small, char *big)
{
	int	i;
	int	j;
	int	d;

	i = -1;
	d = 0;
	while (big[++i])
	{
		if (big[i] == '{')
			d++;
		if (big[i] == '}')
			d--;
		if (d == 0)
		{
			j = -1;
			while (big[i] && big[i] == small[++j])
				i++;
			if (small[j] == '\0')
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
