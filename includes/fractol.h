/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 01:41:57 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/15 18:18:07 by acanterg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebourdit <ebourdit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2020/10/10 14:29:22 by ebourdit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

# include "../minilibx-linux/mlx.h"
# include "mlx.h"

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define PLUS 69
# define MINUS 78

# define ESC 53

# define MOUSEL 1
# define MOUSES 2
# define MOUSER 3
# define SCROLLUP 4
# define SCROLLDOWN 5

# define WINDOW_SIZE 100

typedef	struct		s_config
{
    int             x;
    int             y;
	int				size;
	double			h_start;
	double			v_start;
	double			vp_size;
	int			max_iter;
}					t_config;

typedef struct	    s_complex {
	double			a;
	double			b;
}				    t_complex;

typedef struct	    s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				    t_image;

typedef	struct		s_window
{
	void			*mlx;
	void			*win;
}					t_window;

typedef	struct		s_fractol
{
	t_config		config;
	t_window		win;
    t_image			img;
}					t_fractol;

int		key_hook(int keycode, t_fractol *fractol);
int		mouse_hook(int button, int x, int y, t_fractol *fractol);
int		hook_mousemove(int x, int y, t_fractol *fractol);
void    init(t_fractol *fractol);
void    draw_square(t_fractol *fractol, int x, int y, int size);
void	draw_circle(t_fractol *fractol, float x, float y, float r);
void	draw_fractol(t_fractol *fractol);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	clear_drawing(t_fractol *fractol);
int		exit_fractol(t_window *win);
int		mandelbrot(t_fractol *fractol, t_complex c);

#endif
