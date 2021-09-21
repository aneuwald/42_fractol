/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 01:41:57 by aneuwald          #+#    #+#             */
/*   Updated: 2021/09/21 02:00:19 by aneuwald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* HOOKS */
int         key_hook(int keycode, t_fractol *fractol);
int         mouse_hook(int button, int x, int y, t_fractol *fractol);
int         hook_mousemove(int x, int y, t_fractol *fractol);

/* DRAWING */
void		draw_fractol(t_fractol *fractol);
void		my_mlx_pixel_put(t_image *img, int x, int y, int color);
void        draw_menu(t_fractol *fractol);
int			pick_color(int iter, t_fractol *fractol);
t_palette	*get_palettes(void);
void		print_guide(void);

/* PROGRAM */
void		init(t_fractol *fractol);
int         exit_fractol(t_fractol *fractol);
int			get_fractal(t_fractol *fractol, t_complex c);
t_complex   get_complex(int x, int y, t_fractol *fractol);

/* UTILS */ 
char		*ft_itoa(int n);
int			ft_strcmp(char *s1, char *s2);

#endif
