/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:21:36 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/23 16:02:11 by atoulous         ###   ########.fr       */
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
	e->calc_obj_param[0] = NULL;
	e->obj_fct_obj[1] = &sphere;
	e->calc_obj_param[1] = NULL;
	e->obj_fct_obj[2] = &plane;
	e->calc_obj_param[2] = NULL;
	e->obj_fct_obj[3] = &sphere;
	e->calc_obj_param[3] = NULL;
	e->obj_fct_obj[4] = &cone;
	e->calc_obj_param[4] = &calc_cone_param;
	e->obj_fct_obj[5] = &cylinder;
	e->calc_obj_param[5] = &calc_cylinder_param;
}

static void	get_resolution(t_env *e, char *str)
{
	char	*tmp;
	char	**res;

	if ((tmp = get_in_acc("render", str)))
	{
		res = ft_strsplit(tmp, ' ');
		IMG_WIDTH = ft_atoi(res[0]);
		IMG_HEIGHT = ft_atoi(res[1]);
		free(tmp);
		ft_free_tab(res);
	}
	IMG_WIDTH = (IMG_WIDTH <= 0) ? 800 : IMG_WIDTH;
	IMG_HEIGHT = (IMG_HEIGHT <= 0) ? 700 : IMG_HEIGHT;
}

static void	build_scene(t_env *e, char *str)
{
	char	*tmp;

	if (!(e->scene = malloc(sizeof(t_scene))))
		error_perso(e, "malloc (t_scene *)scene failed");
	e->scene->obj = NULL;
	e->scene->light = NULL;
	if (!(str = find_param("scene", str)))
		error_perso(e, "No scene found in file");
	get_resolution(e, str);
	if (!(e->scene->name = get_in_acc("name", str)))
		error_perso(e, "No name specified in scene");
	if (!(tmp = get_in_acc("camera", str)))
		error_perso(e, "No camera specified in scene");
	else
	{
		CAM_POS = get_v3d("origin", tmp);
		CAM_DIR = get_v3d("dir", tmp);
		free(tmp);
	}
	while ((tmp = get_in_acc("object", str)))
	{
		build_object(e, tmp);
		str = find_param("object", str) + ft_strlen(tmp) + 1;
		free(tmp);
	}
}

void		parse_rt(t_env *e, char *file_name)
{
	int		fd;
	char	*l;
	char	*file;
	int		i;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		error_perso(e, "Failed opening file");
	file = ft_strnew(0);
	while (get_next_line(fd, &l))
	{
		i = 0;
		while (l[i] && (l[i] == ' ' || l[i] == '\t' || l[i] == '\n'))
			i++;
		if (l[i] && l[i] != '#')
			file = ft_strjoin_free(file, &l[i]);
		free(l);
	}
	close(fd);
	make_fct_tab(e);
	check_acc(e, file);
	build_scene(e, file);
	free_fct_tab(e);
	free(file);
}
