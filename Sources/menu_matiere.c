/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_matiere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 21:15:40 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/07 18:12:31 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	print_mat_param(t_env *e, t_object *o)
{
	char s[255];

	sprintf(s, "%.0f", o->mat.diffuse * 100);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 145, 447, F_CLR, s);
	sprintf(s, "%.0f", o->mat.ambient * 100);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 145, 472, F_CLR, s);
	sprintf(s, "%.0f", o->mat.specular * 100);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 145, 497, F_CLR, s);
	sprintf(s, "%.2f", o->coef);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 145, 539, F_CLR, s);
	sprintf(s, "%.2f", o->density);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 145, 565, F_CLR, s);
}

void		print_mat(t_env *e, t_object *o)
{
	mlx_put_image_to_window(MLX, WIN, ME[19].img.img, ME[19].x, ME[19].y);
	mlx_put_image_to_window(MLX, WIN, ME[21].img.img, ME[21].x, ME[21].y);
	mlx_put_image_to_window(MLX, WIN, ME[23].img.img, ME[23].x, ME[23].y);
	mlx_put_image_to_window(MLX, WIN, ME[25].img.img, ME[25].x, ME[25].y);
	mlx_put_image_to_window(MLX, WIN, ME[27].img.img, ME[27].x, ME[27].y);
	if (o->type == 1)
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
	else if (o->asp && !ft_strcmp(o->asp, "water") && o->type == 1)
		mlx_put_image_to_window(MLX, WIN, ME[30].img.img, ME[30].x, ME[30].y);
	print_mat_param(e, o);
}
