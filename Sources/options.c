/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 14:54:56 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/05 11:42:06 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			print_help(void)
{
	ft_putendl("\033[32mYOU NEED HELP\033[0m\n");
	ft_putendl("\033[33mPress ESC to quit\033[0m");
	ft_putendl("\033[33mPress SPACE to reset camera\033[0m");
	ft_putendl("\033[33mPress TAB to select next object\033[0m");
	ft_putendl("\033[33mPress DELETE to delete focus object\033[0m");
	ft_putendl("\033[33mPress O to switch on/off shadows\033[0m");
	ft_putendl("\033[33mPress B to switch on/off shininess\033[0m");
	ft_putendl("\033[33mPress L to switch on/off light game\033[0m");
	ft_putendl("\033[33mPress - or + to change rotation speed\033[0m");
	ft_putendl("\033[33mPress CLEAR or = to change brightness indice\033[0m");
	ft_putendl("\033[33mPress / or * to change atmosphere indice\033[0m");
	ft_putendl("\033[33mPress CMD + Z to undo last del\033[0m");
	ft_putendl("\033[33mPress < or > to change speed\033[0m");
	ft_putendl("\033[33mPress W,A,S,D to move\033[0m");
	ft_putendl("\033[33mPress ARROW UP to move up\033[0m");
	ft_putendl("\033[33mPress ARROW DOWN to move down\033[0m");
	ft_putendl("\033[33mPress 4 to rotate left\033[0m");
	ft_putendl("\033[33mPress 6 to rotate right\033[0m");
	ft_putendl("\033[33mPress 2 to rotate down\033[0m");
	ft_putendl("\033[33mPress 8 to rotate up\033[0m");
	ft_putendl("\033[33mPress ` to take screenshot\033[0m");
	ft_putendl("\033[33mPress C to do cartoon effect\033[0m");
	ft_putendl("\033[33mPress ; to do sepia effect\033[0m");
	ft_putendl("\033[33mPress ' to do grey effect\033[0m\n");
}

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
