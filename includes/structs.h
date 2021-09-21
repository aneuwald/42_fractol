/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 01:41:57 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/20 23:54:03 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	t_complex		default_m;
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

#endif
