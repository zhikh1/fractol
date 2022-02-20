/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:25:07 by nomargen          #+#    #+#             */
/*   Updated: 2022/02/20 10:07:03 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/main.h"

void	update_min_max(int *min, int *max, int *pix_addr, t_config *conf)
{
	if (min && max && conf->palette.map_en)
	{
		if (pix_addr[conf->pix_cntr] != conf->iter_cnt)
		{				
			if (*max < pix_addr[conf->pix_cntr])
				*max = pix_addr[conf->pix_cntr];
			if (*min > pix_addr[conf->pix_cntr])
				*min = pix_addr[conf->pix_cntr];
		}
	}
}

int	map_i(t_config *conf, int i_dif, int min_i, int i)
{
	int	new_i;

	new_i = (double)conf->palette.w / (double)i_dif * (double)((i - min_i));
	return (new_i);
}

void	repaint_with_palette(t_config *conf, int min_i, int max_i)
{
	int					*addr;
	static const int	size = WIN_W * WIN_H;
	int					i_dif;
	int					pix_cntr;

	pix_cntr = 0;
	if (conf->palette.map_en)
		i_dif = max_i - min_i + 1;
	else
	{
		i_dif = conf->iter_cnt;
		min_i = 0;
	}
	addr = (int *)(conf->pix_data.addr);
	while (pix_cntr < size)
	{
		if (addr[pix_cntr] != conf->iter_cnt)
			addr[pix_cntr] = conf->palette.addr[(conf->col_cntr - 1)
				* conf->palette.w + map_i(conf, i_dif, min_i, addr[pix_cntr])];
		else if (addr[pix_cntr] == conf->iter_cnt)
			addr[pix_cntr] = 0;
		pix_cntr++;
	}
}

int	init_palette(t_config *conf)
{
	int	bpp;
	int	ll;
	int	endn;

	conf->palette.img = mlx_xpm_file_to_image(conf->mlx,
			PALETTE_DIR, &conf->palette.w, &conf->palette.h);
	conf->palette.map_en = INIT_MAP_EN;
	conf->col_cntr = INIT_COLOR;
	if (conf->palette.img)
	{
		conf->palette.addr = (int *)mlx_get_data_addr(conf->palette.img,
				&bpp, &ll, &endn);
		if (conf->palette.addr)
		{
			if (conf->palette.h < 10)
				conf->palette.palette_cnt = conf->palette.h;
			else
				conf->palette.palette_cnt = 9;
			if (conf->col_cntr > conf->palette.palette_cnt)
				conf->col_cntr = conf->palette.palette_cnt;
			return (1);
		}
	}
	return (0);
}
