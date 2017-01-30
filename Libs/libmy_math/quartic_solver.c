/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartic_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:32:24 by mmoullec          #+#    #+#             */
/*   Updated: 2017/01/16 14:23:26 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_math.h"

static void				find_new_sol(t_5pow d, t_4pow *a, t_4pow *new_a)
{
	a->q3 = d.q3 / d.q4;
	a->q2 = d.q2 / d.q4;
	a->q1 = d.q1 / d.q4;
	a->q0 = d.q0 / d.q4;
	new_a->q3 = 1.0;
	new_a->q2 = -a->q2;
	new_a->q1 = (a->q1 * a->q3 - 4.0 * a->q0);
	new_a->q0 = 4.0 * a->q0 * a->q2 - carre(a->q1) - a->q0 * carre(a->q3);
}

static int				solveur_part_1(t_quartic_sol *sol)
{
	if (sol->ret3 != 0.0)
	{
		sol->f1 = 0.75 * carre(A.q3) - sol->ret2 - 2.0 * A.q2;
		sol->f2 = 0.25 * (4.0 * A.q3 * A.q2 - 8.0 *
				A.q1 - cube(A.q3)) / sol->ret3;
		R4 = sol->f1 + sol->f2;
		sol->ret5 = sol->f1 - sol->f2;
	}
	else
	{
		sol->f1 = 0.75 * A.q3 * A.q3 - 2.0 * A.q2;
		sol->f2 = 2.0 * sqrt(carre(sol->ret1) - 4.0 * A.q0);
		R4 = sol->f1 + sol->f2;
		sol->ret5 = sol->f1 - sol->f2;
	}
	return (1);
}

static int				solveur_part_2(t_quartic_sol *sol)
{
	if (R4 >= 0.0)
	{
		R6 = sqrt(R4);
		sol->r.q1 = -0.25 * A.q3 + 0.5 * sol->ret3 - 0.5 * R6;
		sol->r.q2 = -0.25 * A.q3 + 0.5 * sol->ret3 + 0.5 * R6;
		AL = 2;
	}
	else
	{
		sol->r.q1 = -0.25 * A.q3 + 0.5 * sol->ret3;
		sol->r.q2 = sol->r.q1;
		AL = 0;
	}
	return (1);
}

static int				return_quartic(double *ret, t_quartic_sol sol)
{
	int i;

	i = 0;
	if (sol.alpha != 0)
	{
		ret[i++] = sol.r.q1;
		ret[i++] = sol.r.q2;
	}
	if (sol.beta != 0)
	{
		ret[i++] = sol.r.q3;
		ret[i++] = sol.r.q4;
	}
	return (sol.alpha + sol.beta);
}

int						quartic_solver(double *ret, t_5pow d)
{
	t_quartic_sol	sol;

	find_new_sol(d, &sol.a, &sol.new_a);
	cubic_equation(sol.new_a, &sol.x, &sol.nbr);
	if (sol.nbr == 1)
		R = sol.x.q1;
	else
		R = (sol.x.q1 > sol.x.q3) ? sol.x.q1 : sol.x.q3;
	R2 = 0.25 * carre(sol.a.q3) + R - sol.a.q2;
	R3 = (sol.ret2 > 0.0) ? sqrt(R2) : 0.0;
	sol.useless = solveur_part_1(&sol) + solveur_part_2(&sol);
	if (R5 >= 0.0)
	{
		R7 = sqrt(R5);
		sol.r.q3 = -0.25 * sol.a.q3 - 0.5 * R3 - 0.5 * R7;
		sol.r.q4 = -0.25 * sol.a.q3 - 0.5 * R3 + 0.5 * R7;
		sol.beta = 2;
	}
	else
	{
		sol.r.q3 = -0.25 * sol.a.q3 - 0.5 * R3;
		sol.r.q4 = sol.r.q3;
		sol.beta = 0;
	}
	return (return_quartic(ret, sol));
}
