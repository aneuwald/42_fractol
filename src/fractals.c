/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:11:56 by acanterg          #+#    #+#             */
/*   Updated: 2021/09/20 17:06:29 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_fractol *fractol, t_complex c)
{
    t_complex z;
    t_complex temp;
    int n;

	n = 0;
	z.a = c.a;
	z.b = c.b;
	temp = z;
    while ((z.a * z.a + z.b * z.b) < 4 && n < fractol->config.max_iter)
	{
		z.a = (temp.a * temp.a - temp.b * temp.b) + fractol->config.m.a;
		z.b = (temp.a * temp.b + temp.a * temp.b) + fractol->config.m.b;
		if (z.a == temp.a && z.b == temp.b)
			return(fractol-> config.max_iter);
        n++;
		temp = z;
	}
    return (n);
}

int	burningship(t_fractol *fractol, t_complex c)
{
    t_complex z;
    t_complex temp;
    int n;

	n = 0;
	z.a = c.a;
	z.b = c.b;
	temp = z;
    while ((z.a * z.a + z.b * z.b) < 16 && n < fractol->config.max_iter)
	{
		z.a = temp.a * temp.a - temp.b * temp.b + c.a;
		z.b = fabs(2 * temp.a * temp.b) + c.b;
		if (z.a == temp.a && z.b == temp.b)
			return(fractol-> config.max_iter);
        n++;
		temp = z;
	}
    return (n);
}

int	mandelbrot(t_fractol *fractol, t_complex c)
{
    t_complex z;
    t_complex temp;
    int n;

	n = 0;
	z.a = c.a;
	z.b = c.b;
	temp = z;
    while ((z.a * z.a + z.b * z.b) < 4 && n < fractol->config.max_iter)
	{
		z.a = (temp.a * temp.a - temp.b * temp.b) + c.a;
		z.b = (temp.a * temp.b + temp.a * temp.b) + c.b;
		if (z.a == temp.a && z.b == temp.b)
			return(fractol-> config.max_iter);
        n++;
		temp = z;
	}
    return (n);
}

int	get_fractal(t_fractol *fractol, t_complex c)
{
	if (fractol->config.fractal == MANDELBROT)
		return (mandelbrot(fractol, c));
	if (fractol->config.fractal == JULIA)
		return (julia(fractol, c));
	if (fractol->config.fractal == BURNINGSHIP)
		return (burningship(fractol, c));
		
	exit_fractol(fractol->win.win);
	return(0);
}