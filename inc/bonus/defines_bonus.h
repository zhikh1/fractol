/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:47:31 by nomargen          #+#    #+#             */
/*   Updated: 2022/02/20 15:37:42 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DEFINES_BONUS_H
# define DEFINES_BONUS_H

# define WIN_H			(720.0f)
# define WIN_W			(1280.0f)
# define INIT_ITER		(256)
# define INIT_COLOR		(1)
# define INIT_MAP_EN		(1)
# define PARAM_INFO_MSG	("\
Usage: ./fract-ol [M | J | N]\n\n\
You can also pass real and imaginary parts of 'c' constant for Julia fractal:\n\
./fract-ol J -0.52 0.52\n\
They have to be floating point numbers between -10.0 and 10.0 (not inclusive)\n\
")
# define KEY_INFO_MSG		("\
Controls:\n\
Wheel up/down...to change zoom;\n\
Arrows..........to navigate;\n\
M, N, J.........to choose fractal type;\n\
R...............to reset scale parameters;\n\
I...............to hide/show info;\n\
G...............to toggle palette maping;\n\
0...............to set \"algorithm\" color type;\n\
1-9.............to set \"palette\" color type and palette num;\n\
+/-.............to change iteration count;\n\
Also you can add your own palettes in palette.xpm file.\n\
")
# define PALETTE_DIR		("palettes/palette.xpm")

#endif