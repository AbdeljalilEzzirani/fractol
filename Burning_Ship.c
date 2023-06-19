/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burning_Ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:11:30 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/19 17:21:34 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int Burning_Ship_fractal(double x, double y, t_data *data)
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
        i = 2 * fabs(b * a); 
        a = r + k;
        b = i + l;
        p++;
    }
    return (p);
}

void Burning_Ship_function_pixel_put(t_data *x)
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
			itr = Burning_Ship_fractal(i+x->x, j+x->y, x);
			if (itr == ITR)
				my_mlx_pixel_put(x, i, j, color_degrade(0xFFD700, x));
			else
				my_mlx_pixel_put(x, i, j, color_degrade(0x2F4F4F, x));
			j++;
		}
        i++;
	}
	mlx_clear_window(x->mlx_ptr, x->win_ptr);
    mlx_put_image_to_window(x->mlx_ptr,x->win_ptr,x->img, 0, 0);
}
