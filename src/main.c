/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:24:58 by nomargen          #+#    #+#             */
/*   Updated: 2022/02/20 15:02:18 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/main.h"

int	close_app(t_exit param, t_config *conf)
{
	if (param == EXIT_KEY)
		ft_putstr_fd("Closing app...\n", 1);
	else if (param == EXIT_BAD_INIT)
		ft_putstr_fd("Bad init!\n", 1);
	else if (param == EXIT_BAD_PARAM)
	{
		ft_putstr_fd("Bad param!\n", 1);
		ft_putstr_fd(PARAM_INFO_MSG, 1);
	}
	if (param == EXIT_KEY)
	{
		mlx_destroy_image(conf->mlx, conf->pix_data.img);
		mlx_destroy_image(conf->mlx, conf->palette.img);
		exit(0);
	}
	else
		exit(-1);
	return (0);
}

int	render_frame(t_config *conf)
{
	int					*pix_addr;
	t_complex			pos;
	int					min_iter;
	int					max_iter;
	static const int	pix_buf_size = WIN_W * WIN_H;

	min_iter = conf->iter_cnt;
	max_iter = 0;
	if (conf->change_f > 0)
	{
		pix_addr = (int *)(conf->pix_data.addr);
		conf->pix_cntr = 0;
		while (conf->pix_cntr < pix_buf_size)
		{
			pos.r = (conf->pix_cntr % (int)WIN_W)
				* conf->scale_fact - conf->w_bias;
			pos.i = (conf->pix_cntr / (int)WIN_W)
				* conf->scale_fact - conf->h_bias;
			pix_addr[conf->pix_cntr] = conf->fr_func(conf, pos);
			update_min_max(&min_iter, &max_iter, pix_addr, conf);
			conf->pix_cntr++;
		}
		put_window(conf, min_iter, max_iter, pix_addr);
	}
	return (1);
}

void	reset_param(t_config *conf)
{
	if (conf->fr_type == ERR)
		close_app(EXIT_BAD_INIT, conf);
	else if (conf->fr_type == MAND)
		conf->fr_func = is_mand;
	else if (conf->fr_type == JULIA)
	{
		if (conf->fr_func)
			set_c_jul(conf, WIN_W / 2.0f, WIN_H / 2.0f);
		conf->fr_func = is_julia;
	}
	else if (conf->fr_type == NEWTON)
		conf->fr_func = is_newton;
	conf->info_en = 1;
	conf->iter_cnt = INIT_ITER;
	reset_scale(conf);
}

int	init_win(t_config *conf)
{
	t_data	*pix_data;

	pix_data = &conf->pix_data;
	conf->mlx = mlx_init();
	conf->zoom = 1.0f;
	if (conf->mlx == NULL)
		return (0);
	conf->mlx_win = mlx_new_window(conf->mlx, WIN_W, WIN_H, "fractol");
	pix_data->img = mlx_new_image(conf->mlx, WIN_W, WIN_H);
	if (pix_data->img == NULL)
		return (0);
	pix_data->addr = mlx_get_data_addr(pix_data->img, &pix_data->bits_per_pixel,
			&pix_data->line_length, &pix_data->endian);
	if (pix_data->addr == NULL)
		return (0);
	conf->fr_func = NULL;
	reset_param(conf);
	if (init_palette(conf) == 0)
		return (0);
	conf->change_f = 1;
	mlx_loop_hook(conf->mlx, render_frame, conf);
	mlx_mouse_hook(conf->mlx_win, mouse_hook, conf);
	mlx_hook(conf->mlx_win, 17, (1L << 2), close_app, EXIT_KEY);
	mlx_key_hook(conf->mlx_win, keyboard_hook, conf);
	return (1);
}

int	main(int argc, char const *argv[])
{
	t_config	conf;

	if (parse_args(&conf, argc, argv))
	{
		if (init_win(&conf))
		{
			ft_putstr_fd(KEY_INFO_MSG, 1);
			mlx_loop(conf.mlx);
		}
		else
			close_app(EXIT_BAD_INIT, &conf);
	}	
	else
		close_app(EXIT_BAD_PARAM, &conf);
	return (0);
}
