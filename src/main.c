/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 02:29:35 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/21 01:59:54 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_fractal(t_fractol *fractol, char *name)
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

	if (argc != 2)
		print_guide();
	check_fractal(&fractol, argv[1]);
	init(&fractol);

	return (0);
}