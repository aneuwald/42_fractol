/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 02:32:29 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/15 18:17:25 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_fractol(t_window *win)
{
	if (win)
		mlx_destroy_window(win->mlx, win->win);
    exit(0);
}

void    increment(int *var, int step)
{
    if (*var + step < 0 || *var + step > WINDOW_SIZE)
        return ;
        
    *var += step;
}

int		hook_mousemove(int x, int y, t_fractol *fractol)
{
    printf("x: %d\n", x);
    printf("y: %d\n", y);
    draw_circle(fractol, x, y, fractol->config.size);
    (void) fractol;
	return (0);
}


int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == UP)
		fractol->config.v_start -= fractol->config.vp_size * 0.05;
    else if (keycode == DOWN)
		fractol->config.v_start += fractol->config.vp_size * 0.05;
    else if (keycode == LEFT)
		fractol->config.h_start -= fractol->config.vp_size * 0.05;
    else if (keycode == RIGHT)
		fractol->config.h_start += fractol->config.vp_size * 0.05;
	else if (keycode == PLUS)
		fractol->config.max_iter += 10;
    else if (keycode == MINUS && fractol->config.max_iter > 10)
		fractol->config.max_iter -= 10;	
    else if (keycode == ESC)
        exit_fractol(&fractol->win);
    draw_fractol(fractol);
    
    return (0);
}


int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	(void) x;
	(void) y;

    if (button == SCROLLUP)
	{
		fractol->config.h_start += fractol->config.vp_size * 0.05;
		fractol->config.v_start += fractol->config.vp_size * 0.05;
		fractol->config.vp_size *= 0.9;
	}
    else if (button == SCROLLDOWN)
    {
		fractol->config.h_start -= fractol->config.vp_size * 0.05;
		fractol->config.v_start -= fractol->config.vp_size * 0.05;
		fractol->config.vp_size *= 1.1;
	}
	draw_fractol(fractol);
    return (0);
}