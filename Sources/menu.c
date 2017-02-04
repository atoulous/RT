/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:16:40 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/04 19:11:55 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		back_menu(t_env *e)
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

void		change_btn_light(t_env *e)
{
	if (IS_GLOBQ)
		mlx_put_image_to_window(MLX, WIN, ME[1].img.img, ME[1].x, ME[1].y);
	else
		mlx_put_image_to_window(MLX, WIN, ME[2].img.img, ME[2].x, ME[2].y);
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
