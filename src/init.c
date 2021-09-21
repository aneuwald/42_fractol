/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 02:51:31 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/21 02:00:02 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    set_default_parameters(t_fractol *fractol)
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
	fractol->config.menu = 0;
	fractol->config.color = 0;
	fractol->config.palette = get_palettes();
}

void	set_image(t_fractol *fractol)
{
	fractol->win.mlx = mlx_init();
	fractol->win.win = mlx_new_window(fractol->win.mlx, WINDOW_SIZE, WINDOW_SIZE, "Hello world!");
	fractol->img.img = mlx_new_image(fractol->win.mlx, WINDOW_SIZE, WINDOW_SIZE);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
											&fractol->img.bpp,
											&fractol->img.line_length,
											&fractol->img.endian);
}

void    init(t_fractol *fractol)
{   
	set_default_parameters(fractol);
	set_image(fractol);
	draw_fractol(fractol);
	mlx_do_key_autorepeaton(fractol->win.mlx);
	mlx_hook(fractol->win.win, 2, 1L<<0, key_hook, fractol);
	mlx_mouse_hook(fractol->win.win, mouse_hook, fractol);
	mlx_hook(fractol->win.win, 6, 1L << 6, hook_mousemove, fractol);
	mlx_hook(fractol->win.win, 33, 1L << 17, exit_fractol, fractol);
	mlx_loop(fractol->win.mlx);
}