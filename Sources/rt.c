/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 13:01:24 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/03 16:23:59 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	menu_object(e);
	return (0);
}

/*
** Save the color in the pixel (x, y) of the image given
*/

void		img_put_pixel(t_img *img, int x, int y, t_rgb color)
{
	img->addr[y * img->sizeline + x * (img->bpp / 8)] = fmin(color.r, 255.0);
	img->addr[y * img->sizeline + x * (img->bpp / 8) + 1] = fmin(color.g, 255.0);
	img->addr[y * img->sizeline + x * (img->bpp / 8) + 2] = fmin(color.b, 255.0);
}

int			main(int ac, char **av)
{
	t_env	*e;
	char	opt;
	int		i;

	if (ac - (i = get_options(ac, av, &opt)) <= 1)
		error_usage();
	e = init_env(av[i + 1], opt);
	create_img(e);
	mlx_loop_hook(MLX, moves, e);
	mlx_hook(WIN, 17, Button1MotionMask, quit_rt, e);
	mlx_hook(WIN, KeyPress, KeyPressMask, ft_key_press, e);
	mlx_hook(WIN, KeyRelease, KeyReleaseMask, ft_key_release, e);
	mlx_hook(WIN, ButtonPress, ButtonPressMask, ft_mouse_click, e);
	mlx_loop(MLX);
	return (0);
}
