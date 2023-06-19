/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:18:17 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/19 17:11:30 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int color_degrade(int itr, t_data *param)
{
	int			b;
	int			r;
	int			g; 
    int         t;
    
    r = itr * 355599;
	g = itr * 355599;
	b = itr * 355599;
	t = itr * 355599;
    if (param->trgb == 257)
        t = itr * 0xFFBB14 * (355555);
    else if (param->trgb == 1)
        r = itr * 0xFF4514 * (355555);
    else if (param->trgb == 2)
        g = itr * 0xFF1493 *(3555555);
    else if (param->trgb == 3)
        b = itr *  0x000080 *(355555);
    else if (param->trgb == 4)
        t = itr * 0x000080 *(355555);
    else if (param->trgb == 5)
        r = itr * 0xDC143C * (355555);
    return ((t << 24 | r << 16 | g << 8 | b));
}

int julia_move(int x, int y, t_data *param)
{
    if (x >= 0 && y >= 0 && x <= width && y <= heigth)
    {
        if (param->zawm == 49)
            return 0;
        else if (param->zawm == 48)
        { 
            param->x_j = (x - width / 2) / (width / 2);
            param->y_j = (y - heigth / 2) / (heigth / 2);
        }   
        param->x_j = (x - width / 2) / (width / 2);
        param->y_j = (y - heigth / 2) / (heigth / 2);
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
	while (i < heigth)
    {
        j = 0.0;
		while (j < width) 
		{
			itr = Julia(i+x->x, j+x->y, x);
			if (itr == ITR)
				my_mlx_pixel_put(x,i,j, color_degrade(0xFF141D % 4, x));
			else
				my_mlx_pixel_put(x,i,j, color_degrade(0x000000FF % 4, x));
			j++;
		}
        i++;
	}
    mlx_clear_window(x->mlx_ptr, x->win_ptr);
    mlx_put_image_to_window(x->mlx_ptr,x->win_ptr,x->img, 0, 0);
}
