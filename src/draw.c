/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 03:05:10 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/20 18:02:16 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

    if (x < 0 || x >= WINDOW_SIZE || y < 0 || y >= WINDOW_SIZE)
        return ;
	
    dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}


void draw_fractol(t_fractol *fractol)
{
	int i;
	int j;
	int	iter;
	int color;

	i = -1;
	while (++i < WINDOW_SIZE)
	{
		j = -1;
		while (++j < WINDOW_SIZE)
		{
            if (fractol->config.menu && j >= WINDOW_SIZE - 30)
                break;
			iter = get_fractal(fractol, get_complex(i, j, fractol));
			color = pick_color(iter, fractol);
 			my_mlx_pixel_put(&fractol->img, i, j, color);
		}
	}
	mlx_put_image_to_window(fractol->win.mlx, fractol->win.win, fractol->img.img, 0, 0);
    if (fractol->config.menu)
        draw_menu(fractol);
	
    (void) fractol;
}