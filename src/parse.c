/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:25:39 by nomargen          #+#    #+#             */
/*   Updated: 2022/02/18 17:38:27 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/main.h"

int	is_valid_float(char const *s)
{
	int	max_digits;

	max_digits = 6;
	if (s && *s == '-')
		s++;
	if (!s || !ft_isdigit(*s))
		return (0);
	s++;
	if (*s != '.')
		return (0);
	s++;
	if (!*s)
		return (0);
	while (*s && ft_isdigit(*s) && max_digits)
	{
		s++;
		max_digits--;
	}
	return (*s == '\0');
}

double	parse_float(char const *s)
{
	double	r;
	double	power;
	double	sign;

	r = 1.0f;
	power = 0.1f;
	sign = 1.0f;
	if (*s == '-')
	{
		sign = -1.0f;
		r *= sign;
		s++;
	}
	r *= *s - '0';
	s += 2;
	while (*s)
	{
		r += (*s - '0') * power * sign;
		power *= 0.1f;
		s++;
	}
	return (r);
}

int	parse_param_args(t_config *conf, int argc, char const *argv[])
{
	int	valid;

	if (conf->fr_type == JULIA)
	{
		if (argc == 4)
		{
			valid = is_valid_float(argv[2]);
			valid *= is_valid_float(argv[3]);
			if (valid)
			{
				conf->c_jul.r = parse_float(argv[2]);
				conf->c_jul.i = parse_float(argv[3]);
			}
			else
				return (0);
		}
		else if (argc != 2)
			return (0);
	}
	return (1);
}

int	parse_args(t_config *conf, int argc, char const *argv[])
{
	conf->fr_type = ERR;
	if (argc <= 1 || argv == NULL)
		return (0);
	else
	{
		if (ft_strcmp(argv[1], "M") == 0)
			conf->fr_type = MAND;
		else if (ft_strcmp(argv[1], "N") == 0)
			conf->fr_type = NEWTON;
		else if (ft_strcmp(argv[1], "J") == 0)
		{
			conf->fr_type = JULIA;
			set_c_jul(conf, WIN_W / 2.0f, WIN_H / 2.0f);
			if (parse_param_args(conf, argc, argv) == 0)
				return (0);
		}
		else
			return (0);
	}
	return (1);
}
