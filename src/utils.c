/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:59:45 by nomargen          #+#    #+#             */
/*   Updated: 2022/02/20 10:13:19 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/main.h"

double	ft_sqr(double a)
{
	return (a * a);
}

void	put_window(t_config *conf, int min_iter, int max_iter, int *pix_addr)
{
	if (conf->col_cntr != 0)
		repaint_with_palette(conf, min_iter, max_iter);
	if (conf->info_en)
		put_black_sq(pix_addr);
	mlx_put_image_to_window(conf->mlx,
		conf->mlx_win, conf->pix_data.img, 0, 0);
	if (conf->info_en)
		show_info(conf, 1, WIN_H - 65);
	conf->change_f--;
}

char	*strcat_en(char *buf, int n)
{
	if (n == 0)
		ft_strlcat(buf, "Disable", 100);
	else
		ft_strlcat(buf, "Enable", 100);
	return (buf);
}

char	*strcat_i(char *buf, int n)
{
	char	*a;

	a = ft_itoa(n);
	ft_strlcat(buf, a, 100);
	free(a);
	return (buf);
}

char	*strcat_fr_type(char *buf, int n)
{
	if (n == ERR)
		ft_strlcat(buf, "Error", 100);
	else if (n == NEWTON)
		ft_strlcat(buf, "Newton", 100);
	else if (n == JULIA)
		ft_strlcat(buf, "Julia", 100);
	else if (n == MAND)
		ft_strlcat(buf, "Mandelbrot", 100);
	return (buf);
}
