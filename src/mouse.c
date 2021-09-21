/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 02:32:29 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/21 08:39:08 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_mousemove(int x, int y, t_fractol *fractol)
{
	fractol->config.x = x;
	fractol->config.y = y;

	if (fractol->config.menu)
		draw_menu(fractol);
	if (!fractol->config.mouse_locked && fractol->config.fractal == JULIA)
	{
		fractol->config.m = get_complex(x, y, fractol);
		draw_fractol(fractol);
	}
	return (0);
}

void	apply_zoom(t_fractol *fractol, int button)
{
	const double zoom_direction_x = (fractol->config.vp_size / 4)
		* ((WINDOW_SIZE / 2) - fractol->config.x) / WINDOW_SIZE / 2;
	const double zoom_direction_y = (fractol->config.vp_size / 4) 
		* ((WINDOW_SIZE / 2) - fractol->config.y) / WINDOW_SIZE / 2;
	double incr_x;
	double incr_y;
	double incr_vp;

	if (button == SCROLLUP)
	{
		incr_x = fractol->config.vp_size * 0.05 - zoom_direction_x;
		incr_y = fractol->config.vp_size * 0.05 - zoom_direction_y;
		incr_vp = 0.9;
		if (fractol->config.p)
			increment_shift(fractol);
		if (fractol->config.miter)
			fractol->config.max_iter++;
	}
	else
	{
		incr_x = -(fractol->config.vp_size * 0.05 + zoom_direction_x);
		incr_y = -(fractol->config.vp_size * 0.05 + zoom_direction_y);
		incr_vp = 1.1;
		if (fractol->config.p)
			decrement_shift(fractol);
		if (fractol->config.miter && fractol->config.max_iter > STEP_ITER)
			fractol->config.max_iter--;
	}
	fractol->config.h_start += incr_x;
	fractol->config.v_start += incr_y;
	fractol->config.vp_size *= incr_vp;
	draw_fractol(fractol);
}


int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == SCROLLUP || button == SCROLLDOWN)
		apply_zoom(fractol, button);
	else if (button == MOUSEL)
	{
		fractol->config.x = x;
		fractol->config.y = y;
		fractol->config.m = get_complex(x, y, fractol);
		draw_fractol(fractol);
	}

	return (0);
}