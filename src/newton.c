/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:25:39 by nomargen          #+#    #+#             */
/*   Updated: 2022/02/20 14:35:46 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/main.h"

#define NEWTON_ABS_Z_LIM	(10000000.0)
#define NEWTON_ABS_D_LIM	(0.00000001)

int	newton_col_alg(t_complex z)
{
	int	color;
	int	argc;

	argc = tanf(z.i / z.r) / M_PI_2;
	color = 0;
	if (argc == 0)
		color = 0xFF0000;
	else if (argc == 1 || argc == 2)
		color = 0x00FFFF;
	else if (argc == 3 || argc == 4)
		color = 0x0000FF;
	else if (argc == -1 || argc == -2)
		color = 0xFF00FF;
	else if (argc == -3 || argc == -4)
		color = 0x00FF00;
	return (color);
}

void	preset_vars(int *i, t_complex *z, t_complex *d, t_complex pos)
{
	*i = 0;
	z->r = pos.r;
	z->i = pos.i;
	d->r = 1.0;
	d->i = 1.0;
}

int	is_newton(t_config *conf, t_complex pos)
{
	int					i;
	t_complex			z;
	t_complex			d;
	static double		two_thirds = 2.0 / 3.0;
	double				p;

	preset_vars(&i, &z, &d, pos);
	while (i < conf->iter_cnt && (z.r * z.r + z.i * z.i) < NEWTON_ABS_Z_LIM
		&& (d.r * d.r + d.i * d.i) > NEWTON_ABS_D_LIM)
	{
		d.r = z.r;
		d.i = z.i;
		p = ft_sqr(ft_sqr(d.r) + ft_sqr(z.i));
		z.r = two_thirds * d.r + (ft_sqr(d.r)
				- ft_sqr(d.i)) / (3.0 * p);
		z.i = two_thirds * d.i * (1.0 - d.r / p);
		d.r = z.r - d.r;
		d.i = z.i - d.i;
		i++;
	}
	if (conf->col_cntr == 0)
		i = newton_col_alg(z);
	return (i);
}
