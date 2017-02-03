/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_to_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:25:09 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/02 10:27:00 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

t_rgb		unsigned_to_rgb(unsigned int color)
{
	t_rgb		rgb;

	rgb.b = ((color & 0x00FF0000) >> 16);
	rgb.g = ((color & 0x00FF00) >> 8);
	rgb.r = (color & 0x00FF);
	return (rgb);
}
