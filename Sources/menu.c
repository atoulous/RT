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
	int				i;
	int				j;
	unsigned int	color;

	j = -1;
	while (++j < WIN_HEIGHT)
	{
		i = -1;
		while (++i < WIN_WIDTH)
		{
			color = (j > 48 && j < WIN_HEIGHT - 131) ? 0x002B333F : 0x003D4D65;
			mlx_pixel_put(MLX, WIN, i, j, color);
		}
	}
}

static void	create_btn(t_env *e, char *btn[NB_BTN])
{
	btn[0] = ft_strdup("Images/top-left.xpm");
	btn[1] = ft_strdup("Images/top-middle.xpm");
	btn[2] = ft_strdup("Images/top-right.xpm");
	btn[3] = ft_strdup("Images/bottom-middle.xpm");
	MENU[0].pos_x = 14;
	MENU[1].pos_x = (WIN_WIDTH / 2) - 65;
	MENU[2].pos_x = WIN_WIDTH - 50;
	MENU[3].pos_x = (WIN_WIDTH / 2) - 268;
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
		MENU[i].pos_y = (i < 3) ? 6 : WIN_HEIGHT - 122;
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
