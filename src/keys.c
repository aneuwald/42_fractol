/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 02:32:29 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/21 08:51:46 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_params(t_fractol *fractol)
{
	fractol->config.x = 0;
	fractol->config.y = 0;
	fractol->config.h_start = -2;
	fractol->config.v_start = -2;
	fractol->config.vp_size = 4;
	fractol->config.max_iter = DEFAULT_ITER;
	fractol->config.mouse_locked = 1;
	fractol->config.m.a = DEFAULT_JULIA_RE;
	fractol->config.m.b = DEFAULT_JULIA_IM;
	fractol->config.shift = 0;
	fractol->config.p = 0;
	fractol->config.miter = 0;
}

void	change_fractals(t_fractol *fractol)
{
	reset_params(fractol);
	fractol->config.fractal = (fractol->config.fractal + 1) % COUNT_FRACTALS;
}

void	move(t_fractol *fractol, int keycode)
{
	if (keycode == UP || keycode == W)
		fractol->config.v_start -= fractol->config.vp_size * 0.05;
	else if (keycode == DOWN || keycode == S)
		fractol->config.v_start += fractol->config.vp_size * 0.05;
	else if (keycode == LEFT || keycode == A)
		fractol->config.h_start -= fractol->config.vp_size * 0.05;
	else if (keycode == RIGHT || keycode == D)
		fractol->config.h_start += fractol->config.vp_size * 0.05;
	else if (keycode == PLUS)
	{
		fractol->config.max_iter += STEP_ITER;
		increment_shift(fractol);
	}
	else if (keycode == MINUS && fractol->config.max_iter > STEP_ITER)
	{
		fractol->config.max_iter -= STEP_ITER;
		decrement_shift(fractol);
	}
}

int	key_hook(int keycode, t_fractol *fractol)
{
	const int	count_color = fractol->config.palette
			[fractol->config.color].count;

	move(fractol, keycode);
	if (keycode == M)
		fractol->config.menu = !fractol->config.menu;
	else if (keycode == L)
		fractol->config.mouse_locked = !fractol->config.mouse_locked;
	else if (keycode == C)
		fractol->config.color = (fractol->config.color + 1) % 5;
	else if (keycode == SHIFT)
		fractol->config.shift = (fractol->config.shift + 1) % count_color;
	else if (keycode == P)
		fractol->config.p = !fractol->config.p;
	else if (keycode == Z)
		fractol->config.miter = !fractol->config.miter;
	else if (keycode == F)
		change_fractals(fractol);
	else if (keycode == R)
		reset_params(fractol);
	else if (keycode == ESC)
		exit_fractol(fractol);
	draw_fractol(fractol);
	return (0);
}
