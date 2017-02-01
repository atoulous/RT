/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:16:40 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/23 18:26:46 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	back_menu(t_env *e)
{
	int				i;
	int				j;
	unsigned int	color;

	j = -1;
	while (++j < WIN_HEIGHT)
	{
		i = -1;
		while (++i < WIN_WIDTH)
		{
			color = (j > 48 && j < WIN_HEIGHT - 131) ? 0x16212F : 0x3D4D65;
			mlx_pixel_put(MLX, WIN, i, j, color);
		}
	}
}

static void	create_interface(t_env *e)
{
	int	i;

	ME[0].path = ft_strdup("Images/top-left.xpm");
	ME[1].path = ft_strdup("Images/top-middle-inv.xpm");
	ME[2].path = ft_strdup("Images/top-middle.xpm");
	ME[3].path = ft_strdup("Images/top-right.xpm");
	ME[4].path = ft_strdup("Images/bottom-middle.xpm");
	ME[5].path = ft_strdup("Images/info-top.xpm");
	ME[6].path = ft_strdup("Images/color-selector.xpm");
	ME[7].path = ft_strdup("Images/info-mat.xpm");
	ME[8].path = ft_strdup("Images/info-plane.xpm");
	ME[9].path = ft_strdup("Images/info-sphere.xpm");
	ME[10].path = ft_strdup("Images/info-cylinder.xpm");
	ME[11].path = ft_strdup("Images/info-cone.xpm");
	ME[12].path = ft_strdup("Images/info-torus.xpm");
	i = -1;
	while (++i < 4)
		ME[i].y = 6;
	ME[4].y = WIN_HEIGHT - 122;
	ME[5].y = 60;
	ME[6].y = 130;
	ME[7].y = 445;
	i = 7;
	while (++i < NB_ME)
		ME[i].y = 306;
	ME[0].x = 15;
	ME[1].x = (WIN_WIDTH / 2) - 65;
	ME[2].x = (WIN_WIDTH / 2) - 65;
	ME[3].x = WIN_WIDTH - 97;
	ME[4].x = (WIN_WIDTH / 2) - 268;
	i = 4;
	while (++i < NB_ME)
		ME[i].x = WIN_WIDTH - 234;
}

void		change_btn_light(t_env *e)
{
	if (OPT_GQ)
		mlx_put_image_to_window(MLX, WIN, ME[1].img.img, ME[1].x, ME[1].y);
	else
		mlx_put_image_to_window(MLX, WIN, ME[2].img.img, ME[2].x, ME[2].y);
}

void		menu_object(t_env *e)
{
	int			i;
	int			j;
	t_object	*o;
	char		s[255];

	if (e->scene->obj_focus)
	{
		o = (t_object *)e->scene->obj_focus->content;
		mlx_put_image_to_window(MLX, WIN, ME[6].img.img, ME[6].x, ME[6].y);
		i = o->type + 7;
		mlx_put_image_to_window(MLX, WIN, ME[i].img.img, ME[i].x, ME[i].y);
		mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 311, F_CLR,
											e->obj_allowed[o->type]);
		if (o->type == 1 || o->type == 2)
			sprintf(s, "%.1f,%.1f,%.1f", o->pos.x, o->pos.y, o->pos.z);
		else	
			sprintf(s, "%.1f,%.1f,%.1f", o->p1.x, o->p1.y, o->p1.y);
		mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 335, F_CLR, s);
		if (o->type == 1)
			sprintf(s, "%.1f,%.1f,%.1f", o->dir.x, o->dir.y, o->dir.z);
		else if (o->type == 3)
			sprintf(s, "%.1f,%.1f,%.1f", o->p2.x, o->p2.y, o->p2.z);
		else if (o->type == 2 || o->type == 4 || o->type == 5)
			sprintf(s, "%.2f", o->r1);
		mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 359, F_CLR, s);
		if (o->type > 2)
		{	
			if (o->type == 3)
				sprintf(s, "%.2f", o->r1);
			else
				sprintf(s, "%.1f,%.1f,%.1f", o->p2.x, o->p2.y, o->p2.z);
			mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 383, F_CLR, s);
		}
		if (o->type > 3)
		{
			sprintf(s, "%.2f", o->r1);
			mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 406, F_CLR, s);
		}
		mlx_put_image_to_window(MLX, WIN, ME[7].img.img, ME[7].x, ME[7].y);
	}
	else
	{
		j = 132;
		while (j++ < 558)
		{
			i = WIN_WIDTH - 237;
			while (i++ < WIN_WIDTH)
				mlx_pixel_put(MLX, WIN, i, j, 0x16212F);
		}
	}
}

void		menu_image(t_env *e)
{
	char *width;
	char *height;
	char *tmp;
	char *res;

	width = ft_itoa(IMG_WIDTH);
	height = ft_itoa(IMG_HEIGHT);
	tmp = ft_strjoin(width, " x ");
	res = ft_strjoin(tmp, height);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 64, F_CLR, e->scene->name);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 87, F_CLR, res);
	free(width);
	free(height);
	free(tmp);
	free(res);
}

void		init_menu(t_env *e)
{
	int		i;

	back_menu(e);
	create_interface(e);
	i = -1;
	while (++i < NB_ME)
	{
		if (!(ME[i].img.img = mlx_xpm_file_to_image(MLX, ME[i].path,
				&(ME[i].img.width), &(ME[i].img.height))))
			error_perso(e, "Menu image not found");
		ME[i].img.addr = mlx_get_data_addr(ME[i].img.img,
				&(ME[i].img.bpp), &(ME[i].img.sizeline), &ENDIAN);
	}
	i = -1;
	while (++i < NB_ME)
	{
		mlx_put_image_to_window(MLX, WIN, ME[i].img.img, ME[i].x, ME[i].y);
		free(ME[i].path);
	}
	change_btn_light(e);
	menu_image(e);
	menu_object(e);
}
