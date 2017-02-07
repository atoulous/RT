/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 10:47:27 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/07 00:03:16 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Save the color in the pixel (x, y) of the image given
*/

#define A_L 2

void		img_put_pixel2(t_img *img, int x, int y, t_rgb rgb)
{
	char	*addr;

	addr = img->addr;
	addr[y * img->sizeline + x * (img->bpp / 8)] = rgb.r;
	addr[y * img->sizeline + x * (img->bpp / 8) + 1] = rgb.g;
	addr[y * img->sizeline + x * (img->bpp / 8) + 2] = rgb.b;
}

int			col(t_env *e, char *addr, t_l l, int alpha)
{
	int z[4];
	int ret;
	int k;

	ret = 0;
	k = -1;
	z[0] = (int)addr[(l.y * A_L) * e->img.sizeline + (l.x * A_L) * \
			(e->img.bpp / 8) + alpha];
	z[1] = (int)addr[((l.y * A_L) + 1) * e->img.sizeline + (l.x * A_L) * \
			(e->img.bpp / 8) + alpha];
	z[2] = (int)addr[(l.y * A_L) * e->img.sizeline + ((l.x * A_L) + 1) * \
			(e->img.bpp / 8) + alpha];
	z[3] = (int)addr[((l.y * A_L) + 1) * e->img.sizeline + ((l.x * A_L) + 1) * \
			(e->img.bpp / 8) + alpha];
	while (++k < 4)
	{
		if (z[k] >= 0)
			ret += abs(z[k]);
		else
			ret += 255 + z[k];
	}
	return (ret / 4);
}

void		run_al(t_env *e, t_l l, t_img *img)
{
	t_rgb rgb;

	IMG_WIDTH /= A_L;
	IMG_HEIGHT /= A_L;
	l.x = -1;
	l.y = -1;
	while (++l.y < IMG_HEIGHT)
	{
		l.x = -1;
		while (++l.x < IMG_WIDTH)
		{
			rgb.r = col(e, IMG_ADDR, l, 0);
			rgb.g = col(e, IMG_ADDR, l, 1);
			rgb.b = col(e, IMG_ADDR, l, 2);
			img_put_pixel2(img, l.x, l.y, rgb);
		}
	}
}

void		restart_params(t_env *e)
{
	VW_WIDTH = IMG_WIDTH / 1000.0;
	VW_HEIGHT = IMG_HEIGHT / 1000.0;
	VW_DIST = 1.0;
	GAP_X = VW_WIDTH / (double)IMG_WIDTH;
	GAP_Y = VW_HEIGHT / (double)IMG_HEIGHT;
}

void		antialiasing(t_env *e)
{
	int			i;
	t_l			l;
	pthread_t	th[NB_TH];
	t_img		tmp_img;

	init_params_for_al(e, &tmp_img);
	i = -1;
	while (++i < NB_TH)
		if (pthread_create(&th[i], NULL, &raytracer, (void *)(e->param[i])) < 0)
			error_perso(e, "create thread failed");
	i = -1;
	while (++i < NB_TH)
		(void)pthread_join(th[i], NULL);
	run_al(e, l, &tmp_img);
	restart_params(e);
	mlx_destroy_image(MLX, IMG);
	e->img = tmp_img;
	mlx_put_image_to_window(MLX, WIN, IMG, IMG_GAP_X, IMG_GAP_Y + 49);
}
