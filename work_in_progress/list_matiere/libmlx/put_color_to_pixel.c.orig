/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_to_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:27:38 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/22 18:35:09 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

void	put_color_to_pixel(t_mlx *mlx, t_l l, t_rgb rgb)
{
	int		j;

	j = (l.x * 4) + (l.y * mlx->sl);
	mlx->d_a[j] = rgb.b;
	mlx->d_a[++j] = rgb.g;
	mlx->d_a[++j] = rgb.r;
}
