/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:25:39 by nomargen          #+#    #+#             */
/*   Updated: 2022/02/20 15:36:58 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/bonus/main_bonus.h"
#include "../../inc/bonus/keys_bonus.h"

int	mouse_hook(int keycode, int x, int y, t_config *conf)
{
	if (keycode == WHEEL_UP)
		zoom(conf, 1.4, x, y);
	else if (keycode == WHEEL_DOWN)
		zoom(conf, 0.6, x, y);
	else if (keycode == LEFT_CLICK && conf->fr_type == JULIA)
		set_c_jul(conf, x, y);
	conf->change_f++;
	return (0);
}
