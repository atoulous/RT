/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 10:47:27 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/06 22:39:10 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Save the color in the pixel (x, y) of the image given
*/

void		img_put_pixel2(t_img *img, int x, int y, unsigned int color)
{
	char	*addr;

	addr = img->addr;
	addr[y * img->sizeline + x * (img->bpp / 8)] = (color & 0xFF) ;
	addr[y * img->sizeline + x * (img->bpp / 8) + 1] = ((color & 0xFF00) >> 8) ;
	addr[y * img->sizeline + x * (img->bpp / 8) + 2] = ((color & 0xFF0000) >> 16);
}

int col(t_env *e, char *addr, int i, int j, int alpha)
{
	int z[4];
	int cpt = 1;
	int ret = 0;

	z[0] = (int)addr[(j * 2) * e->img.sizeline + (i * 2) * (e->img.bpp / 8) + alpha];
	z[1] = (int)addr[((j * 2) + 1) * e->img.sizeline + (i * 2) * (e->img.bpp / 8) + alpha];
	z[2] = (int)addr[(j * 2) * e->img.sizeline + ((i* 2) + 1) * (e->img.bpp / 8) + alpha];
	z[3] = (int)addr[((j * 2) + 1) * e->img.sizeline + ((i * 2) + 1) * (e->img.bpp / 8) + alpha];
	for (int k = 0; k < 4;k++)
	{
		if (z[k] >= 0)
			ret += abs(z[k]);
		else
			ret += 255 + z[k];
	}
	return (ret / 4);
}


void		antialiasing(t_env *e)
{
	int			i;
	int			j;

	pthread_t	th[NB_TH];
	t_img		tmp_img;
	t_img		anti_img;
	int			color;
	int			r;
	int			g;
	int			b;

	tmp_img = e->img;
	tmp_img.width = IMG_WIDTH;
	tmp_img.height = IMG_HEIGHT;
	IMG_WIDTH *= 2;
	IMG_HEIGHT *= 2;
	IMG = mlx_new_image(MLX, IMG_WIDTH, IMG_HEIGHT);
	IMG_ADDR = mlx_get_data_addr(IMG, &e->img.bpp, &e->img.sizeline, &ENDIAN);
	VW_WIDTH = IMG_WIDTH / 1000.0;
	VW_HEIGHT = IMG_HEIGHT / 1000.0;
	VW_DIST = 2.0;
	GAP_X = VW_WIDTH / (double)IMG_WIDTH;
	GAP_Y = VW_HEIGHT / (double)IMG_HEIGHT;
	i = -1;
	while (++i < NB_TH)
		if (pthread_create(&th[i], NULL, &raytracer, (void *)(e->param[i])) < 0)
			error_perso(e, "create thread failed");
	i = -1;
	while (++i < NB_TH)
		(void)pthread_join(th[i], NULL);
	IMG_WIDTH /= 2;
	IMG_HEIGHT /= 2;
	j = -1;
	while(++j < IMG_HEIGHT)
	{
		i = -1;
		while (++i < IMG_WIDTH)
		{
			r = col(e, IMG_ADDR, i, j, 0);
			g = col(e, IMG_ADDR, i, j, 1);
			b = col(e, IMG_ADDR, i, j, 2);
/*
				r = IMG_ADDR[(j * 2) * e->img.sizeline + (i * 2) * (e->img.bpp / 8)]
				+ IMG_ADDR[((j * 2) + 1) * e->img.sizeline + (i * 2) * (e->img.bpp / 8)]
				+ IMG_ADDR[(j * 2) * e->img.sizeline + ((i* 2) + 1) * (e->img.bpp / 8)]
				+ IMG_ADDR[((j * 2) + 1) * e->img.sizeline + ((i * 2) + 1) * (e->img.bpp / 8)];

				g = (IMG_ADDR[(j * 2) * e->img.sizeline + (i * 2) * (e->img.bpp / 8) + 1])
				+ (IMG_ADDR[((j * 2) + 1) * e->img.sizeline + (i * 2) * (e->img.bpp / 8) + 1])
				+ (IMG_ADDR[(j * 2) * e->img.sizeline + ((i* 2) + 1) * (e->img.bpp / 8) + 1])
				+ (IMG_ADDR[((j * 2) + 1) * e->img.sizeline + ((i * 2) + 1) * (e->img.bpp / 8) + 1]);

				b = (IMG_ADDR[(j * 2) * e->img.sizeline + (i * 2) * (e->img.bpp / 8) + 2])
				+ (IMG_ADDR[((j * 2) + 1) * e->img.sizeline + (i * 2) * (e->img.bpp / 8) + 2])
				+ (IMG_ADDR[(j * 2) * e->img.sizeline + ((i * 2) + 1) * (e->img.bpp / 8) + 2])
				+ (IMG_ADDR[((j * 2) + 1) * e->img.sizeline + ((i * 2) + 1) * (e->img.bpp / 8) + 2]);
*/
			(j == 250 && i == 451) ? printf("	rgb(%d, %d, %d)\n", r, g, b) : 0;
//			r /= 4;
//			g /= 4;
//			b /= 4;
			img_put_pixel2(&tmp_img, i, j, (r + (g << 8) + (b << 16)));
		}
	}
	VW_WIDTH = IMG_WIDTH / 1000.0;
	VW_HEIGHT = IMG_HEIGHT / 1000.0;
	VW_DIST = 1.0;
	GAP_X = VW_WIDTH / (double)IMG_WIDTH;
	GAP_Y = VW_HEIGHT / (double)IMG_HEIGHT;
	mlx_destroy_image(MLX, IMG);
	e->img = tmp_img;
	mlx_put_image_to_window(MLX, WIN, IMG, IMG_GAP_X, IMG_GAP_Y + 49);
}


