/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 02:32:29 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/14 06:17:35 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_fractol(t_window *win)
{
	//if (win)
		//mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	(void) win;
    exit(0);
}

void    increment(int *var, int step)
{
    if (*var + step < 0 || *var + step > WINDOW_SIZE)
        return ;
        
    *var += step;
}

int	key_hook(int keycode, t_fractol *fractol)
{
    printf("fractol->config.x: %u\n", fractol->config.x);
    printf("fractol->config.y: %u\n", fractol->config.y);
	if (keycode == UP)
        increment(&fractol->config.y, -10);
    else if (keycode == DOWN)
        increment(&fractol->config.y, 10);
    else if (keycode == LEFT)
        increment(&fractol->config.x, -10);
    else if (keycode == RIGHT)
        increment(&fractol->config.x, 10);
    else if (keycode == ESC)
        exit_fractol(&fractol->win);
    else
        draw(fractol);
    
    return (0);
}


int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
    printf("button: %d\n", button);
    printf("x: %d\n", x);
    printf("y: %d\n", y);
    if (button == MOUSEL)
        clear_drawing(fractol);
    else if (button == SCROLLUP && fractol->config.size < 50)
        fractol->config.size++;
    else if (button == SCROLLDOWN && fractol->config.size > 5)
        fractol->config.size--;
    
    return (0);
}