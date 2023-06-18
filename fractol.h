/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:18:20 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/18 20:35:58 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include"mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <math.h>

#define ITR 50
#define width 1000.0
#define heigth 1000.0

typedef struct	s_data
{
	double 		zoom_width;
	double 		zoom_height;
	double		var_wid;
	double		var_hei;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			set;
	double		x_j;
	double		y_j;
    void		*mlx_ptr;
	void		*win_ptr;
	void		*param;
	int			width_zoom;
	int			heigth_zoom;
	int			zawm;
	int			key_button;
	double		zoom;
	double		x;
	double		y;
}				t_data;

// void		struct_double(t_data *x);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int 		mandelbrot(double x, double y, t_data *data);
int 		Julia(double x, double y, t_data *data);
void		Julia_function_pixel_put(t_data *x);
void		MNDLBRT_function_pixel_put(t_data *x);
int			ft_strcmp(char *s1, char *s2);
int			julia_move(int x, int y, t_data *param);
void		Burning_Ship_function_pixel_put(t_data *x);
void		ft_putstr(char *s);
int			f_zoom(int button, int x, int y, t_data *param);
void		msg_list_display(void);
void check_fractal(char *scmp, t_data *x);
int			flesh_key_hook(int keycode, t_data *param);
int			close_window(int keycode, t_data *param);
int			tab_key_hook(int keycode, t_data *param);
int			color_degrade_Julia(int itr);
int			ft_exit(t_data *param);
int			shift_change_color(int y);
int			color_degrade(int itr);
int			Burning_Ship_fractal(double x, double y, t_data *data);
// int			change_color(int keycode, t_data *param);



// double		sin(double angle);
// double		cos(double angle);
// int			trgb(double it);
// void		MNDLBRT_function_pixel_put(t_data *x);
// int			Julia(double x, double y);
// void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
