/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:37:30 by nomargen          #+#    #+#             */
/*   Updated: 2022/02/21 22:00:29 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

# include "../../lib/libmlx/mlx.h"
# include "../../lib/libft/libft.h"
# include "../../inc/bonus/types_bonus.h"
# include "../../inc/bonus/defines_bonus.h"
# include <stddef.h>
# include <math.h>

int		close_app(t_config *conf);
void	win_err_handler(void);
void	param_err_handler(void);
void	show_info(t_config *conf, int x, int y);
void	set_c_jul(t_config *conf, double x, double y);
int		jul_col_alg(int i);
int		is_julia(t_config *conf, t_complex pos);
int		keyboard_hook(int keycode, t_config *conf);
int		is_mand(t_config *conf, t_complex pos);
int		mouse_hook(int keycode, int x, int y, t_config *conf);
int		is_newton(t_config *conf, t_complex pos);
void	update_min_max(int *min, int *max, int *pix_addr, t_config *conf);
int		map_i(t_config *conf, int i_dif, int min_i, int i);
void	repaint_with_palette(t_config *conf, int min_i, int max_i);
int		init_palette(t_config *conf);
int		parse_args(t_config *conf, int argc, char const *argv[]);
void	set_scale_fact(t_config *conf, double new_zoom);
void	set_win_bias(t_config *conf, double x, double y);
void	zoom(t_config *conf, double zoom, double x, double y);
void	move_pict(int keycode, t_config *conf);
void	reset_scale(t_config *conf);
void	reset_param(t_config *conf);
void	put_black_sq(int *addr);
double	ft_sqr(double a);
void	put_window(t_config *conf, int min_iter, int max_iter, int *pix_addr);
char	*strcat_en(char *buf, int n);
char	*strcat_i(char *buf, int n);
char	*strcat_fr_type(char *buf, int n);

#endif