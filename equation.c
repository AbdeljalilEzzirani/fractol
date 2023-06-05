/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:15:57 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/05 19:42:46 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int mandelbrot(double x, double y)
{
    double a;
    double b;
    double p;
    double k;
    double l;
    double r;
    double i;

    a = ((x - (800 / 2)) / (800 / 4));
    b = ((y - (800 / 2)) / (800 / 4));
    k = a;
    l = b;
    p = 0.0;
    while(p < ITR)
    {
        r = (a * a) - (b * b);
        i = 2 * b * a;
        a = r + k;
        b = i + l;
        if((a * a) + (b * b) > 4)
            break;
        p++;
    }
    // printf("%d\n", p);
    return p;
}


//  if (mandelbrot(x,y) == 80)
//                 mlx_pixel_put (mlx_ptr, win_ptr, i, j, 0XFF33FF);
//             else
//                 mlx_pixel_put (mlx_ptr, win_ptr, j, i, 0XFF33AB);
//             x++;
//             y++;