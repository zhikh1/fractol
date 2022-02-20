/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:22:18 by nomargen          #+#    #+#             */
/*   Updated: 2022/02/20 16:00:32 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/bonus/main_bonus.h"
#include "../../inc/bonus/keys_bonus.h"

void	set_scale_fact(t_config *conf, double new_zoom)
{
	double	win_min_len;

	if (WIN_W < WIN_H)
		win_min_len = WIN_W;
	else
		win_min_len = WIN_H;
	if (new_zoom <= 0)
		new_zoom = 1.0;
	conf->scale_fact = 4.0 / win_min_len / new_zoom;
	conf->zoom = new_zoom;
}

void	set_win_bias(t_config *conf, double x, double y)
{
	conf->w_bias = x;
	conf->h_bias = y;
}

void	zoom(t_config *conf, double zoom, double x, double y)
{
	double	dh;
	double	dw;
	double	old_s;

	old_s = conf->scale_fact;
	set_scale_fact(conf, conf->zoom * zoom);
	dw = x * (conf->scale_fact - old_s);
	dh = y * (conf->scale_fact - old_s);
	set_win_bias(conf, conf->w_bias + dw, conf->h_bias + dh);
}

void	move_pict(int keycode, t_config *conf)
{
	double	dh;
	double	dw;

	dh = 0.0;
	dw = 0.0;
	if (keycode == UP_KEY)
		dh = WIN_H * 0.2 * conf->scale_fact;
	else if (keycode == DOWN_KEY)
		dh = -WIN_H * 0.2 * conf->scale_fact;
	else if (keycode == LEFT_KEY)
		dw = WIN_W * 0.2 * conf->scale_fact;
	else if (keycode == RIGHT_KEY)
		dw = -WIN_W * 0.2 * conf->scale_fact;
	set_win_bias(conf, conf->w_bias + dw, conf->h_bias + dh);
}

void	reset_scale(t_config *conf)
{
	set_scale_fact(conf, 1.0);
	set_win_bias(conf, WIN_W / 2.0 * conf->scale_fact,
		WIN_H / 2.0 * conf->scale_fact);
}
