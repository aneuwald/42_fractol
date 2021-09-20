/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 01:41:57 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/20 17:54:48 by aneuwald         ###   ########.fr       */
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

# include "keymap.h"
# include "../minilibx-linux/mlx.h"
/*# include "mlx.h"*/

# define MANDELBROT 0
# define JULIA 1
# define BURNINGSHIP 2

# define WINDOW_SIZE 500
# define STEP_ITER 10

typedef struct	    s_complex {
	double			a;
	double			b;
}				    t_complex;

typedef struct		s_palette
{
	int				count;
	int				colors[16];
}					t_palette;

typedef	struct		s_config
{
	int				fractal;
    int             x;
    int             y;
	double			h_start;
	double			v_start;
	double			vp_size;
	int				max_iter;
	int				menu;
	int				mouse_locked;
	t_complex		m;
	int				color;
	t_palette		*palette;
}					t_config;

typedef struct	    s_color {
	int				r;
	int				g;
	int				b;
}				    t_color;

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
void    draw_square(t_fractol *fractol, int x, int y, int size, int color);
void	draw_circle(t_fractol *fractol, float x, float y, float r);
void	draw_fractol(t_fractol *fractol);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	clear_drawing(t_fractol *fractol);
int		exit_fractol(t_window *win);
int		get_fractal(t_fractol *fractol, t_complex c);
t_complex get_complex(int x, int y, t_fractol *fractol);
void    draw_menu(t_fractol *fractol);
char	*ft_itoa(int n);
t_palette	*get_palettes(void);
int pick_color(int iter, t_fractol *fractol);

#endif
