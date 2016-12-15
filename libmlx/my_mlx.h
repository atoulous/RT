/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:29:41 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/15 18:17:34 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_l
{
	int				x;
	int				y;
}					t_l;

typedef struct		s_mlx
{
	void			*m;
	void			*w;
	void			*i;
	int				sl;
	int				bpp;
	int				e;
	char			*d_a;
}					t_mlx;

typedef struct		s_rgb
{
	double			r;
	double			g;
	double			b;
}					t_rgb;

typedef struct		s_hsv
{
	double			h;
	double			s;
	double			v;
}					t_hsv;

typedef struct		s_chsv
{
	t_hsv			out;
	t_rgb			tmp;
	double			min;
	double			max;
	double			delta;
}					t_chsv;

typedef struct		s_crgb
{
	t_rgb			r;
	long			i;
	double			hh;
	double			p;
	double			q;
	double			t;
	double			ff;
}					t_crgb;

void				put_color_to_pixel(t_mlx *mlx, t_l l, t_rgb rgb);
t_rgb				hsv_to_rgb(t_hsv hsv);
t_hsv				rgb_to_hsv(t_rgb rgb);
t_mlx				*glob_init_mlx(char *n, int w, int h);

t_rgb				rgb_mult(t_rgb a, t_rgb b);
t_rgb				rgb_add(t_rgb a, t_rgb b);
t_rgb				rgb_create(double a, double b, double c);
t_rgb				rgb_0(void);

void				print_rgb(t_rgb r);
#endif
