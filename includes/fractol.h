/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 01:41:57 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/14 06:14:09 by aneuwald         ###   ########.fr       */
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

# include "../minilibx-linux/mlx.h"

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define ESC 65307

# define MOUSEL 1
# define MOUSES 2
# define MOUSER 3
# define SCROLLUP 4
# define SCROLLDOWN 5

# define WINDOW_SIZE 800

typedef	struct		s_config
{
    int             x;
    int             y;
	int				size;
}					t_config;

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
void    init(t_fractol *fractol);
void    draw(t_fractol *fractol);
void	draw_circle(t_fractol *fractol, float x, float y, float r);
void	clear_drawing(t_fractol *fractol);
int		exit_fractol(t_window *win);

#endif
