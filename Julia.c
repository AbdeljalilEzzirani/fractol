/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:18:17 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/16 20:00:20 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fc(z)=z^2+C
// C=r*cos(a)+i*r*sin(a), де: a=(0..2*Pi), r=0,7885.

#include "fractol.h"

int color_degrade_Julia(int itr)
{
	// int			t;
	int			r;
	int			g; 
	int			b;

    r = itr * 3555;
	g = (1 - itr)  * itr * 3555;
	b = (1 - itr) * (1 - itr) * itr * 3555;
    // if ()
	// t = (1 - itr) * (1 - itr) *  itr * itr * (itr ^ 10) * 0x00FF0000 * 0x0000FF00 * 0x000000FF;
	// r = (1 - itr) * (1 - itr) *  itr * itr * (itr ^ 10) * 0x00FF0000;
	// g = (1 - itr) * (1 - itr) *  itr * itr * (itr ^ 10) * 0x0000FF00;
	// b = (1 - itr) * (1 - itr) *  itr * itr * (itr ^ 10) * 0x000000FF;
	return (0 << 24 | r << 16 | g << 8 | b);
}

// int tab_key_hook(int keycode, t_data *param)
// {
//     (void)param;
//     if (keycode == 257 || keycode == 258)
//     {
//         return (color_degrade_Julia((ITR / 255) * 255));
//     }
//     return (0);
// }

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

    // if (x >= 0 && x <= width && y >= 0 && y <= heigth)
    // {
    a = ((x - (width / 2)) / data->zoom);
    b = ((y - (heigth / 2)) / data->zoom);
    // }
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
        // printf("x ---> %f : ", x);
        // printf("y ---> %f : \n", y);
        
    return (p);
}

void Julia_function_pixel_put(t_data *x)
{
    double			i;
	double			j;
	int				itr;

	i = 0.0;
	itr = 0;
    // x->x_j = 0.99;
    // x->y_j = 1.14;
    // mlx_hook(x->win_ptr, 6, 0, &julia_move, x);
    // printf("%.2f\n", x -> y);
    // printf("%.2f\n", x -> x);
	while (i < heigth){
        j = 0.0;
		while (j < width) 
		{
			itr = Julia(i, j, x);
			if (itr == ITR)
				my_mlx_pixel_put(x,i+x->x,j+x->y, color_degrade_Julia(0xFF141D % 4));
			else
				my_mlx_pixel_put(x,i+x->x,j+x->y, color_degrade_Julia(0x000000FF % 4));
			j++;
		}
        i++;
	}
    // mlx_hook();
    mlx_clear_window(x->mlx_ptr, x->win_ptr);
    mlx_put_image_to_window(x->mlx_ptr,x->win_ptr,x->img, 0, 0);
}
