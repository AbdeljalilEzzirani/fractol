/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:17:56 by abez-zir          #+#    #+#             */
/*   Updated: 2023/06/05 15:57:18 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int The_Mandelbrot_Set(int i, int j)
{
    
}

void change_repaire(int x, int y)
{
    int         i;
    int         j;
    
    i = ((x - (500 / 2)) / (500 / 4));
    j = ((y - (500 / 2)) / (500 / 4));
    The_Mandelbrot_Set(i, j);
}

void ft_Mandelbrot(void *mlx_ptr, void *win_ptr)
{
    int         x;
    int         y;
    int         i;
    int         j;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "the greate window in mlx");

    while (x < 500)
    {
        while (y < 500)
        {
           change_repaire(x, y);
        }
    }
    mlx_loop (mlx_ptr);
}

int main ()
{
    void    *mlx_ptr;
    void    *win_ptr;

    ft_Mandelbrot(mlx_ptr, win_ptr);
}


// a = 1;
// b = 2;

// c = b * a;
// b++;
// a++;
// if(c > 90000000000000000)
//     break;
// madelbrot(cwf(x), cws(y));