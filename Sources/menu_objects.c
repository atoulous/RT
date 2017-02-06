/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:29:15 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/06 20:22:27 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	back_obj_menu(t_env *e)
{
	int	i;
	int	j;

	j = 132;
	while (j++ < 663)
	{
		i = WIN_WIDTH - 237;
		while (i++ < WIN_WIDTH)
			mlx_pixel_put(MLX, WIN, i, j, 0x16212F);
	}
}

static void	print_mat(t_env *e, t_object *o)
{
	char	s[255];

	mlx_put_image_to_window(MLX, WIN, ME[19].img.img, ME[19].x, ME[19].y);
	mlx_put_image_to_window(MLX, WIN, ME[21].img.img, ME[21].x, ME[21].y);
	mlx_put_image_to_window(MLX, WIN, ME[23].img.img, ME[23].x, ME[23].y);
	mlx_put_image_to_window(MLX, WIN, ME[25].img.img, ME[25].x, ME[25].y);
	mlx_put_image_to_window(MLX, WIN, ME[27].img.img, ME[27].x, ME[27].y);
	mlx_put_image_to_window(MLX, WIN, ME[29].img.img, ME[29].x, ME[29].y);
	if (o->pro && !ft_strcmp(o->pro, "marbre"))
		mlx_put_image_to_window(MLX, WIN, ME[20].img.img, ME[20].x, ME[20].y);
	else if (o->pro && !ft_strcmp(o->pro, "wood"))
		mlx_put_image_to_window(MLX, WIN, ME[22].img.img, ME[22].x, ME[22].y);
	else if (o->pro && !ft_strcmp(o->pro, "damier"))
		mlx_put_image_to_window(MLX, WIN, ME[24].img.img, ME[24].x, ME[24].y);
	else if (o->pro && !ft_strcmp(o->pro, "random"))
		mlx_put_image_to_window(MLX, WIN, ME[26].img.img, ME[26].x, ME[26].y);
	if (o->asp && !ft_strcmp(o->asp, "bump"))
		mlx_put_image_to_window(MLX, WIN, ME[28].img.img, ME[28].x, ME[28].y);
	else if (o->asp && !ft_strcmp(o->asp, "water"))
		mlx_put_image_to_window(MLX, WIN, ME[30].img.img, ME[30].x, ME[30].y);
	sprintf(s, "%.0f", o->mat.diffuse * 100);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 145, 447, F_CLR, s);
	sprintf(s, "%.0f", o->mat.ambient * 100);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 145, 472, F_CLR, s);
	sprintf(s, "%.0f", o->mat.specular * 100);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 145, 497, F_CLR, s);
	sprintf(s, "%.2f", o->coef);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 145, 539, F_CLR, s);
}

static void	print_obj_param2(t_env *e, t_object *o)
{
	char	s[255];

	if (o->type > 2)
	{
		if (o->type == 3 || o->type == 5)
			sprintf(s, "%.2f", o->r1);
		else
			sprintf(s, "%.1f,%.1f,%.1f", o->p2.x, o->p2.y, o->p2.z);
		mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 383, F_CLR, s);
	}
	if (o->type > 3)
	{
		sprintf(s, "%.2f", o->r2);
		mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 406, F_CLR, s);
	}
	mlx_put_image_to_window(MLX, WIN, ME[7].img.img, ME[7].x, ME[7].y);
	print_mat(e, o);
}

static void	print_obj_param(t_env *e, t_object *o)
{
	char	s[255];
	int		i;

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
	else if (o->type == 3 && o->type == 5)
		sprintf(s, "%.1f,%.1f,%.1f", o->p2.x, o->p2.y, o->p2.z);
	else if (o->type == 2 || o->type == 4)
		sprintf(s, "%.2f", o->r1);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 359, F_CLR, s);
	print_obj_param2(e, o);
}

void		menu_object(t_env *e)
{
	t_object	*o;

	if (e->scene->obj_focus)
	{
		o = (t_object *)e->scene->obj_focus->content;
		mlx_put_image_to_window(MLX, WIN, ME[6].img.img, ME[6].x, ME[6].y);
		print_obj_param(e, o);
	}
	else
	{
		back_obj_menu(e);
		menu_image_filter(e);
	}
}
