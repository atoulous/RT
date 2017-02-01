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
	btn[1] = ft_strdup("Images/top-middle-inv.xpm");
	btn[2] = ft_strdup("Images/top-middle.xpm");
	btn[3] = ft_strdup("Images/top-right.xpm");
	btn[4] = ft_strdup("Images/bottom-middle.xpm");
	btn[5] = ft_strdup("Images/info-img.xpm");
	btn[6] = ft_strdup("Images/info-obj.xpm");
	MENU[0].pos_x = 14;
	MENU[1].pos_x = (WIN_WIDTH / 2) - 65;
	MENU[2].pos_x = (WIN_WIDTH / 2) - 65;
	MENU[3].pos_x = WIN_WIDTH - 50;
	MENU[4].pos_x = (WIN_WIDTH / 2) - 268;
	MENU[5].pos_x = WIN_WIDTH - 234;
	MENU[6].pos_x = WIN_WIDTH - 234;
}

void		change_btn_light(t_env *e)
{
	if (OPT_GQ)
		mlx_put_image_to_window(MLX, WIN, MENU[1].img.img,
												MENU[1].pos_x, MENU[1].pos_y);
	else
		mlx_put_image_to_window(MLX, WIN, MENU[2].img.img,
												MENU[2].pos_x, MENU[2].pos_y);
}

void		menu_object(t_env *e)
{
	int i;
	int j;
	t_object	*obj;
	char		pos[255];

	if (e->scene->obj_focus)
	{
		obj = (t_object *)e->scene->obj_focus->content;
		mlx_put_image_to_window(MLX, WIN, MENU[6].img.img,
						MENU[6].pos_x, MENU[6].pos_y);
		mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 226, 0x8493A8,
											e->obj_allowed[obj->type]);
		sprintf(pos, "(%.1f, %.1f)", obj->pos.x, obj->pos.y);
		mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 450, 0x8493A8, pos);
		sprintf(pos, "%.1f", obj->r1);
		mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 474, 0x8493A8, pos);
		mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 496, 0x8493A8, "Test");
		mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 520, 0x8493A8, "Test");
	}
	else
	{
		j = 185;
		while (j++ < 554)
		{
			i = WIN_WIDTH - 237;
			while (i++ < WIN_WIDTH)
				mlx_pixel_put(MLX, WIN, i, j, 0x002B333F);
		}
	}
}

void		menu_image(t_env *e)
{
	char *width;
	char *height;

	width = ft_itoa(IMG_WIDTH);
	height = ft_itoa(IMG_HEIGHT);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 97, 0x8493A8, e->scene->name);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 118, 0x8493A8, width);
	mlx_string_put(MLX, WIN, WIN_WIDTH - 166, 140, 0x8493A8, height);
	free(width);
	free(height);
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
		MENU[i].pos_y = (i < 4) ? 6 : WIN_HEIGHT - 122;
		MENU[5].pos_y = 62;
		MENU[6].pos_y = 197;
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
	change_btn_light(e);
	menu_image(e);
	menu_object(e);
}
