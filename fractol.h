/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:18:20 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/20 19:08:17 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define ITR 80
# define WIDTH 1000.0
# define HEIGTH 1000.0

typedef struct s_data
{
	void		*mlx_ptr;
	double		zoom_wid;
	double		zoom_hei;
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
	void		*win_ptr;
	void		*param;
	int			wid_zoom;
	int			hei_zoom;
	int			zawm;
	int			key_button;
	double		zoom;
	double		x;
	double		y;
	int			t;
	int			g;
	int			b;
	int			trgb;
	double		r;
	double		i;
}				t_data;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			mandelbrot(double x, double y, t_data *data);
int			julia(double x, double y, t_data *data);
void		julia_function_pixel_put(t_data *x);
void		mndlbrt_function_pixel_put(t_data *x);
int			ft_strcmp(char *s1, char *s2);
int			julia_move(int x, int y, t_data *param);
void		burning_ship_function_pixel_put(t_data *x);
void		ft_putstr(char *s);
int			f_zoom(int button, int x, int y, t_data *param);
void		msg_list_display(void);
void		check_fractal(char *scmp, t_data *x);
int			flesh_key_hook(int keycode, t_data *param);
int			ft_exit(t_data *param);
int			color_degrade(int itr, t_data *param);
int			burning_ship_fractal(double x, double y, t_data *data);
void		keyhook(int keycode, t_data *param);

#endif
