/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:16:40 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/07 09:57:01 by jubarbie         ###   ########.fr       */
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

void		menu_image_filter(t_env *e)
{
	if (!(e->scene->obj_focus))
	{
		(!IS_GREY) ?
		mlx_put_image_to_window(MLX, WIN, ME[13].img.img, ME[13].x, ME[13].y) :
		mlx_put_image_to_window(MLX, WIN, ME[14].img.img, ME[14].x, ME[14].y);
		(!IS_SEPIA) ?
		mlx_put_image_to_window(MLX, WIN, ME[15].img.img, ME[15].x, ME[15].y) :
		mlx_put_image_to_window(MLX, WIN, ME[16].img.img, ME[16].x, ME[16].y);
		(!IS_CRTN) ?
		mlx_put_image_to_window(MLX, WIN, ME[17].img.img, ME[17].x, ME[17].y) :
		mlx_put_image_to_window(MLX, WIN, ME[18].img.img, ME[18].x, ME[18].y);
		mlx_put_image_to_window(MLX, WIN, ME[31].img.img, ME[31].x, ME[31].y);
		(!IS_STEREO) ?
		mlx_put_image_to_window(MLX, WIN, ME[33].img.img, ME[33].x, ME[33].y) :
		mlx_put_image_to_window(MLX, WIN, ME[34].img.img, ME[34].x, ME[34].y);
		(!IS_MOTION_BLUR) ?
		mlx_put_image_to_window(MLX, WIN, ME[35].img.img, ME[35].x, ME[35].y) :
		mlx_put_image_to_window(MLX, WIN, ME[36].img.img, ME[36].x, ME[36].y);
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
