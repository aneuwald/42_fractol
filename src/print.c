/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:59:33 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/21 02:01:36 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_fractol(t_fractol *fractol)
{
	if (fractol && fractol->win.win)
		mlx_destroy_window(fractol->win.mlx, fractol->win.win);
	exit(0);
}

void	print_guide(void)
{
	printf("\n\033[0;31m### WRONG ARGUMENTS ###\n");
	printf("\033[0mPlease, use one of the following options:\n\n");
	printf("\t\033[0;32m./fractol mandelbrot\n");
	printf("\t./fractol julia\n");
	printf("\t./fractol burningship\033[0m\n\n");
	exit_fractol(0);
}
