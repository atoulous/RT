/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 13:01:24 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/05 19:56:10 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Save the color in the pixel (x, y) of the image given
*/

void		img_put_pixel2(t_img *img, int x, int y, int color)
{
	char	*addr;

	addr = img->addr;
	addr[y * img->sizeline + x * (img->bpp / 8)] = (color & 0xFF) ;
	addr[y * img->sizeline + x * (img->bpp / 8) + 1] = ((color & 0xFF00) >> 8) ;
	addr[y * img->sizeline + x * (img->bpp / 8) + 2] = ((color & 0xFF0000) >> 16);
}


int			create_img_anti(t_env *e)
{
	int			i;
	int			j;
	pthread_t	th[NB_TH];
	t_img		tmp_img;
	t_img		anti_img;
	int			color;
	float		r;
	float		g;
	float		b;

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
			r = (char)IMG_ADDR[j * 2 * e->img.sizeline + i * 2 * (e->img.bpp / 8)]
			+ (char)IMG_ADDR[(j * 2 + 1) * e->img.sizeline + i * 2 * (e->img.bpp / 8)]
			+ (char)IMG_ADDR[j * 2 * e->img.sizeline + (i* 2 + 1) * (e->img.bpp / 8)]
			+ (char)IMG_ADDR[(j * 2 + 1) * e->img.sizeline + (i * 2 + 1) * (e->img.bpp / 8)];

			g = (char)(IMG_ADDR[j * 2 * e->img.sizeline + i * 2 * (e->img.bpp / 8) + 1])
			+ (char)(IMG_ADDR[(j * 2 + 1) * e->img.sizeline + i * 2 * (e->img.bpp / 8) + 1])
			+ (char)(IMG_ADDR[j * 2 * e->img.sizeline + (i* 2 + 1) * (e->img.bpp / 8) + 1])
			+ (char)(IMG_ADDR[(j * 2 + 1) * e->img.sizeline + (i * 2 + 1) * (e->img.bpp / 8) + 1]);

			b = (char)(IMG_ADDR[j * 2 * e->img.sizeline + i * 2 * (e->img.bpp / 8) + 2])
			+ (char)(IMG_ADDR[(j * 2 + 1) * e->img.sizeline + i * 2 * (e->img.bpp / 8) + 2])
			+ (char)(IMG_ADDR[j * 2 * e->img.sizeline + (i * 2 + 1) * (e->img.bpp / 8) + 2])
			+ (char)(IMG_ADDR[(j * 2 + 1) * e->img.sizeline + (i * 2 + 1) * (e->img.bpp / 8) + 2]);
			r /= 4.0;
			b /= 4.0;
			g /= 4.0;
			//color = IMG_ADDR[j * 2 * e->img.sizeline + i * 2 * (e->img.bpp / 8)];
			//color += (IMG_ADDR[j * 2 * e->img.sizeline + i * 2 * (e->img.bpp / 8) + 1] << 8);
			//color += (IMG_ADDR[j * 2 * e->img.sizeline + i * 2 * (e->img.bpp / 8) + 2] << 16);
			img_put_pixel2(&tmp_img, i, j, ((int)r + ((int)g << 8) + ((int)b << 16)));
		}
	}
	VW_WIDTH = IMG_WIDTH / 1000.0;
	VW_HEIGHT = IMG_HEIGHT / 1000.0;
	VW_DIST = 1.0;
	GAP_X = VW_WIDTH / (double)IMG_WIDTH;
	GAP_Y = VW_HEIGHT / (double)IMG_HEIGHT;
	e->img = tmp_img;
	mlx_put_image_to_window(MLX, WIN, IMG, IMG_GAP_X, IMG_GAP_Y + 49);
	return (0);
}



/*
** Calling the raytracer function for each thread
** Display the image on the window
*/

int			create_img(t_env *e)
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
	mlx_put_image_to_window(MLX, WIN, IMG, IMG_GAP_X, IMG_GAP_Y + 49);
	return (0);
}

/*
** Save the color in the pixel (x, y) of the image given
*/

void		img_put_pixel(t_img *img, int x, int y, t_param *param)
{
	t_env	*e;
	char	*addr;

	e = ENV;
	addr = img->addr;
	if (IS_SEPIA)
		sepia_filter(param);
	else if (IS_GREY)
		grey_filter(param);
	addr[y * img->sizeline + x * (img->bpp / 8)] = fmin(F_COLOR.r, 255.0);
	addr[y * img->sizeline + x * (img->bpp / 8) + 1] = fmin(F_COLOR.g, 255.0);
	addr[y * img->sizeline + x * (img->bpp / 8) + 2] = fmin(F_COLOR.b, 255.0);
	if (IS_MOTION_BLUR)
		img->addr[y * img->sizeline + x * (img->bpp / 8) + 3] = 150;
	else
		img->addr[y * img->sizeline + x * (img->bpp / 8) + 3] = 0;
}

int			main(int ac, char **av)
{
	t_env	*e;
	int		opt;
	int		i;

	if (ac - (i = get_options(ac, av, &opt)) <= 1)
		error_usage();
	e = init_env(av[i + 1], opt);
	create_img_anti(e);
	mlx_loop_hook(MLX, moves, e);
	mlx_hook(WIN, 17, Button1MotionMask, quit_rt, e);
	mlx_hook(WIN, KeyPress, KeyPressMask, ft_key_press, e);
	mlx_hook(WIN, KeyRelease, KeyReleaseMask, ft_key_release, e);
	mlx_hook(WIN, ButtonPress, ButtonPressMask, ft_mouse_click, e);
	mlx_loop(MLX);
	return (0);
}
