/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 02:32:29 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/21 02:32:36 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    change_fractals(t_fractol *fractol)
{
	fractol->config.h_start = -2;
	fractol->config.v_start = -2;
	fractol->config.vp_size = 4;
	fractol->config.max_iter = DEFAULT_ITER;
	fractol->config.m.a = -0.70176;
	fractol->config.m.b = -0.3842;
	fractol->config.fractal = (fractol->config.fractal + 1) % COUNT_FRACTALS;
}

void    reset_params(t_fractol *fractol)
{
	fractol->config.x = 0;
	fractol->config.y = 0;
	fractol->config.h_start = -2;
	fractol->config.v_start = -2;
	fractol->config.vp_size = 4;
	fractol->config.max_iter = DEFAULT_ITER;
	fractol->config.mouse_locked = 1;
	fractol->config.m.a = -0.70176;
	fractol->config.m.b = -0.3842;
}

int	key_hook(int keycode, t_fractol *fractol)
{
	// printf("key: %d\n", keycode);
	if (keycode == UP || keycode == W)
		fractol->config.v_start -= fractol->config.vp_size * 0.05;
	else if (keycode == DOWN || keycode == S)
		fractol->config.v_start += fractol->config.vp_size * 0.05;
	else if (keycode == LEFT || keycode == A)
		fractol->config.h_start -= fractol->config.vp_size * 0.05;
	else if (keycode == RIGHT || keycode == D)
		fractol->config.h_start += fractol->config.vp_size * 0.05;
	else if (keycode == PLUS)
		fractol->config.max_iter += STEP_ITER;
	else if (keycode == MINUS && fractol->config.max_iter > STEP_ITER)
		fractol->config.max_iter -= STEP_ITER;	
	else if (keycode == M)
		fractol->config.menu = !fractol->config.menu;
	else if (keycode == L)
		fractol->config.mouse_locked = !fractol->config.mouse_locked;   
	else if (keycode == C)
		fractol->config.color = (fractol->config.color + 1) % 4;
	else if (keycode == F)
		change_fractals(fractol);
	else if (keycode == R)
		reset_params(fractol);
	else if (keycode == ESC)
		exit_fractol(fractol);
	draw_fractol(fractol);
	
	return (0);
}
