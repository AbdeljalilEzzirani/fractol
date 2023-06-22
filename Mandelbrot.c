/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:17:56 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/20 19:18:20 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	f_zoom(int button, int x, int y, t_data *param)
{
	if (button == 4)
	{
		param->var_wid += (x * param->zoom_hei);
		param->var_hei += (y * param->zoom_wid);
		param->zoom_hei *= 2;
		param->zoom_wid *= 2;
	}
	else if (button == 5)
	{
		param->zoom_hei /= 2;
		param->zoom_wid /= 2;
		param->var_wid -= (x * param->zoom_hei);
		param->var_hei -= (y * param->zoom_wid);
	}
	if (param->set == 0)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		mndlbrt_function_pixel_put(param);
	}
	else if (param->set == 1)
		julia_function_pixel_put(param);
	else if (param->set == 2)
		burning_ship_function_pixel_put(param);
	return (0);
}

int	mandelbrot(double x, double y, t_data *data)
{
	double				a;
	double				b;
	double				l;
	double				k;
	double				p;

	a = (x * data -> zoom_wid) - data -> var_wid;
	b = (y * data -> zoom_hei) - data -> var_hei;
	k = a;
	l = b;
	p = 0.0;
	while (p < ITR && ((a * a) + (b * b) < 4))
	{
		data->r = (a * a) - (b * b);
		data->i = 2 * b * a;
		a = data->r + k;
		b = data->i + l;
		p++;
	}
	return (p);
}

void	mndlbrt_function_pixel_put(t_data *x)
{
	int				i;
	int				j;
	int				itr;

	i = 0;
	itr = 0;
	while (i < HEIGTH)
	{
		j = 0;
		while (j < WIDTH)
		{
			itr = mandelbrot(i + x->x, j + x->y, x);
			if (itr == ITR)
				my_mlx_pixel_put(x, i, j, color_degrade(0xFFD700, x));
			else
				my_mlx_pixel_put(x, i, j, color_degrade(0x2F4F4F, x));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(x->mlx_ptr, x->win_ptr, x->img, 0, 0);
}
