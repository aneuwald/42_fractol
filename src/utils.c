/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:14:09 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/21 07:57:48 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	get_complex(int x, int y, t_fractol *fractol)
{
	t_complex	c;

	c.a = fractol->config.h_start + ((double)x / WINDOW_SIZE)
		* fractol->config.vp_size;
	c.b = fractol->config.v_start + ((double)y / WINDOW_SIZE)
		* fractol->config.vp_size;
	return (c);
}

void	increment_shift(t_fractol *fractol)
{
	const int	color = fractol->config.color;
	const int	count_color = fractol->config.palette[color].count;

	fractol->config.shift++;
	fractol->config.shift %= count_color;
}

void	decrement_shift(t_fractol *fractol)
{
	const int	color = fractol->config.color;
	const int	count_color = fractol->config.palette[color].count;

	fractol->config.shift--;
	if (fractol->config.shift < 0)
		fractol->config.shift = count_color;
}
