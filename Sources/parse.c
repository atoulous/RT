/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:21:36 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/15 16:31:40 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char		*go_to_next_acc(t_env *e, char *str, int n)
{
	char	*tmp;

	tmp = str;
	while ((*tmp == '\n' || *tmp == '\t' || *tmp == ' ') && tmp != '\0'
																	&& n-- > 0)
		tmp++;
	if (*tmp != '{')
		error_perso(e, "Missing one \"{\" in file");
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
		return (-1)
	return (-1);
}

t_v3d		get_v3d(char *name, char *str)
{
	char	*tmp;
	char	*tmpy;
	char	*tmpz;

	if (!(tmp = ft_strnstr(str, name, n)))
		return (v3d(0, 0, 0));
	else
	{
		tmp = go_to_next_acc(e, tmp + ft_strlen(name), n);
		while ((*tmp == '\n' || *tmp == '\t' || *tmp == ' ') && n-- > 0)
			tmp++;
		tmpy = tmp;
		while (*tmpy != '\n' && *tmpy != '\t' && *tmpy != ' ' && n-- > 0)
			tmpy++;
		while ((*tmpy == '\n' || *tmpy == '\t' || *tmpy == ' ') && n-- > 0)
			tmpy++;
		tmpz = tmpy;
		while (*tmpz != '\n' && *tmpz != '\t' && *tmpz != ' ' && n-- > 0)
			tmpz++;
		return (v3d(ft_atof(tmp), ft_atof(tmpy), ft_atof(tmpz)));
	}
}

char		*get_in_acc(char param, char *str)
{
	char	*tmp;
	char	*tmp1;
	char	*tmp2;
	int		len;

	if (!(tmp = find_param(param, str)))
		return (NULL);
	if ((len = size_to_end_acc(tmp)) == -1)
		return (NULL)
	tmp1 = strndup(tmp, size_to_end_acc(e, tmp));
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
				{	
					i++;
					j++;
				}
				if (big[i] != '{')
					return (NULL);
				return (&big[++i]);
			}
		}
	}
	return (NULL);
}
