/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params_for_al.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 23:26:18 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/07 16:09:19 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

#define A_L 2

void		init_params_for_al(t_env *e, t_img *tmp_img)
{
	*tmp_img = e->img;
	tmp_img->width = IMG_WIDTH;
	tmp_img->height = IMG_HEIGHT;
	IMG_WIDTH *= A_L;
	IMG_HEIGHT *= A_L;
	IMG = mlx_new_image(MLX, IMG_WIDTH, IMG_HEIGHT);
	IMG_ADDR = mlx_get_data_addr(IMG, &e->img.bpp, &e->img.sizeline, &ENDIAN);
	VW_WIDTH = IMG_WIDTH / 1000.0;
	VW_HEIGHT = IMG_HEIGHT / 1000.0;
	VW_DIST = A_L;
	GAP_X = VW_WIDTH / (double)IMG_WIDTH;
	GAP_Y = VW_HEIGHT / (double)IMG_HEIGHT;
}
