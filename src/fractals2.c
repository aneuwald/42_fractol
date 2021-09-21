/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:11:56 by acanterg          #+#    #+#             */
/*   Updated: 2021/09/21 02:51:12 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbar(t_fractol *fractol, t_complex c)
{
	t_complex	z;
	t_complex	temp;
	int			n;

	n = 0;
	z = c;
	temp = z;
	while ((z.a * z.a + z.b * z.b) < 4 && n < fractol->config.max_iter)
	{
		z.a = (temp.a * temp.a - temp.b * temp.b) + c.a;
		z.b = (-2.0 * temp.a * temp.b) + c.b;
		if (z.a == temp.a && z.b == temp.b)
			return (fractol-> config.max_iter);
		n++;
		temp = z;
	}
	return (n);
}

int	celtic_mandelbar(t_fractol *fractol, t_complex c)
{
	t_complex	z;
	t_complex	temp;
	int			n;

	n = 0;
	z = c;
	temp = z;
	while ((z.a * z.a + z.b * z.b) < 4 && n < fractol->config.max_iter)
	{
		z.a = fabs((temp.a * temp.a - temp.b * temp.b)) + c.a;
		z.b = (-2.0 * temp.a * temp.b) + c.b;
		if (z.a == temp.a && z.b == temp.b)
			return (fractol-> config.max_iter);
		n++;
		temp = z;
	}
	return (n);
}

int	celtic_perpendicular(t_fractol *fractol, t_complex c)
{
	t_complex	z;
	t_complex	temp;
	int			n;

	n = 0;
	z = c;
	temp = z;
	while ((z.a * z.a + z.b * z.b) < 4 && n < fractol->config.max_iter)
	{
		z.a = fabs((temp.a * temp.a - temp.b * temp.b)) + c.a;
		z.b = -2.0 * fabs(temp.a) * temp.b + c.b;
		if (z.a == temp.a && z.b == temp.b)
			return (fractol-> config.max_iter);
		n++;
		temp = z;
	}
	return (n);
}

int	perpendicular_buffalo(t_fractol *fractol, t_complex c)
{
	t_complex	z;
	t_complex	temp;
	int			n;

	n = 0;
	z = c;
	temp = z;
	while ((z.a * z.a + z.b * z.b) < 4 && n < fractol->config.max_iter)
	{
		z.a = fabs(temp.a * temp.a - temp.b * temp.b) + c.a;
		z.b = (-2.0 * temp.a * fabs(temp.b)) + c.b;
		if (z.a == temp.a && z.b == temp.b)
			return (fractol-> config.max_iter);
		n++;
		temp = z;
	}
	return (n);
}

int	get_fractal2(t_fractol *fractol, t_complex c)
{
	if (fractol->config.fractal == MANDELBAR)
		return (mandelbar(fractol, c));
	else if (fractol->config.fractal == CELTIC_MANDELBAR)
		return (celtic_mandelbar(fractol, c));
	else if (fractol->config.fractal == CELTIC_PERPENDICULAR)
		return (celtic_perpendicular(fractol, c));
	else if (fractol->config.fractal == PERPENDICULAR_BUFFALO)
		return (perpendicular_buffalo(fractol, c));
	else
		exit_fractol(fractol->win.win);
	return (0);
}
