/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 02:51:31 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/15 18:18:46 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init(t_fractol *fractol)
{   
    fractol->config.x = 20;
    fractol->config.y = 20;
    fractol->config.size = 5;
	fractol->config.h_start = -2;
	fractol->config.v_start = -2;
	fractol->config.vp_size = 4;
	fractol->config.max_iter = 300;

    fractol->win.mlx = mlx_init();
	fractol->win.win = mlx_new_window(fractol->win.mlx, WINDOW_SIZE, WINDOW_SIZE, "Hello world!");
    fractol->img.img = mlx_new_image(fractol->win.mlx , WINDOW_SIZE, WINDOW_SIZE);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
                                            &fractol->img.bpp,
                                            &fractol->img.line_length,
                                            &fractol->img.endian);
    clear_drawing(fractol);
    draw_fractol(fractol);
    mlx_do_key_autorepeaton(fractol->win.mlx);
    mlx_hook(fractol->win.win, 2, 1L<<0, key_hook, fractol);
    mlx_mouse_hook(fractol->win.win, mouse_hook, fractol);
    //mlx_hook(fractol->win.win, 6, 1L << 6, hook_mousemove, fractol);
	mlx_loop(fractol->win.mlx);
}