/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:56:18 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/15 18:51:43 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libmlx/my_mlx.h"
#include "Libs/libft/libft.h"

typedef void		(*t_ptr_f)(t_list **, t_list *);
typedef t_list*		(*t_ptr_f2)(void const *, size_t);

typedef struct		s_triple_rgb
{
	t_rgb			ambient;
	t_rgb			diffuse;
	t_rgb			specular;
}					t_triple_rgb;

typedef struct		s_materia
{
	char			*name;
	t_triple_rgb	compo;
	double			shininess;
}					t_materia;

t_triple_rgb		fill_compo(t_rgb ambient, t_rgb diffuse, t_rgb specular)
{
	t_triple_rgb	triple;

	triple.ambient = ambient;
	triple.diffuse = diffuse;
	triple.specular = specular;
	return (triple);
}

t_materia			*new_materia(char *name, t_triple_rgb compo, \
		double shininess)
{
	t_materia		*materia;

	materia = (t_materia *)malloc(sizeof(t_materia));
	materia->name = ft_strdup(name);
	materia->compo = compo;
	materia->shininess = shininess;
	return (materia);
}

t_list				*materia_list(void)
{
	t_list			*l;
	t_ptr_f			f;
	t_ptr_f2		f2;

	f = &ft_lstadd;
	f2 = &ft_lstnew;
	f(&l, f2(new_materia("emerald", fill_compo(rgb_create(0.0215, 0.1745, \
							0.0215), rgb_create(0.07568, 0.61424, 0.07568), \
						rgb_create(0.633, 0.727811, 0.633)), 0.6), \
				sizeof(t_materia)));
	f(&l, f2(new_materia("jade", fill_compo(rgb_create(0.135, 0.2225, \
							0.1575), rgb_create(0.54, 0.89, 0.63), \
						rgb_create(0.316228, 0.316228, 0.316228)), 0.1), \
				sizeof(t_materia)));
	return (l);
}

void				print_tri(t_triple_rgb r)
{
	print_rgb(r.ambient);
	print_rgb(r.diffuse);
	print_rgb(r.specular);
}

void				print_matiere(t_materia *m)
{
	printf("%s\n", m->name);
	print_tri(m->compo);
	printf("shininess = %f\n", m->shininess);
}

void				print_materia_list(t_list **list)
{
	t_list *l;

	l = *list;
	while (l)
	{
		print_matiere(l->content);
		l = l->next;
	}
}

int				main(void)
{
	t_list *l;

	l = materia_list();
	print_materia_list(&l);
	return (0);
}
