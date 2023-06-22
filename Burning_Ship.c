/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burning_Ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:11:30 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/20 11:39:40 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	flesh_key_hook(int keycode, t_data *param)
{
	keyhook(keycode, param);
	if (keycode == 53)
		ft_exit(param);
	if (keycode == 126)
		param->y += 10;
	else if (keycode == 125)
		param->y -= 10;
	else if (keycode == 123)
		param->x += 10;
	else if (keycode == 124)
		param->x -= 10;
	if (param->set == 0)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		mndlbrt_function_pixel_put(param);
	}
	else if (param->set == 1)
	{
		julia_function_pixel_put(param);
	}
	else if (param->set == 2)
		burning_ship_function_pixel_put(param);
	return (0);
}

int	ft_exit(t_data *param)
{
	mlx_destroy_image(param->mlx_ptr, param->img);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	exit(0);
}

int	burning_ship_fractal(double x, double y, t_data *data)
{
	double						a;
	double						b;
	double						l;
	double						k;
	double						p;

	a = (x * data -> zoom_wid) - data -> var_wid;
	b = (y * data -> zoom_hei) - data -> var_hei;
	k = a;
	l = b;
	p = 0.0;
	while (p < ITR && ((a * a) + (b * b) < 4))
	{
		data->r = (a * a) - (b * b);
		data->i = 2 * fabs(b * a);
		a = data->r + k;
		b = data->i + l;
		p++;
	}
	return (p);
}

void	burning_ship_function_pixel_put(t_data *x)
{
	double			i;
	double			j;
	int				itr;

	i = 0.0;
	itr = 0;
	while (i < HEIGTH)
	{
		j = 0.0;
		while (j < WIDTH)
		{
			itr = burning_ship_fractal(i + x->x, j + x->y, x);
			if (itr == ITR)
				my_mlx_pixel_put(x, i, j, color_degrade(0xFFD700, x));
			else
				my_mlx_pixel_put(x, i, j, color_degrade(0x2F4F4F, x));
			j++;
		}
		i++;
	}
	mlx_clear_window(x->mlx_ptr, x->win_ptr);
	mlx_put_image_to_window(x->mlx_ptr, x->win_ptr, x->img, 0, 0);
}
