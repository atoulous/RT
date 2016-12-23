/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:16:40 by jubarbie          #+#    #+#             */
/*   Updated: 2016/12/23 18:26:46 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	back_menu(t_env *e)
{
	int	i;
	int	j;

	j = -1;
	while (++j < WIN_HEIGHT)
	{
		i = -1;
		while (++i < 40)
			mlx_pixel_put(MLX, WIN, i, j, 0x00333333);
	}
}

static void	create_btn(t_env *e, char *btn[NB_BTN])
{
	btn[0] = ft_strdup("Images/light.xpm");
	btn[1] = ft_strdup("Images/sphere.xpm");
	btn[2] = ft_strdup("Images/plane.xpm");
	btn[3] = ft_strdup("Images/cone.xpm");
	btn[4] = ft_strdup("Images/cylinder.xpm");
	MENU[0].btn_fct = &change_light_status;
	MENU[1].btn_fct = &add_sphere;
	MENU[2].btn_fct = &add_plane;
	MENU[3].btn_fct = &add_cone;
	MENU[4].btn_fct = &add_cylinder;
}

void		init_menu(t_env *e)
{
	char	*btn[NB_BTN];
	int		i;

	back_menu(e);
	create_btn(e, btn);
	i = -1;
	while (++i < NB_BTN)
	{
		MENU[i].pos_x = 4;
		MENU[i].pos_y = 4 + i * BTN_SIZE + 4 * i;
		MENU[i].width = BTN_SIZE;
		MENU[i].height = BTN_SIZE;
		if (!(MENU[i].img.img = mlx_xpm_file_to_image(MLX, btn[i],
				&(MENU[i].img.width), &(MENU[i].img.height))))
			error_perso(e, "Menu image not found");
		MENU[i].img.addr = mlx_get_data_addr(MENU[i].img.img,
				&(MENU[i].img.bpp), &(MENU[i].img.sizeline), &ENDIAN);
	}
	i = -1;
	while (++i < NB_BTN)
	{
		mlx_put_image_to_window(MLX, WIN, MENU[i].img.img,
												MENU[i].pos_x, MENU[i].pos_y);
		free(btn[i]);
	}
}
