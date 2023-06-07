/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:17:56 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/07 02:56:26 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot(double x, double y)
{
    double a;
    double b;
    
    double l;
    double k;
    
    double p;
    
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
    return p;
}





// void change_repaire(int x, int y)
// {
//     int         i;
//     int         j;
    
//     i = ((x - (500 / 2)) / (500 / 4));
//     j = ((y - (500 / 2)) / (500 / 4));
//     The_Mandelbrot_Set(i, j);
// }

// void ft_Mandelbrot(void *mlx_ptr, void *win_ptr)
// {
//     int         x;
//     int         y;
//     int         i;
//     int         j;

//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, 500, 500, "the greate window in mlx");

//     while (x < 500)
//     {
//         while (y < 500)
//         {
//            change_repaire(x, y);
//         }
//     }
//     mlx_loop (mlx_ptr);
