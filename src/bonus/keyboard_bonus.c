/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:25:39 by nomargen          #+#    #+#             */
/*   Updated: 2022/02/20 15:37:39 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/bonus/main_bonus.h"
#include "../../inc/bonus/keys_bonus.h"

void	navigate_if(int keycode, t_config *conf)
{
	if (keycode == ESC_KEY)
		close_app(EXIT_KEY, conf);
	else if (keycode >= LEFT_KEY && keycode <= DOWN_KEY)
		move_pict(keycode, conf);
	else if (keycode == R_KEY)
		reset_scale(conf);
	else if (keycode == M_KEY)
	{
		conf->fr_type = MAND;
		reset_param(conf);
	}
	else if (keycode == J_KEY)
	{
		conf->fr_type = JULIA;
		reset_param(conf);
	}
	else if (keycode == N_KEY)
	{
		conf->fr_type = NEWTON;
		reset_param(conf);
	}
}

int	keyboard_hook(int keycode, t_config *conf)
{
	if (keycode >= N0_KEY && keycode <= N9_KEY)
		conf->col_cntr = keycode - N0_KEY;
	else if (keycode == I_KEY)
		conf->info_en = !conf->info_en;
	else if (keycode == G_KEY)
		conf->palette.map_en = !conf->palette.map_en;
	else if (keycode == PLUS_KEY)
		conf->iter_cnt *= 2;
	else if (keycode == MINUS_KEY)
		conf->iter_cnt /= 2;
	else
		navigate_if(keycode, conf);
	if (conf->iter_cnt == 0)
		conf->iter_cnt = 1;
	if (conf->col_cntr > conf->palette.palette_cnt)
		conf->col_cntr = conf->palette.palette_cnt;
	conf->change_f++;
	return (0);
}
