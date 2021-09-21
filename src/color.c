/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:52:50 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/21 08:55:01 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int op, int r, int g, int b)
{
	return((op << 24) + (r << 16) + (g << 8) + b);
}

t_color	parse_color(int c)
{
	t_color color;

	color.r = (c >> 16) & 0xFF;
	color.g = (c >> 8) & 0xFF;
	color.b = (c) & 0xFF;
	return (color);
}

int interpolate_color(int color1, int color2, double fract)
{
	const t_color c1 = parse_color(color1);
	const t_color c2 = parse_color(color2);
	t_color c;
	
	c.r = fract * c2.r + (1 - fract) * c1.r;
	c.g = fract * c2.g + (1 - fract) * c1.g;
	c.b = fract * c2.b + (1 - fract) * c1.b;
	return (get_color(0, c.r, c.g, c.b));
}

int pick_color(int iter, t_fractol *fractol)
{
	const t_palette p = fractol->config.palette[fractol->config.color];
	const double ratio = (fractol->config.max_iter + 1) / ((double)p.count - 1);
	const double fract = (iter / ratio) - floor(iter / ratio);

	if (fractol->config.p)
		return (interpolate_color(p.colors[((int)floor(iter / ratio) + fractol->config.shift - 1) % (p.count)],
					p.colors[((int)floor(iter / ratio) + fractol->config.shift) % (p.count)],
					fract));
	if (iter == fractol->config.max_iter)
		return (get_color(0, 0, 0, 0));

	return (interpolate_color(p.colors[(int)floor(iter / ratio) ],
						p.colors[(int)floor(iter / ratio) + 1],
						fract));
}

t_palette	*get_palettes(void)
{
	static t_palette	array[6];

	array[0] =
		(t_palette){16,{0x000000, 0x040110, 0x09012f, 0x040449,
						0x000764,0x0c2c8a,0x1853b1, 0x397dd1,
						0x86b5e5, 0xd3ecf8, 0xf1e9bf, 0xf8c95f,
						0xffaa00, 0xcc8100, 0x995700, 0x6a3503}};
	array[1] =
		(t_palette){5,{0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121}};
	array[2] =
		(t_palette){5,{0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, 0xA1D700}};
	array[3] =
		(t_palette){5,{0x002F2F, 0x046380, 0xEFECCA, 0xA7A37E, 0xE6E2AF}};
	array[4] =
		(t_palette){7, {0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF,
			0x0000FF, 0xFF00FF, 0xFF0000}};
	array[5] =
		(t_palette){8, {0x000000, 0x50050E, 0x7C091F, 0x890100,
			0xA20004, 0xb30e02, 0xC31B00, 0xDD0000}};
	return (array);
}
