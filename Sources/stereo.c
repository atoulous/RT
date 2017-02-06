/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 22:14:04 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/06 23:04:03 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_stereo(t_env *e)
{
	IMG = mlx_new_image(MLX, IMG_WIDTH, IMG_HEIGHT);
	IMG_ADDR = mlx_get_data_addr(IMG, &e->img.bpp, &e->img.sizeline, &ENDIAN);
}

int			create_stereo_img(t_env *e, int j)
{
	int			i;
	pthread_t	th[NB_TH];

	i = -1;
	while (++i < NB_TH)
		if (pthread_create(&th[i], NULL, &raytracer, (void *)(e->param[i])) < 0)
			error_perso(e, "create thread failed");
	i = -1;
	while (++i < NB_TH)
		(void)pthread_join(th[i], NULL);
	mlx_put_image_to_window(MLX, WIN, IMG,
			IMG_GAP_X + IMG_WIDTH * j, IMG_GAP_Y + 49 + IMG_HEIGHT / 2);
	mlx_destroy_image(MLX, IMG);
	return (0);
}

int			stereo(t_env *e)
{
	t_img	tmp;

	tmp = e->img;
	IMG_WIDTH /= 2;
	IMG_HEIGHT /= 2;
	VW_WIDTH = IMG_WIDTH / 1000.0;
	VW_HEIGHT = IMG_HEIGHT / 1000.0;
	VW_DIST /= 2.0;
	init_stereo(e);
	create_stereo_img(e, 0);
	CAM_POS = add_v3d(CAM_POS, smul_v3d(CAM_RIGHT, -2));
	init_stereo(e);
	create_stereo_img(e, 1);
	IMG_WIDTH *= 2;
	IMG_HEIGHT *= 2;
	VW_WIDTH = IMG_WIDTH / 1000.0;
	VW_HEIGHT = IMG_HEIGHT / 1000.0;
	VW_DIST *= 2.0;
	e->img = tmp;
	return (0);
}
