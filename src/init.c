/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 02:51:31 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/14 10:39:42 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hook_mousemove(int x, int y, t_fractol *fractol)
{
    printf("x: %d\n", x);
    printf("x: %d\n", y);
    draw_circle(fractol, x, y, fractol->config.size);
    (void) fractol;
	return (0);
}

void    init(t_fractol *fractol)
{   
    fractol->config.x = 20;
    fractol->config.y = 20;
    fractol->config.size = 5;
    fractol->win.mlx = mlx_init();
	fractol->win.win = mlx_new_window(fractol->win.mlx, WINDOW_SIZE, WINDOW_SIZE, "Hello world!");
    fractol->img.img = mlx_new_image(fractol->win.mlx , WINDOW_SIZE, WINDOW_SIZE);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
                                            &fractol->img.bpp,
                                            &fractol->img.line_length,
                                            &fractol->img.endian);
    clear_drawing(fractol);
    draw(fractol);
    mlx_do_key_autorepeatoff(fractol->win.mlx);
    mlx_hook(fractol->win.win, 2, 1L<<0, key_hook, fractol);
    mlx_mouse_hook(fractol->win.win, mouse_hook, fractol);
    mlx_hook(fractol->win.win, 6, 1L << 6, hook_mousemove, fractol);
	mlx_loop(fractol->win.mlx);
}