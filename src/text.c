/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:37:15 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/20 17:40:56 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    draw_background(t_fractol *fractol)
{
    int i;
    int j;

    i = 0;
    while(i < WINDOW_SIZE)
    {
        j = WINDOW_SIZE - 30;
        while(j < WINDOW_SIZE)
        {
            my_mlx_pixel_put(&fractol->img, i, j, 0);
            j++;
        }
        i++;
    }
    i = 0;
    while(i < 110)
    {
        j = 0;
        while(j < 115)
        {
            my_mlx_pixel_put(&fractol->img, i, j, 0);
            j++;
        }
        i++;
    }
	mlx_put_image_to_window(fractol->win.mlx, fractol->win.win, fractol->img.img, 0, 0);
}


void    draw_menu(t_fractol *fractol)
{
    char *strnbr;

    draw_background(fractol);
    strnbr = ft_itoa(fractol->config.max_iter);
    mlx_string_put(fractol->win.mlx, fractol->win.win, 10, WINDOW_SIZE - 10, 0xff0000, "MAX ITERATIONS:");
    mlx_string_put(fractol->win.mlx, fractol->win.win, 105, WINDOW_SIZE - 10, 0xff0000, strnbr);
    free(strnbr);
    strnbr = ft_itoa(fractol->config.x);
    mlx_string_put(fractol->win.mlx, fractol->win.win, 140, WINDOW_SIZE - 10, 0xff0000, "X:");
    mlx_string_put(fractol->win.mlx, fractol->win.win, 155, WINDOW_SIZE - 10, 0xff0000, strnbr);
    free(strnbr);
    strnbr = ft_itoa(fractol->config.y);
    mlx_string_put(fractol->win.mlx, fractol->win.win, 180, WINDOW_SIZE - 10, 0xff0000, "Y:");
    mlx_string_put(fractol->win.mlx, fractol->win.win, 195, WINDOW_SIZE - 10, 0xff0000, strnbr);
    free(strnbr);
    mlx_string_put(fractol->win.mlx, fractol->win.win, 10, 15, 0xff0000, "M: MENU");
    mlx_string_put(fractol->win.mlx, fractol->win.win, 10, 30, 0xff0000, "L: LOCK MOUSE");
    mlx_string_put(fractol->win.mlx, fractol->win.win, 10, 45, 0xff0000, "C: COLORS");
    mlx_string_put(fractol->win.mlx, fractol->win.win, 10, 60, 0xff0000, "F: FRACTALS");
    mlx_string_put(fractol->win.mlx, fractol->win.win, 10, 75, 0xff0000, "R: RESET");
    mlx_string_put(fractol->win.mlx, fractol->win.win, 10, 90, 0xff0000, "+/-: ITERATIONS");
    mlx_string_put(fractol->win.mlx, fractol->win.win, 10, 105, 0xff0000, "M.WHEEL: ZOOM");
    mlx_string_put(fractol->win.mlx, fractol->win.win, 250, WINDOW_SIZE - 10, 0xff0000, "LOCK MOUSE (JULIA):");
    if (fractol->config.mouse_locked == 1)
        mlx_string_put(fractol->win.mlx, fractol->win.win, 370, WINDOW_SIZE - 10, 0x00ff00, "ON");
    else
        mlx_string_put(fractol->win.mlx, fractol->win.win, 370, WINDOW_SIZE - 10, 0xff0000, "OFF");

    if (fractol->config.fractal == MANDELBROT)
        mlx_string_put(fractol->win.mlx, fractol->win.win, WINDOW_SIZE - 80, WINDOW_SIZE - 10, 0xff0000, "MANDELBROT");
    else if (fractol->config.fractal == JULIA)
    {
        mlx_string_put(fractol->win.mlx, fractol->win.win, WINDOW_SIZE - 51, WINDOW_SIZE - 10, 0xff0000, "JULIA");
    }
    else if (fractol->config.fractal == BURNINGSHIP)
        mlx_string_put(fractol->win.mlx, fractol->win.win, WINDOW_SIZE - 86, WINDOW_SIZE - 10, 0xff0000, "BURNINGSHIP");

}