/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:17:56 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/19 02:54:51 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int color_degrade_MNDLBRT(int itr)
// {
// 	int			r;
// 	int			g; 
// 	int			b;
	
// 	r = (1 - itr) * itr * 3555;
// 	g = (1 - itr) * (1 - itr)  * itr * 3555;
// 	b = (1 - itr) * (1 - itr) * (1 - itr) * itr * 3555;
// 	return (0 << 24 | r << 16 | g << 8 | b);
// }


int f_zoom(int button, int x, int y, t_data *param)
{
	if (button == 4)//scrol Up ->> 4
	{
		param->var_wid += (x  * param->zoom_height);
		param->var_hei += (y  * param->zoom_width);
		param->zoom_height *= 2;
		param->zoom_width *= 2;
	}
	else if (button == 5){// Scrol Down ->> 5
		param->zoom_height /= 2;
		param->zoom_width /= 2;
		param->var_wid -= (x  * param->zoom_height);
		param->var_hei -= (y * param->zoom_width);
	}
	if(param->set == 0)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		MNDLBRT_function_pixel_put(param);
	}
	else if(param->set == 1)
		Julia_function_pixel_put(param);
	else if(param->set == 2)
		Burning_Ship_function_pixel_put(param);
	return 0;
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

    a = (x * data -> zoom_width) - data -> var_wid;
    b = (y * data -> zoom_height) - data -> var_hei;
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
    int			i;
	int			j;
	int				itr;

	// if(x->img != NULL)
	// 	mlx_destroy_image(x->mlx_ptr, x->img);
	i = 0;
	itr = 0;
	while (i < heigth){
        j = 0;
		while (j < width) 
		{
			itr = mandelbrot(i + x->x, j + x->y, x);
			if (itr == ITR)
				my_mlx_pixel_put(x, i, j, color_degrade(0xFFD700));
			else
				my_mlx_pixel_put(x, i, j, color_degrade(0x2F4F4F));
			j++;
		}
        i++;
	}
	// mlx_clear_window(x->mlx_ptr, x->win_ptr);
    mlx_put_image_to_window(x->mlx_ptr,x->win_ptr,x->img, 0, 0);
}
