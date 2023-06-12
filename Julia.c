/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:18:17 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/12 14:35:09 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fc(z)=z^2+C
// C=r*cos(a)+i*r*sin(a), де: a=(0..2*Pi), r=0,7885.

#include "fractol.h"

int color_degrade_Julia(int itr)
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

int Julia(double x, double y)
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
        a = r + -0.74543;
        b = i + 0.11301;
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
			itr = Julia(i, j);
			if (itr == ITR)
				my_mlx_pixel_put(x,i,j, color_degrade_Julia((itr ^ 10) * (itr ^ 10) * itr * itr));
			else
				my_mlx_pixel_put(x,i,j, color_degrade_Julia(itr * itr * itr * itr * (itr ^ 10)));
			j++;
		}
        i++;
	}
}
