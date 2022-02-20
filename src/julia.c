/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:25:39 by nomargen          #+#    #+#             */
/*   Updated: 2022/02/20 14:37:02 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/main.h"

#define JULIA_ABS_Z_LIM	(4.0)

void	set_c_jul(t_config *conf, double x, double y)
{
	conf->c_jul.r = (x - (WIN_W / 2.0)) / WIN_W * 4.0;
	conf->c_jul.i = (y - (WIN_H / 2.0)) / WIN_H * 4.0;
}

int	jul_col_alg(int i)
{
	char	color[4];

	color[0] = 0;
	color[2] = 128 * (1.0 - cos(i));
	color[1] = 128 * (1.0 - cos(0.23570226039 * (double)i));
	color[3] = 128 * (1.0 - cos(0.12452650612 * (double)i));
	return (*(int *)color);
}

int	is_julia(t_config *conf, t_complex pos)
{			
	int			i;
	t_complex	z;	
	t_complex	c;
	double		zr_zi_buf;

	i = 0;
	z.r = pos.r;
	z.i = pos.i;
	c.r = conf->c_jul.r;
	c.i = conf->c_jul.i;
	while (i < conf->iter_cnt && (z.r * z.r + z.i * z.i) < JULIA_ABS_Z_LIM)
	{
		zr_zi_buf = (z.r * z.i);
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = zr_zi_buf * 2.0 + c.i;
		i++;
	}
	if (conf->col_cntr == 0)
		i = jul_col_alg(i);
	return (i);
}
