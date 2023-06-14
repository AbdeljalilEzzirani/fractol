/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:17:56 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/14 03:11:49 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int color_degrade_MNDLBRT(int itr)
{
	// int			t;
	int			r;
	int			g; 
	int			b;
	
	// t = itr * 0x00FF0000 * 0x0000FF00 * 0x000000FF;
	r = (1 - itr) * itr * 3555;
	g = (1 - itr) * (1 - itr)  * itr * 3555;
	b = (1 - itr) * (1 - itr) * (1 - itr) * itr * 3555;
	// return (create_trgb(0, r, g, b));	
	// t = (1 - itr) * (1 - itr) *  itr * itr * (itr ^ 10) * 0x00FF0000 * 0x0000FF00 * 0x000000FF;
	// r = (1 - itr) * (1 - itr) *  itr * itr * (itr ^ 10) * 0x00FF0000;
	// g = (1 - itr) * (1 - itr) *  itr * itr * (itr ^ 10) * 0x0000FF00;
	// b = (1 - itr) * (1 - itr) *  itr * itr * (itr ^ 10) * 0x000000FF;
	return (0 << 24 | r << 16 | g << 8 | b);
}

int mandelbrot(double x, double y)
{
    double a;
    double b;
    double l;
    double k;
    double p;
    double r;
    double i;

    a = ((x - (width / 2)) / (width / 4));
    b = ((y - (heigth / 2)) / (heigth / 4));
    k = a;
    l = b;
    p = 0.0;
    while(p < ITR && ((a * a) + (b * b) < 4))
    {
        r = (a * a) - (b * b);
        i = 2 * b * a; 
        a = r + k;
        b = i + l;
        p++;
    }
    return (p);
}

//scrol Up ->> 4  /  Scrol Down ->> 5

int equation_zoom(int button, int x, int y, t_data *param)
{
	param->width_zoom = width;
	param->heigth_zoom = heigth;
	if (button == 4)
	{
		x = param->width_zoom - (width / 10);
		y = param->heigth_zoom - (heigth / 10);
	}
	else if (button == 5)
	{
		x = param->width_zoom - (width / 10);
		y = param->heigth_zoom - (heigth / 10);
	}
	mlx_destroy_image(param->mlx_ptr, param->img);
	param->img = mlx_new_image(param->mlx_ptr, width, heigth);
	param->addr = mlx_get_data_addr(param->img, &param->bits_per_pixel, &param->line_length, &param->endian);
	if (param->digit == 0)
		MNDLBRT_function_pixel_put(param);
	return 0;
}

void MNDLBRT_function_pixel_put(t_data *x)
{
    double			i;
	double			j;
	int				itr;

	i = 0.0;
	itr = 0;
	while (i < heigth){
        j = 0.0;
		while (j < width) 
		{
			itr = mandelbrot(i, j);
			if (itr == ITR)
				my_mlx_pixel_put(x,i,j, color_degrade_MNDLBRT(0xFFD700));
			else
				my_mlx_pixel_put(x,i,j, color_degrade_MNDLBRT(0x2F4F4F));
			j++;
		}
        i++;
	}
	mlx_mouse_hook(x->win_ptr, equation_zoom, x->param);
	mlx_clear_window(x->mlx_ptr, x->win_ptr);
    mlx_put_image_to_window(x->mlx_ptr,x->win_ptr,x->img, 0, 0);
}
