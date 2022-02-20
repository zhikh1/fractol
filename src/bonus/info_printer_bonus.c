/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_printer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:25:39 by nomargen          #+#    #+#             */
/*   Updated: 2022/02/20 15:45:12 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/bonus/main_bonus.h"

static int	ft_count_digits(long long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_ltoa(long long n)
{
	int		n_digits;
	int		is_negative;
	int		i;
	char	*result;

	n_digits = ft_count_digits(n);
	is_negative = (n < 0);
	result = malloc(sizeof(char) * (n_digits + is_negative + 1));
	if (!result)
		return (NULL);
	if (is_negative)
		result[0] = '-';
	i = n_digits - 1 + is_negative;
	result[i + 1] = '\0';
	while (i >= is_negative)
	{
		if (is_negative)
			result[i] = -(n % 10) + '0';
		else
			result[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (result);
}

char	*strcat_d(char *buf, double n)
{
	long long	a;
	long long	b;
	char		*str_a;
	char		*str_b;

	if (n < 20000000000000000.0)
	{
		a = n / 1.0f;
		b = (n - (double)a) * 10000000;
		if (n < 0)
			b = -b;
		str_a = ft_ltoa(a);
		str_b = ft_ltoa(b);
		ft_strlcat(buf, str_a, 100);
		ft_strlcat(buf, ".", 100);
		ft_strlcat(buf, str_b, 100);
		free(str_a);
		free(str_b);
	}
	else
		ft_strlcat(buf, "Inf", 100);
	return (buf);
}

void	put_black_sq(int *addr)
{
	int					i;
	static const int	pix_buf_size = WIN_W * WIN_H;

	i = (WIN_H - 80) * WIN_W;
	while (i < pix_buf_size)
	{
		if (i % (int)WIN_W < 200)
			addr[i] = 0;
		i++;
	}
}

void	show_info(t_config *conf, int x, int y)
{
	char	str[100];

	ft_strlcpy(str, "Fractal: ", 100);
	mlx_string_put(conf->mlx, conf->mlx_win, x, y + 0,
		0xFFFFFF, strcat_fr_type(str, conf->fr_type));
	ft_strlcpy(str, "Zoom: ", 100);
	mlx_string_put(conf->mlx, conf->mlx_win, x, y + 15,
		0xFFFFFF, strcat_d(str, conf->zoom));
	ft_strlcpy(str, "Iteration: ", 100);
	mlx_string_put(conf->mlx, conf->mlx_win, x, y + 30,
		0xFFFFFF, strcat_i(str, conf->iter_cnt));
	ft_strlcpy(str, "Palette maping: ", 100);
	mlx_string_put(conf->mlx, conf->mlx_win, x, y + 45,
		0xFFFFFF, strcat_en(str, conf->palette.map_en));
	ft_strlcpy(str, "Color mode: ", 100);
	if (conf->col_cntr)
	{
		ft_strlcat(str, "Palette #", 100);
		strcat_i(str, conf->col_cntr);
	}
	else
		ft_strlcat(str, "Algorithm", 100);
	mlx_string_put(conf->mlx, conf->mlx_win, x, y + 60, 0xFFFFFF, str);
}
