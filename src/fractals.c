/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:11:56 by acanterg          #+#    #+#             */
/*   Updated: 2021/09/15 18:12:57 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_fractol *fractol, t_complex c)
{
    t_complex z;
    t_complex temp;
    int n;

	n = 0;
	z.a = 0;
	z.b = 0;
	temp = z;
    while ((z.a * z.a + z.b * z.b) < 16 && n < fractol->config.max_iter)
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