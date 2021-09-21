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
	int	i;
	int	j;

	i = -1;
	while (++i < WINDOW_SIZE)
	{
		j = WINDOW_SIZE - 30 - 1;
		while (++j < WINDOW_SIZE)
			my_mlx_pixel_put(&fractol->img, i, j, 0);
	}
	i = -1;
	while (++i < MENU_WIDTH)
	{
		j = -1;
		while (++j < MENU_HEIGHT)
			my_mlx_pixel_put(&fractol->img, i, j, 0);
	}
	mlx_put_image_to_window(fractol->win.mlx, fractol->win.win,
		fractol->img.img, 0, 0);
}

void	print_on_of(t_fractol *fractol, int x, int y, int param)
{
	if (param)
		print_green(fractol, x, y, "(OFF)");
	else
		print(fractol, x, y, "(OFF)");
}

void	draw_instructions(t_fractol *fractol)
{
	print(fractol, 10, 15, "M: MENU");
	print(fractol, 10, 30, "L: LOCK MOUSE");
	print_on_of(fractol, 105, 30, fractol->config.mouse_locked);
	print(fractol, 10, 45, "C: COLORS");
	print(fractol, 10, 60, "F: FRACTALS");
	print(fractol, 10, 75, "R: RESET");
	print(fractol, 10, 90, "Z: MOUSE ITER");
	print_on_of(fractol, 105, 90, fractol->config.miter);
	print(fractol, 10, 105, "P: PSYCHEDELIC");
	print_on_of(fractol, 110, 105, fractol->config.p);
	print(fractol, 10, 120, "MW: ZOOM");
	print(fractol, 10, 135, "M1: JULIA PARAMS");
	print(fractol, 10, 150, "+/-: ITERATIONS");
	print(fractol, 10, 165, "SHIFT: SHIFT COLOR");
	print(fractol, 10, 180, "ESC: QUIT");
}

void	draw_set_name(t_fractol *fractol)
{
	if (fractol->config.fractal == MANDELBROT)
		print(fractol, 10, WINDOW_SIZE - 10, "MANDELBROT");
	else if (fractol->config.fractal == JULIA)
		print(fractol, 10, WINDOW_SIZE - 10, "JULIA");
	else if (fractol->config.fractal == BURNINGSHIP)
		print(fractol, 10, WINDOW_SIZE - 10, "BURNINGSHIP");
	else if (fractol->config.fractal == PERPENDICULAR_BURNINGSHIP)
		print(fractol, 10, WINDOW_SIZE - 10, "PERPENDICULAR BURNINGSHIP");
	else if (fractol->config.fractal == MANDELBAR)
		print(fractol, 10, WINDOW_SIZE - 10, "MANDELBAR");
	else if (fractol->config.fractal == CELTIC_MANDELBAR)
		print(fractol, 10, WINDOW_SIZE - 10, "CELTIC MANDELBAR");
	else if (fractol->config.fractal == CELTIC_PERPENDICULAR)
		print(fractol, 10, WINDOW_SIZE - 10, "CELTIC PERPENDICULAR");
	else if (fractol->config.fractal == PERPENDICULAR_BUFFALO)
		print(fractol, 10, WINDOW_SIZE - 10, "PERPENDICULAR BUFFALO");
}

void	draw_menu(t_fractol *fractol)
{
	char	*strnbr;

	draw_background(fractol);
	draw_instructions(fractol);
	draw_set_name(fractol);
	strnbr = ft_itoa(fractol->config.max_iter);
	print(fractol, WINDOW_SIZE - 200, WINDOW_SIZE - 10, "MAX ITER:");
	print(fractol, WINDOW_SIZE - 135, WINDOW_SIZE - 10, strnbr);
	free(strnbr);
	strnbr = ft_itoa(fractol->config.x);
	print(fractol, WINDOW_SIZE - 100, WINDOW_SIZE - 10, "X:");
	print(fractol, WINDOW_SIZE - 85, WINDOW_SIZE - 10, strnbr);
	free(strnbr);
	strnbr = ft_itoa(fractol->config.y);
	print(fractol, WINDOW_SIZE - 50, WINDOW_SIZE - 10, "Y:");
	print(fractol, WINDOW_SIZE - 35, WINDOW_SIZE - 10, strnbr);
	free(strnbr);
}
