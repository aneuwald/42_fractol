/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 03:05:10 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/15 17:48:11 by acanterg         ###   ########.fr       */
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

void draw_circle(t_fractol *fractol, float x, float y, float r)
{
    int i;
    int j;

    i = x - r;
    while(i < x + r)
    {
        j = y - r;
        while(j < y + r)
        {
            if ((((x - i)*(x - i)) + ((y - j)*(y - j))) <= r * r)
                my_mlx_pixel_put(&fractol->img, i, j, 0x00FFAA00);
            j++;
        }
        i++;
    }
	mlx_put_image_to_window(fractol->win.mlx, fractol->win.win, fractol->img.img, 0, 0);
}

void    draw_square(t_fractol *fractol, int x, int y, int size)
{
    int i;
    int j;

    i = x;
    while(i < x + size)
    {
        j = y;
        while(j < y + size)
        {
            my_mlx_pixel_put(&fractol->img, i, j, 0x00FF0000);
            j++;
        }
        i++;
    }
	mlx_put_image_to_window(fractol->win.mlx, fractol->win.win, fractol->img.img, 0, 0);
}

void    clear_drawing(t_fractol *fractol)
{
    int i;
    int j;

    i = 0;
    while(i < WINDOW_SIZE)
    {
        j = 0;
        while(j < WINDOW_SIZE)
        {
            my_mlx_pixel_put(&fractol->img, i, j, 0x00FFFFFF);
            j++;
        }
        i++;
    }
	mlx_put_image_to_window(fractol->win.mlx, fractol->win.win, fractol->img.img, 0, 0);
}

int	get_color(int op, int r, int g, int b)
{
	return((op << 24) + (r << 16) + (g << 8) + b);
}

void draw_fractol(t_fractol *fractol)
{
	int i;
	int j;
	int	iter;
	int color;
	t_complex coord;

	i = -1;
	while (++i < WINDOW_SIZE)
	{
		j = -1;
		while (++j < WINDOW_SIZE)
		{
			coord.a = fractol->config.h_start + ((double)i / WINDOW_SIZE) * fractol->config.vp_size;
			coord.b = fractol->config.v_start + ((double)j / WINDOW_SIZE) * fractol->config.vp_size;
			iter = mandelbrot(fractol, coord);
			color = 255 - (iter * 255 / fractol->config.max_iter);
			color = get_color(0, color, color, color);
			// color = get_color(0, 255, 0, 0);
 			my_mlx_pixel_put(&fractol->img, i, j, color);
		}
	}
	mlx_put_image_to_window(fractol->win.mlx, fractol->win.win, fractol->img.img, 0, 0);
	printf("h_start: %.30f\n", fractol->config.h_start);
	printf("v_start: %.30f\n", fractol->config.v_start);
	printf("vp_size: %.30f\n", fractol->config.vp_size);
	printf("max_iter: %d\n", fractol->config.max_iter);
	(void) fractol;
}