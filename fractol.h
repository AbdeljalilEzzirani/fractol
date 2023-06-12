/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:18:20 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/12 14:22:19 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include"mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <math.h>

#define ITR 80
#define width 1000
#define heigth 1000


typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void    *mlx_ptr;
	void    *win_ptr;
}				t_data;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int 		mandelbrot(double x, double y);
int 		Julia(double x, double y);
void		Julia_function_pixel_put(t_data *x);
void		MNDLBRT_function_pixel_put(t_data *x);


// double		sin(double angle);
// double		cos(double angle);
// int			trgb(double it);
// void		MNDLBRT_function_pixel_put(t_data *x);
// int			Julia(double x, double y);
// void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
