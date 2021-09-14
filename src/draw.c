/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 03:05:10 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/14 06:12:41 by aneuwald         ###   ########.fr       */
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

void    draw(t_fractol *fractol)
{
    int i;
    int j;

    i = fractol->config.x;
    while(i < fractol->config.x + 50)
    {
        j = fractol->config.y;
        while(j < fractol->config.y + 50)
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