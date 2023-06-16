/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:17:56 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/16 03:24:54 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int color_degrade_MNDLBRT(int itr)
{
	int			r;
	int			g; 
	int			b;
	
	r = (1 - itr) * itr * 3555;
	g = (1 - itr) * (1 - itr)  * itr * 3555;
	b = (1 - itr) * (1 - itr) * (1 - itr) * itr * 3555;
	return (0 << 24 | r << 16 | g << 8 | b);
}

//scrol Up ->> 4  /  Scrol Down ->> 5

int f_zoom(int button, int x, int y, t_data *param)
{
	(void)x;
	(void)y;
	if (button == 4)
		param->zoom *= 1.09;
	else if (button == 5)
		param->zoom /= 1.09;
	if(param->set == 0)
		MNDLBRT_function_pixel_put(param);
	else if(param->set == 1)
		Julia_function_pixel_put(param);
	return 0;
}

// int change_color(int keycode, t_data *param)
// {
// 	if (keycode == 257 || keycode == 258)
// 	{
		
// 	}
// }

int close_window(int keycode, t_data *param)
{
	if (keycode == 53)
	{
		exit (0);
		mlx_destroy_image(param->mlx_ptr, param->img);
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	}
	return (0);
}

int	check_button(t_data *x)
{
	exit (0);
	mlx_destroy_image(x->mlx_ptr, x->img);
	mlx_clear_window(x->mlx_ptr, x->win_ptr);
	mlx_destroy_window(x->mlx_ptr, x->win_ptr);
}

int mandelbrot(double x, double y, t_data *data)
{
    double a;
    double b;
    double l;
    double k;
    double p;
    double r;
    double i;

    a = ((x - (width / 2)) / data->zoom);
    b = ((y - (heigth / 2)) / data->zoom);
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
			itr = mandelbrot(i, j, x);
			if (itr == ITR)
				my_mlx_pixel_put(x,i,j, color_degrade_MNDLBRT(0xFFD700));
			else
				my_mlx_pixel_put(x,i,j, color_degrade_MNDLBRT(0x2F4F4F));
			j++;
		}
        i++;
	}
	// mlx_hook();
	// mlx_mouse_hook(x->win_ptr, equation_zoom, x->param);// for zoom
	mlx_clear_window(x->mlx_ptr, x->win_ptr);
    mlx_put_image_to_window(x->mlx_ptr,x->win_ptr,x->img, 0, 0);
}
