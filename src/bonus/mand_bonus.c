/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:25:39 by nomargen          #+#    #+#             */
/*   Updated: 2022/02/20 15:36:43 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/bonus/main_bonus.h"

#define MAND_ABS_Z_LIM	(4.0)

int	mand_col_alg(t_complex z, int i)
{
	char	color[4];
	double	abs_sqr;

	color[0] = 0;
	abs_sqr = (z.r * z.r + z.i * z.i);
	color[2] = 128 * (1.0 - cos(i));
	color[1] = 128 * (1.0 - cos(0.23570226039f * abs_sqr));
	color[3] = 128 * (1.0 - cos(0.12452650612f * abs_sqr));
	return (*(int *)color);
}

int	is_mand(t_config *conf, t_complex pos)
{
	int			i;
	t_complex	c;
	t_complex	z;
	double		zr_zi_buf;

	i = 0;
	c.r = pos.r;
	c.i = pos.i;
	z.r = c.r;
	z.i = c.i;
	while (i < conf->iter_cnt && (z.r * z.r + z.i * z.i) < MAND_ABS_Z_LIM)
	{
		zr_zi_buf = (z.r * z.i);
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = zr_zi_buf * 2.0 + c.i;
		i++;
	}
	if (conf->col_cntr == 0)
		i = mand_col_alg(z, i);
	return (i);
}
