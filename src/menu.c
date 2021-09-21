/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:37:15 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/21 12:14:32 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_background(t_fractol *fractol)
{
	int i;
	int j;

	i = -1;
	while(++i < WINDOW_SIZE)
	{
		j = WINDOW_SIZE - 30 - 1;
		while(++j < WINDOW_SIZE)
			my_mlx_pixel_put(&fractol->img, i, j, 0);
	}
	i = -1;
	while(++i < MENU_WIDTH)
	{
		j = -1;
		while(++j < MENU_HEIGHT)
			my_mlx_pixel_put(&fractol->img, i, j, 0);
	}
	mlx_put_image_to_window(fractol->win.mlx, fractol->win.win, fractol->img.img, 0, 0);
}

void	print_on_of(t_fractol *fractol, int x, int y, int param)
{
	if (param)
		print(fractol, x, y, 0x00ff00, "ON");
	else
		print(fractol, x, y, 0xff0000, "OFF");
}

void    draw_instructions(t_fractol *fractol)
{
	print(fractol, 10, 15, 0xff0000, "M: MENU");
	print(fractol, 10, 30, 0xff0000, "L: LOCK MOUSE");
	print_on_of(fractol, 95, 30, fractol->config.mouse_locked);
	print(fractol, 10, 45, 0xff0000, "C: COLORS");
	print(fractol, 10, 60, 0xff0000, "F: FRACTALS");
	print(fractol, 10, 75, 0xff0000, "R: RESET");
	print(fractol, 10, 90, 0xff0000, "Z: MOUSE ITER");
	print_on_of(fractol, 95, 90, fractol->config.miter);
	print(fractol, 10, 105, 0xff0000, "P: PSYCHEDELIC");
	print_on_of(fractol, 100, 105, fractol->config.p);
	print(fractol, 10, 120, 0xff0000, "MW: ZOOM");
	print(fractol, 10, 135, 0xff0000, "M1: JULIA PARAMS");
	print(fractol, 10, 150, 0xff0000, "+/-: ITERATIONS");
	print(fractol, 10, 165, 0xff0000, "SHIFT: SHIFT COLOR");
	print(fractol, 10, 180, 0xff0000, "ESC: QUIT");
}

void    draw_set_name(t_fractol *fractol)
{
	if (fractol->config.fractal == MANDELBROT)
		print(fractol, WINDOW_SIZE - 80, WINDOW_SIZE - 10, 0xff0000, "MANDELBROT");
	else if (fractol->config.fractal == JULIA)
		print(fractol, WINDOW_SIZE - 51, WINDOW_SIZE - 10, 0xff0000, "JULIA");
	else if (fractol->config.fractal == BURNINGSHIP)
		print(fractol, WINDOW_SIZE - 86, WINDOW_SIZE - 10, 0xff0000, "BURNINGSHIP");
	else if (fractol->config.fractal == PERPENDICULAR_BURNINGSHIP)
		print(fractol, WINDOW_SIZE - 170, WINDOW_SIZE - 10, 0xff0000, "PERPENDICULAR BURNINGSHIP");
	else if (fractol->config.fractal == MANDELBAR)
		print(fractol, WINDOW_SIZE - 74, WINDOW_SIZE - 10, 0xff0000, "MANDELBAR");
	else if (fractol->config.fractal == CELTIC_MANDELBAR)
		print(fractol, WINDOW_SIZE - 116, WINDOW_SIZE - 10, 0xff0000, "CELTIC MANDELBAR");
	else if (fractol->config.fractal == CELTIC_PERPENDICULAR)
		print(fractol, WINDOW_SIZE - 140, WINDOW_SIZE - 10, 0xff0000, "CELTIC PERPENDICULAR");
	else if (fractol->config.fractal == PERPENDICULAR_BUFFALO)
		print(fractol, WINDOW_SIZE - 146, WINDOW_SIZE - 10, 0xff0000, "PERPENDICULAR BUFFALO");
}

void    draw_menu(t_fractol *fractol)
{
	char *strnbr;

	draw_background(fractol);
	draw_instructions(fractol);
	draw_set_name(fractol);
	strnbr = ft_itoa(fractol->config.max_iter);
	print(fractol, 10, WINDOW_SIZE - 10, 0xff0000, "MAX ITERATIONS:");
	print(fractol, 105, WINDOW_SIZE - 10, 0xff0000, strnbr);
	free(strnbr);
	strnbr = ft_itoa(fractol->config.x);
	print(fractol, 140, WINDOW_SIZE - 10, 0xff0000, "X:");
	print(fractol, 155, WINDOW_SIZE - 10, 0xff0000, strnbr);
	free(strnbr);
	strnbr = ft_itoa(fractol->config.y);
	print(fractol, 180, WINDOW_SIZE - 10, 0xff0000, "Y:");
	print(fractol, 195, WINDOW_SIZE - 10, 0xff0000, strnbr);
	free(strnbr);
}