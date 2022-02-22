/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:50:41 by nomargen          #+#    #+#             */
/*   Updated: 2022/02/20 21:04:18 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef TYPES_BONUS_H
# define TYPES_BONUS_H

typedef enum e_exit{
	EXIT_KEY = 0,
	EXIT_BAD_PARAM,
	EXIT_BAD_INIT
}	t_exit;

typedef enum e_fr_type
{
	ERR = 0,
	MAND,
	JULIA,
	NEWTON
}	t_fr_type;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_palette {
	void	*img;
	int		*addr;
	int		w;
	int		h;
	int		palette_cnt;
	int		map_en;
}	t_palette;

typedef struct s_config
{
	t_fr_type	fr_type;
	t_palette	palette;
	int			col_cntr;
	t_complex	c_jul;
	int			info_en;
	int			iter_cnt;
	double		zoom;
	double		w_bias;
	double		h_bias;
	double		scale_fact;
	t_data		pix_data;
	int			pix_cntr;
	void		*mlx;
	void		*mlx_win;
	int			(*fr_func)(struct s_config *config, t_complex pos);
	int			change_f;
	t_exit		exit;
}	t_config;

#endif