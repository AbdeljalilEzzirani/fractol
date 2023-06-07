/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:19:35 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/07 02:43:54 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fractol.h"
// #include <stdio.h>

// int mandelbrot(double x, double y)
// {
//     double a;
//     double b;
//     double p;
//     double k;
//     double l;
//     double r;
//     double i;

//     a = ((x - (800 / 2)) / (800 / 4));
//     b = ((y - (800 / 2)) / (800 / 4));
//     k = a;
//     l = b;
//     p = 0.0;
//     while(p < ITR)
//     {
//         r = (a * a) - (b * b);
//         i = 2 * b * a;
//         a = r + k;
//         b = i + l;
//         if((a * a) + (b * b) > 4)
//             break;
//         p++;
//     }
//     return p;
// }
