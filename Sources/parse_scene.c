/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:21:36 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/16 17:38:24 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	free_fct_tab(t_env *e)
{
	int	i;

	i = -1;
	while (e->obj_allowed[++i])
		free(e->obj_allowed[i]);
	free(e->obj_allowed);
}

static void	make_fct_tab(t_env *e)
{
	e->obj_allowed = ft_strsplit(OBJ_ALLOWED, ' ');
	e->obj_fct_obj[0] = &sphere;
	e->obj_fct_obj[1] = &sphere;
	e->obj_fct_obj[2] = &plane;
	e->obj_fct_obj[3] = &sphere;
	e->obj_fct_obj[4] = &cone;
	e->obj_fct_obj[5] = &cylinder;
}

static void	build_scene(t_env *e, char *str)
{
	char	*tmp;

	if (!(e->scene = malloc(sizeof(t_scene))))
		error_perso(e, "malloc (t_scene *)scene failed");
	e->scene->obj = NULL;
	e->scene->light = NULL;
	check_acc(e, str);
	if (!(str = find_param("scene", str)))
		error_perso(e, "No scene found in file");
	if (!(e->scene->name = get_in_acc("name", str)))
		error_perso(e, "No name specified in scene");
	if (!(tmp = get_in_acc("camera", str)))
		error_perso(e, "No camera specified in scene");
	else
	{
		e->scene->cam_pos = get_v3d("origin", tmp);
		e->scene->cam_dir = get_v3d("dir", tmp);
		free(tmp);
	}
	while ((tmp = get_in_acc("object", str)))
	{
		build_object(e, tmp);
		str += ft_strlen(tmp);
		free(tmp);
	}
}

static int	avoid_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
		i++;
	return (i);
}

void		parse_rt(t_env *e, char *file_name)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*file;
	int		i;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		error_perso(e, "Failed opening file");
	file = ft_strnew(0);
	while (get_next_line(fd, &line))
	{
		i = avoid_spaces(line);
		if (line[i] && line[i] != '#')
		{
			tmp = file;
			file = ft_strjoin(tmp, &line[i]);
			free(tmp);
		}
		free(line);
	}
	close(fd);
	make_fct_tab(e);
	build_scene(e, file);
	free_fct_tab(e);
	free(file);
}
