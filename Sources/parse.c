/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:21:36 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/17 21:56:44 by jubarbie         ###   ########.fr       */
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
