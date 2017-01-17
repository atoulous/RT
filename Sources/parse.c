/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:21:36 by jubarbie          #+#    #+#             */
/*   Updated: 2017/01/09 17:49:45 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Check in the given string if all opening brace there is a closing one
*/

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

/*
** Return the number of characters to the next closing brace at same depth
*/

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

/*
** Return the content inside the braces of the param given in the str given
** The return string is trimed
** --
** Ex:
** param = "my_param"
** str = "some text my_param { inside braces text } some more text"
** function will return "inside param"
** --
** The returned string is freshly allocated, needs to be freed!
*/

char		*get_in_acc(char *param, char *str)
{
	if (!ft_strcmp("name", param))
		printf("param = %s, str = %s\n=========\n", param, str);
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
		if (!ft_strcmp("name", param))
	printf("tmp2 ==> %s\n---------------------------------------\n\n", tmp2);
	free(tmp1);
	return (tmp2);
}
