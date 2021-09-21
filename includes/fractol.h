/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 01:41:57 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/21 12:08:18 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libs.h"

# define MANDELBROT 0
# define JULIA 1
# define BURNINGSHIP 2
# define PERPENDICULAR_BURNINGSHIP 3
# define MANDELBAR 4
# define CELTIC_MANDELBAR 5
# define CELTIC_PERPENDICULAR 6
# define PERPENDICULAR_BUFFALO 7

# define DEFAULT_JULIA_RE -0.70176
# define DEFAULT_JULIA_IM -0.3842

# define COUNT_FRACTALS 8

# define WINDOW_SIZE 500
# define STEP_ITER 5
# define DEFAULT_ITER 20

# define MENU_WIDTH 155
# define MENU_HEIGHT 187

#endif
