/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_init_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:20:06 by mmoullec          #+#    #+#             */
/*   Updated: 2017/02/05 17:20:12 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

t_mlx		*glob_init_mlx(char *n, int width, int height)
{
	t_mlx	*m;

	m = (t_mlx *)malloc(sizeof(t_mlx));
	m->m = mlx_init();
	m->w = mlx_new_window(m->m, width, height, n);
	m->i = mlx_new_image(m->m, width, height);
	m->d_a = mlx_get_data_addr(m->i, &m->bpp, &m->sl, &m->e);
	return (m);
}
