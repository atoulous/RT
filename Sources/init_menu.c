/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:16:44 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/06 09:11:13 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	get_images(t_env *e)
{
	ME[0].path = ft_strdup("Images/top-left.xpm");
	ME[1].path = ft_strdup("Images/top-middle-inv.xpm");
	ME[2].path = ft_strdup("Images/top-middle.xpm");
	ME[3].path = ft_strdup("Images/top-right.xpm");
	ME[4].path = ft_strdup("Images/bottom-middle.xpm");
	ME[5].path = ft_strdup("Images/info-top.xpm");
	ME[6].path = ft_strdup("Images/color-selector.xpm");
	ME[7].path = ft_strdup("Images/info-mat.xpm");
	ME[8].path = ft_strdup("Images/info-plane.xpm");
	ME[9].path = ft_strdup("Images/info-sphere.xpm");
	ME[10].path = ft_strdup("Images/info-cylinder.xpm");
	ME[11].path = ft_strdup("Images/info-cone.xpm");
	ME[12].path = ft_strdup("Images/info-torus.xpm");
	ME[13].path = ft_strdup("Images/grey.xpm");
	ME[14].path = ft_strdup("Images/grey-inv.xpm");
	ME[15].path = ft_strdup("Images/sepia.xpm");
	ME[16].path = ft_strdup("Images/sepia-inv.xpm");
	ME[17].path = ft_strdup("Images/cartoon.xpm");
	ME[18].path = ft_strdup("Images/cartoon-inv.xpm");
	ME[19].path = ft_strdup("Images/marbre.xpm");
	ME[20].path = ft_strdup("Images/marbre-inv.xpm");
	ME[21].path = ft_strdup("Images/bois.xpm");
	ME[22].path = ft_strdup("Images/bois-inv.xpm");
}

static void	create_interface(t_env *e)
{
	int	i;

	i = -1;
	while (++i < 4)
		ME[i].y = 6;
	ME[4].y = WIN_HEIGHT - 122;
	ME[5].y = 60;
	ME[6].y = 130;
	ME[7].y = 475;
	i = 7;
	while (++i < 13)
		ME[i].y = 306;
	ME[0].x = 15;
	ME[1].x = (WIN_WIDTH / 2) - 65;
	ME[2].x = (WIN_WIDTH / 2) - 65;
	ME[3].x = WIN_WIDTH - 97;
	ME[4].x = (WIN_WIDTH / 2) - 268;
	i = 4;
	while (++i < NB_ME)
		ME[i].x = WIN_WIDTH - 234;
	i = 12;
	while (++i < 19)
		ME[i].x = WIN_WIDTH - 176;
	ME[13].y = 180;
	ME[14].y = 180;
	ME[15].y = 210;
	ME[16].y = 210;
	ME[17].y = 240;
	ME[18].y = 240;
	ME[19].y = 440;
	ME[20].y = 440;
	ME[21].y = 440;
	ME[21].x = WIN_WIDTH - 120;
	ME[22].y = 440;
	ME[22].x = WIN_WIDTH - 120;
	get_images(e);
}

void		init_menu(t_env *e)
{
	int		i;

	back_menu(e);
	create_interface(e);
	i = -1;
	while (++i < NB_ME)
	{
		if (!(ME[i].img.img = mlx_xpm_file_to_image(MLX, ME[i].path,
						&(ME[i].img.width), &(ME[i].img.height))))
			error_perso(e, "Menu image not found");
		ME[i].img.addr = mlx_get_data_addr(ME[i].img.img,
				&(ME[i].img.bpp), &(ME[i].img.sizeline), &ENDIAN);
	}
	i = -1;
	while (++i < NB_ME)
	{
		mlx_put_image_to_window(MLX, WIN, ME[i].img.img, ME[i].x, ME[i].y);
		free(ME[i].path);
	}
	change_btn_light(e);
	menu_image(e);
	menu_object(e);
}
