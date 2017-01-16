/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_init_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:01:29 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/22 19:25:40 by mmoullec         ###   ########.fr       */
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
