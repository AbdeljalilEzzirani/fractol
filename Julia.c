/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:18:17 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/19 03:01:11 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fc(z)=z^2+C
// C=r*cos(a)+i*r*sin(a), де: a=(0..2*Pi), r=0,7885.

#include "fractol.h"

// int shift_change_color(int y)
// {
    
// }

int color_degrade(int itr)
{
	int			b;
	int			r;
	int			g; 

    r = itr * 3555;
	g = (1 - itr)  * itr * 3555;
	b = (1 - itr) * (1 - itr) * itr * 3555;
    if (itr == 1)
        return (b << 24 | g << 16 | r << 8 | 0);
    else if (itr == 2)
        return (0 << 24 | b << 16 | g << 8 | r);
    else if (itr == 3)
        return (r << 24 | g << 16 | b << 8 | 0);
	return (0 << 24 | r << 16 | g << 8 | b);
}

int julia_move(int x, int y, t_data *param)
{
    if (x >= 0 && y >= 0 && x <= width && y <= heigth)
    {
        param->x_j = (x - width / 1.9) / (width / 1.5);
        param->y_j = (y - heigth / 1.9) / (heigth / 1.5);
        Julia_function_pixel_put(param);
    }
    return 0;
}

int Julia(double x, double y, t_data *data)
{
    double a;
    double b;
    double l;
    double k;
    double p;
    double r;
    double i;

    // a = ((x - (width / 2)) / data->zoom);
    // b = ((y - (heigth / 2)) / data->zoom);
    a = (x * data -> zoom_width) - data -> var_wid;
    b = (y * data -> zoom_height) - data -> var_hei;
    k = a;
    l = b;
    p = 0.0;
    while(p < ITR && ((a * a) + (b * b) < 4))
    {
        r = (a * a) - (b * b);
        i = 2 * b * a; 
        a = r + data->x_j;
        b = i + data->y_j;
        p++;
    }   
    return (p);
}

void Julia_function_pixel_put(t_data *x)
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
			itr = Julia(i+x->x, j+x->y, x);
			if (itr == ITR)
				my_mlx_pixel_put(x,i,j, color_degrade(0xFF141D % 4));
			else
				my_mlx_pixel_put(x,i,j, color_degrade(0x000000FF % 4));
			j++;
		}
        i++;
	}
    mlx_clear_window(x->mlx_ptr, x->win_ptr);
    mlx_put_image_to_window(x->mlx_ptr,x->win_ptr,x->img, 0, 0);
}
