/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:59:33 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/21 08:30:04 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fractol(t_fractol *fractol)
{
	if (fractol && fractol->win.win)
		mlx_destroy_window(fractol->win.mlx, fractol->win.win);
	exit(0);
}

void	print_guide(void)
{
	printf("\n\033[0;31m### 😥 WRONG ARGUMENTS 😥 ###\n");
	printf("\033[0mDon't worry! Please, use one of the following commands:\n\n");
	printf("\t\033[0;32m./fractol mandelbrot\n");
	printf("\t./fractol julia\n");
	printf("\t./fractol burningship\n");
	printf("\t./fractol perpendicular_burningship\n");
	printf("\t./fractol mandelbar\n");
	printf("\t./fractol celtic_mandelbar\n");
	printf("\t./fractol celtic_perpendicular\n");
	printf("\t./fractol perpendicular_buffalo\n\n");
	printf("\t\033[0;33mTap 'M' to check some cool effects! 😉 \033[0m\n\n");
	exit_fractol(0);
}

void	print(t_fractol *fractol, int x, int y, char *text)
{
	mlx_string_put(fractol->win.mlx, fractol->win.win, x, y, 0xFF0000, text);
}

void	print_green(t_fractol *fractol, int x, int y, char *text)
{
	mlx_string_put(fractol->win.mlx, fractol->win.win, x, y, 0x00FF00, text);
}
