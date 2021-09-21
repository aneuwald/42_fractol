/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 02:29:35 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/21 00:33:46 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_guide(void)
{
	printf("\n\033[0;31m!!! WRONG INPUT ARGUMENTS !!!\n");
	printf("\033[0mPlease, use one of the following options:\n");
	printf("\033[0;32m./fractol mandelbrot\n");
	printf("./fractol julia\n");
	printf("./fractol burningship\033[0m\n\n");
	exit_fractol(0);
}

void	set_fractal(t_fractol *fractol, char *name)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		fractol->config.fractal = MANDELBROT;
	else if (ft_strcmp(name, "julia") == 0)
		fractol->config.fractal = JULIA;
	else if (ft_strcmp(name, "burningship") == 0)
		fractol->config.fractal = BURNINGSHIP;
	else
		print_guide();
}

int	main(int argc, char **argv)
{
	t_fractol fractol;

	(void) argv;
	if (argc != 2)
		print_guide();
	set_fractal(&fractol, argv[1]);
	init(&fractol);

	return (0);
}