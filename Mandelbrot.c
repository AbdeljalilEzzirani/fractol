/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:17:56 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/12 14:24:52 by abez-zir         ###   ########.fr       */
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
	int			t;
	int			r;
	int			g; 
	int			b;
	
	t = (1 - itr) * (1 - itr) *  itr * itr * (itr ^ 10) * 0x00FF0000 * 0x0000FF00 * 0x000000FF;
	r = (1 - itr) * (1 - itr) *  itr * itr * (itr ^ 10) * 0x00FF0000;
	g = (1 - itr) * (1 - itr) *  itr * itr * (itr ^ 10) * 0x0000FF00;
	b = (1 - itr) * (1 - itr) *  itr * itr * (itr ^ 10) * 0x000000FF;
	return (t << 24 | r << 16 | g << 8 | b);
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
				my_mlx_pixel_put(x,i,j, color_degrade_MNDLBRT((itr ^ 10) * (itr ^ 10) * itr * itr));
			else
				my_mlx_pixel_put(x,i,j, color_degrade_MNDLBRT(itr * itr * itr * itr * (itr ^ 10)));
			j++;
		}
        i++;
	}
}
