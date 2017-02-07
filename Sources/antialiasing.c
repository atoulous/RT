/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 10:47:27 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/07 16:14:25 by mmoullec         ###   ########.fr       */
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
	addr[y * img->sizeline + x * (4)] = rgb.r;
	addr[y * img->sizeline + x * (4) + 1] = rgb.g;
	addr[y * img->sizeline + x * (4) + 2] = rgb.b;
}

int			col(t_env *e, char *addr, t_l l, int alpha)
{
	int z[A_L * 2];
	t_l ret;
	t_l p;

	ret.x = 0;
	ret.y = -1;
	p.x = -1;
	p.y = -1;
	while (++p.y < A_L)
	{
		p.x = -1;
		while (++p.x < A_L)
			z[++ret.y] = (int)addr[((l.y * A_L) + p.y) * e->img.sizeline + \
						((l.x * A_L) + p.x) * (e->img.bpp / 8) + alpha];
	}
	ret.y = -1;
	while (++ret.y < (A_L * 2))
	{
		if (z[ret.y] >= 0)
			ret.x += z[ret.y];
		else
			ret.x += 255 + z[ret.y];
	}
	return (ret.x / (A_L * 2));
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
	mlx_destroy_image(MLX, IMG);
	restart_params(e);
	e->img = tmp_img;
	e->img.img = tmp_img.img;
	mlx_put_image_to_window(MLX, WIN, IMG, IMG_GAP_X, IMG_GAP_Y + 49);
	ft_putstr("\033[32mAnti-aliasing x2 ON\033[0m\n");
}
